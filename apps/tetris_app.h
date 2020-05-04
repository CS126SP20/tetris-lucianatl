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

            void DrawScore();

            void DrawBoard();

            void DrawPiece(char type, int rotation, int x, int y);

            void DrawGameOver();

            void DrawPaused();

            void DrawStart();

            float mRadius = 1;
            const int tile_size_ = 25;
            pretzel::PretzelGuiRef gui;

            cinder::Timer clock_;

            double time_increments_ = 0.5;


            double red = 235/ 255.0;
            double blue = 197 / 255.0 ;
            double green = 223 / 255.0;

            ///new stuff
            // game engine that will run the whole game
            tetris::GameEngine game_engine;

            // upper bound for random rotation number
            int kNumRotations = 4;

            // state of the game
            GameState state_;

            bool has_printed_game_over_ = false;

            bool is_paused_ = false;

            bool is_on_starting_page_ = true;

            cinder::gl::Texture2dRef tetris_logo_;

        };
        }
    // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
