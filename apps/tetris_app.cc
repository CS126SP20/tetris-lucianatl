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
        mRadius = 25;
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
        game_engine = tetris::GameEngine(board, 800);
        state_ = GameState::kPlaying;



    }
    void MyApp::update() { }
    void MyApp::draw() {
        cinder::gl::clear(cinder::Color(84 / 255., 166. / 255, 1));
        cinder::gl::drawSolidCircle(cinder::vec2(getWindowCenter()), mRadius);
        gui->draw();
    }

    void MyApp::DrawBoard() const {

    }

    void MyApp::DrawFallingPiece() const {

    }

    void MyApp::DrawNextPiece() const {

    }
    void MyApp::keyDown(KeyEvent event) {

    }

}  // namespace myapp