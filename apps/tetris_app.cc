// Copyright (c) 2020 Luciana Toledo-Lopez. All rights reserved.

#include "tetris_app.h"

#include <cinder/app/App.h>
#include <mylibrary/board.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/wrapper.h>
//#include "pretzel/PretzelGui.h"
#include "../../../blocks/PretzelGui/src/pretzel/PretzelGui.h"


namespace myapp {
    using namespace tetris;

using cinder::app::KeyEvent;

MyApp::MyApp() {

    Pieces pieces = Pieces();
    Board board = Board(pieces, kScreenHeight);
    game_engine = GameEngine(board, pieces, kScreenHeight);

}

void MyApp::setup() {
    mRadius = 25;
    gui = pretzel::PretzelGui::create("Tetris settings");
    gui->setSize(cinder::vec2(10, 10));
    gui->setPos(cinder::vec2(0,0));

    gui->addSlider("Tetris Size", &mRadius, 2, 1000);

    gui->addSaveLoad();
    gui->loadSettings();

    ci::gl::enableAlphaBlending();

}

void MyApp::update() { }

void MyApp::draw() {
    cinder::gl::clear(cinder::Color(84 / 255., 166. / 255, 1));
    cinder::gl::drawSolidCircle(cinder::vec2(getWindowCenter()), mRadius);

    gui->draw();
}

void MyApp::DrawBoard() const {
    // draw rectangles that limit the board
    // draw already placed blocks

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
}

}  // namespace myapp
