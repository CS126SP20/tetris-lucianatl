// Copyright (c) 2020 Luciana Toledo-Lopez. All rights reserved.

#include "tetris_app.h"

#include <cinder/app/App.h>
#include "pretzel/PretzelGui.h"
#include "mylibrary/GameEngine.h"

// from snake project CS 126
#if defined(CINDER_COCOA_TOUCH)
const char kNormalFont[] = "Arial";
const char kBoldFont[] = "Arial-BoldMT";
const char kDifferentFont[] = "AmericanTypewriter";
#elif defined(CINDER_LINUX)
const char kNormalFont[] = "Arial Unicode MS";
const char kBoldFont[] = "Arial Unicode MS";
const char kDifferentFont[] = "Purisa";
#else
const char kNormalFont[] = "Arial";
const char kBoldFont[] = "Arial Bold";
const char kDifferentFont[] = "Papyrus";
#endif



namespace myapp {

    using cinder::app::KeyEvent;
    using cinder::TextBox;
    using cinder::ColorA;
    using std::string;

    MyApp::MyApp() {
    }

    void MyApp::setup() {

        // for setting up the color slider
        color_slider = pretzel::PretzelGui::create("Brightness settings");
        color_slider->setSize(cinder::vec2(10, 10));
        color_slider->setPos(cinder::vec2(400, 0));
        color_slider->addSlider("Tetris color", &color_scalar_, 0.001, 1.0);

        color_slider->addSaveLoad();
        color_slider->loadSettings();
        ci::gl::enableAlphaBlending();

        //initializing the variables
        tetris::Pieces pieces = tetris::Pieces();
        tetris::Board board = tetris::Board(800);
        game_engine = tetris::GameEngine(board);
        tetris_logo_ = cinder::gl::Texture2d::create(
                cinder::loadImage( loadAsset( "tetrisLogo.png" ) ));
        clock_.start();

    }

    void MyApp::update() {
        if (game_engine.board.IsGameOver() || is_paused_ || is_on_starting_page_) {
            return;
        }

        // move vertically, store piece
        if (clock_.getSeconds() >= time_increments_) {
            if (game_engine.board.IsMovementPossible(game_engine.falling_piece_x,
                 game_engine.falling_piece_y + 1, game_engine.falling_piece_type,
                 game_engine.falling_piece_rotation)) {
                game_engine.falling_piece_y++;

                clock_.stop();
                clock_.start();

            } else {
                game_engine.board.StorePiece(game_engine.falling_piece_x,
                     game_engine.falling_piece_y, game_engine.falling_piece_type,
                     game_engine.falling_piece_rotation);

                game_engine.board.DeletePossibleLines();

                game_engine.CreateNewPiece();
            }

        }
    }

    void MyApp::draw() {
        // if on any specific static page, draw it, otherwise draw game board
        if (is_on_starting_page_) {
            cinder::gl::clear(cinder::ColorA(color_scalar_ * (11 / kColorMax),
                    color_scalar_ * (204 / kColorMax), color_scalar_ * (233 / kColorMax), 0.1));
            DrawStart();
            return;
        }
        if (game_engine.board.IsGameOver()) {
            if (!has_printed_game_over_) {
                cinder::gl::clear(cinder::ColorA(11 / kColorMax,
                        204 / kColorMax, 233 / kColorMax, color_scalar_));

            }
            DrawGameOver();
            return;
        }
        if (is_paused_) {
            cinder::gl::clear(cinder::ColorA(0,
                    color_scalar_ * 0.5, color_scalar_ * 0.4, 1));

            DrawPaused();
            return;
        }

        cinder::gl::clear(cinder::ColorA(color_scalar_ * (11 / kColorMax),
                color_scalar_ * (204 / kColorMax), color_scalar_ * (233 / kColorMax), 0.1));

        DrawBoard();

        // draw falling piece
        DrawPiece(game_engine.falling_piece_type, game_engine.falling_piece_rotation,
                  game_engine.board.GetXPosInScreen(game_engine.falling_piece_x),
                  game_engine.board.GetYPosInScreen(game_engine.falling_piece_y));

    }


    void MyApp::DrawBoard() {
        // draw next piece
        DrawPiece(game_engine.next_piece_type, game_engine.next_piece_rotation,
                  game_engine.next_piece_x, game_engine.next_piece_y);


        ci::ColorA color = cinder::ColorA(0.2, 0.2, 0.1, 1);
        cinder::gl::color(color);

        int x_int_left_ = 400 - (tetris::kBlockSize * (tetris::kBoardWidth / 2)) - 1 - tetris::kBlockSize;
        int x_int_right_ = 400 + (tetris::kBlockSize * (tetris::kBoardWidth / 2));
        int board_y_ = game_engine.board.GetScreenHeight() - (tetris::kBlockSize * tetris::kBoardHeight);

        // left border
        cinder::gl::drawSolidRect(cinder::Rectf(x_int_left_, board_y_, x_int_left_ + tetris::kBoardLineWidth,
                                                game_engine.board.GetScreenHeight() - 1));
        // right border
        cinder::gl::drawSolidRect(cinder::Rectf(x_int_right_, board_y_, x_int_right_ + tetris::kBoardLineWidth,
                                                game_engine.board.GetScreenHeight() - 1));

        color = cinder::ColorA(kRed * (1.0 - color_scalar_), kGreen * (1.0 - color_scalar_),
                               kBlue * (1.0 - color_scalar_), 1);
        cinder::gl::color(color);

        // draw existing pieces in board
        x_int_left_ += 1 + tetris::kBlockSize;

        for (int i = 0; i < tetris::kBoardWidth; i++) {
            for (int j = 0; j < tetris::kBoardHeight; j++) {

                // Check if the block is filled, if so, draw it
                if (!game_engine.board.IsFreeBlock(i, j)) {

                    cinder::gl::drawSolidRect(cinder::Rectf(x_int_left_ + i * tetris::kBlockSize,
                            board_y_ + j * tetris::kBlockSize,
                            (x_int_left_ + i * tetris::kBlockSize) + tetris::kBlockSize - 1,
                            (board_y_ + j * tetris::kBlockSize) + tetris::kBlockSize - 1));

                }
            }
        }
        DrawScore();
    }

    // from snake project CS 126
    template<typename C>
    void PrintText(const string &text, const C &color, const cinder::ivec2 &size,
                   const cinder::vec2 &loc) {
        cinder::gl::color(color);

        auto box = TextBox()
                .alignment(TextBox::CENTER)
                .font(cinder::Font(kNormalFont, 30))
                .size(size)
                .color(color)
                .backgroundColor(ColorA(0, 0, 0, 0))
                .text(text);

        const auto box_size = box.getSize();
        const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
        const auto surface = box.render();
        const auto texture = cinder::gl::Texture::create(surface);
        cinder::gl::draw(texture, locp);
    }

    void MyApp::DrawGameOver() {
        if (has_printed_game_over_) return;

        const cinder::vec2 center = getWindowCenter();
        const cinder::ivec2 size = {500, 50};
        const cinder::Color color = cinder::Color::white();

        size_t row = 0;
        PrintText("Game Over :(", color, size, center);
        PrintText("final score: " + std::to_string(game_engine.board.score_),
                  color, size, {center.x, center.y + (++row) * 50});

        has_printed_game_over_ = true;
    }


    void MyApp::DrawPiece(char type, int rotation, int x, int y) {

        // Travel the matrix of blocks of the piece and draw the blocks that are filled
        for (int i = 0; i < tetris::kPieceMatrixSize; i++) {
            for (int j = 0; j < tetris::kPieceMatrixSize; j++) {
                // Get the type of the block and draw it with the correct color

                ci::ColorA color = cinder::ColorA(kRed * (1.0 - color_scalar_), kGreen * (1.0 - color_scalar_),
                                                  kBlue * (1.0 - color_scalar_), 1);
                cinder::gl::color(color);
                if (game_engine.board.pieces.GetBlockType(type,
                                                          rotation, j, i) != 0) {
                    cinder::gl::drawSolidRect(cinder::Rectf(x + i * tetris::kBlockSize,
                        y + j * tetris::kBlockSize,
                        (x + i * tetris::kBlockSize) + tetris::kBlockSize - 1,
                        (y + j * tetris::kBlockSize) + tetris::kBlockSize - 1));
                }
            }
        }
    }

    void MyApp::DrawScore() {

        const cinder::vec2 center = getWindowCenter();
        const cinder::ivec2 size = {500, 50};
        const cinder::Color color = cinder::Color::white();

        PrintText(std::to_string(game_engine.board.score_), color, size, {700, 100});

    }

    void MyApp::DrawPaused() {

        const cinder::vec2 center = getWindowCenter();
        const cinder::ivec2 size = {500, 50};
        const cinder::Color color = cinder::Color::white();

        size_t row = 0;

        PrintText("Game Paused", color, size, center);
        PrintText("down, j, s keys to move down", color, size, {center.x, center.y + (++row) * 50});
        PrintText("up, k, w keys and space bar to rotate", color, size, {center.x, center.y + (++row) * 50});
        PrintText("left, h, a keys to move left", color, size, {center.x, center.y + (++row) * 50});
        PrintText("right, l, d keys to move right", color, size, {center.x, center.y + (++row) * 50});

        color_slider->draw();

    }

    void MyApp::DrawStart() {
        const cinder::vec2 center = getWindowCenter();
        const cinder::ivec2 size = {500, 50};
        const cinder::Color color = cinder::Color::white();

        size_t row = 0;

        cinder::gl::draw( tetris_logo_, {225, 200});
        PrintText("Press enter to begin", color, {size.x - 50 , size.y},
                  {center.x, center.y + (++row) * 50});
        PrintText("by Luciana Toledo-López", color, size, {center.x, center.y + (++row) * 100});
    }

    void MyApp::keyDown(KeyEvent event) {
        switch (event.getCode()) {
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
                is_paused_ = !(is_paused_);
                break;
            }
            case KeyEvent::KEY_r: {
                break;
            }
            case KeyEvent::KEY_RETURN: {
                is_on_starting_page_ = false;
                break;
            }
            case KeyEvent::KEY_k:
            case KeyEvent::KEY_w:
            case KeyEvent::KEY_UP:
            case KeyEvent::KEY_SPACE: {
                if (game_engine.board.IsMovementPossible(game_engine.falling_piece_x, game_engine.falling_piece_y,
                        game_engine.falling_piece_type,
                        (game_engine.falling_piece_rotation + 1) % kNumRotations)) {
                    game_engine.falling_piece_rotation = (game_engine.falling_piece_rotation + 1) % kNumRotations;
                }

                break;
            }
        }
    }


}
// namespace myapp