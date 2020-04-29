// Copyright (c) 2020 Luciana Toledo-Lopez. All rights reserved.

#include "tetris_app.h"

#include <cinder/app/App.h>
//#include <mylibrary/board.h>
#include "pretzel/PretzelGui.h"
#include "mylibrary/GameEngine.h"


namespace myapp {

    using cinder::app::KeyEvent;

    MyApp::MyApp() {
    }

    void MyApp::setup() {
        mRadius = 5;
        gui = pretzel::PretzelGui::create("Tetris settings");
        gui->setSize(cinder::vec2(10, 10));
        gui->setPos(cinder::vec2(0,0));
        gui->addSlider("Tetris Size", &mRadius, 2, 1000);
        gui->addSaveLoad();
        gui->loadSettings();
        ci::gl::enableAlphaBlending();

        ///new stuff
        tetris::Pieces pieces = tetris::Pieces();
        tetris::Board board = tetris::Board(800);
        game_engine = tetris::GameEngine(board);
        state_ = GameState::kPlaying;

        //TODO: start music and clock



    }
    void MyApp::update() { }
    void MyApp::draw() {
        cinder::gl::clear(cinder::Color(84 / 255., 166. / 255, 1));
        cinder::vec2 mx1 = (getWindowCenter());
        cinder::gl::drawSolidCircle(mx1, mRadius);
        cinder::gl::drawSolidRect(cinder::Rectf(tetris::kBoardLineWidth * 40, tetris::kBoardLineWidth * 40,
                tetris::kBoardLineWidth * 40 + tile_size_, tetris::kBoardLineWidth * 40 + tile_size_));
        DrawBoard();
        gui->draw();
    }

    void MyApp::DrawBoard() {
        // TODO: draw rectangles that limit the board, draw already placed blocks
        // board limit rectangle to the left
        cinder::gl::color(.2, .2, .1);

        int x_int_left_ = 400 - (tetris::kBlockSize * (tetris::kBoardWidth / 2)) - 1;
        int x_int_right_ = 400 + (tetris::kBlockSize * (tetris::kBoardWidth / 2));
        int m_y = game_engine.board.GetScreenHeight() - (tetris::kBlockSize * tetris::kBoardHeight);
        // left
        cinder::gl::drawSolidRect(cinder::Rectf(x_int_left_, m_y, x_int_left_ + tetris::kBoardLineWidth,
                game_engine.board.GetScreenHeight() - 1));
        // right
        cinder::gl::drawSolidRect(cinder::Rectf(x_int_right_, m_y, x_int_right_ + tetris::kBoardLineWidth,
                                                game_engine.board.GetScreenHeight() - 1));

        // store peice for testing purposes
        game_engine.board.StorePiece(0, 0, 'j', 1);

        // draw existing pieces in board
        x_int_left_ += 1;
        for (int i = 0; i < tetris::kBoardWidth; i++) {
            for (int j = 0; j < tetris::kBoardHeight; j++) {
                // Check if the block is filled, if so, draw it
                if (!game_engine.board.IsFreeBlock(i, j)) {
                    cinder::gl::drawSolidRect(cinder::Rectf(x_int_left_ + i * tetris::kBlockSize,
                            m_y + j * tetris::kBlockSize,
                            (x_int_left_ + i * tetris::kBlockSize) + tetris::kBlockSize - 1,
                            (m_y + j * tetris::kBlockSize) + tetris::kBlockSize - 1));

                }
            }
        }
    }

    void MyApp::DrawFallingPiece() const {

    }

    void MyApp::DrawNextPiece() const {

    }
    void MyApp::keyDown(KeyEvent event) {
        switch (event.getCode()) {
            case KeyEvent::KEY_UP:
            case KeyEvent::KEY_k:
            case KeyEvent::KEY_w: {
                break;
            }
            case KeyEvent::KEY_DOWN:
            case KeyEvent::KEY_j:
            case KeyEvent::KEY_s: {
                if (game_engine.board.IsMovementPossible(game_engine.falling_piece_x, game_engine.falling_piece_y + 1,
                        game_engine.falling_piece_type, game_engine.falling_piece_rotation)) {
                    game_engine.falling_piece_y++;
                }
                break;
            }
            case KeyEvent::KEY_LEFT:
            case KeyEvent::KEY_h:
            case KeyEvent::KEY_a: {
                if (game_engine.board.IsMovementPossible(game_engine.falling_piece_x - 1, game_engine.falling_piece_y,
                        game_engine.falling_piece_type, game_engine.falling_piece_rotation)) {
                    game_engine.falling_piece_x--;
                }
                break;
            }
            case KeyEvent::KEY_RIGHT:
            case KeyEvent::KEY_l:
            case KeyEvent::KEY_d: {
                if (game_engine.board.IsMovementPossible(game_engine.falling_piece_x + 1, game_engine.falling_piece_y,
                        game_engine.falling_piece_type, game_engine.falling_piece_rotation)) {
                    game_engine.falling_piece_x++;
                }
                break;
            }
            case KeyEvent::KEY_p: {
                break;
            }
            case KeyEvent::KEY_r: {
                break;
            }
            case KeyEvent::KEY_q: {
                break;
            }
            case KeyEvent::KEY_SPACE: {
                if (game_engine.board.IsMovementPossible(game_engine.falling_piece_x, game_engine.falling_piece_y,
                        game_engine.falling_piece_type, (game_engine.falling_piece_rotation + 1) % kNumRotations))
                    game_engine.falling_piece_rotation = (game_engine.falling_piece_rotation + 1) % kNumRotations;
                break;
            }
        }
    }

}  // namespace myapp