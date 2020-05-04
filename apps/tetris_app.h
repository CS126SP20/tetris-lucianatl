// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <pretzel/PretzelGui.h>

#include "mylibrary/GameEngine.h"


    namespace myapp {

        class MyApp : public cinder::app::App {
        public:

            MyApp();
            /// sets up gui slider, starts timer for falling pieces, initializes game_engine
            void setup() override;

            /// returns if on a static page, otherwise proceeds with game fucntions
            void update() override;

            /// calls the appropriate drawing functions based on game state evaualted by bools is_paused,
            /// is_on_starting page
            void draw() override;
            ///
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

            bool has_printed_game_over_ = false;

            bool is_paused_ = false;

            bool is_on_starting_page_ = true;

            cinder::gl::Texture2dRef tetris_logo_;

        };
        }
    // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
