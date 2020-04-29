// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <pretzel/PretzelGui.h>

#include "mylibrary/GameEngine.h"


    namespace myapp {
        // used to describe the state of the game
        enum class GameState {
            kPlaying,
            kGameOver,
            kGamePaused
        };

        class MyApp : public cinder::app::App {
        public:
            MyApp();

            void setup() override;

            void update() override;

            void draw() override;

            void keyDown(cinder::app::KeyEvent) override;

        private:
            void DrawFallingPiece() const;

            void DrawBoard();

            void DrawNextPiece() const;

            float mRadius;
            const int tile_size_ = 25;
            pretzel::PretzelGuiRef gui;


            ///new stuff
            // game engine that will run the whole game
            tetris::GameEngine game_engine;

            // upper bound for random rotation number
            int kNumRotations = 4;

            // state of the game
            GameState state_;


        };
        }
    // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
