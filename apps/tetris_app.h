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
                /// sets up color_slider slider, starts timer for falling pieces, initializes game_engine
                void setup() override;

                /// returns if on a static page, otherwise proceeds with game fucntions
                void update() override;

                /// calls the appropriate drawing functions based on game state evaualted by bools is_paused,
                /// is_on_starting page
                void draw() override;

                /// moves falling piece according to keys, p is for pausing
                void keyDown(cinder::app::KeyEvent) override;

            private:

                /// draws the score in the upper right hand corner
                void DrawScore();

                /// draws the borders of the game as well as the stored pieces and next piece
                void DrawBoard();

                /// draws a piece according to the matrices in Pieces class
                void DrawPiece(char type, int rotation, int x, int y);

                /// draws a game over screen with final score
                void DrawGameOver();

                /// draws the paused screen, inlcudes directions
                void DrawPaused();

                /// draws the start screen iwth e image in assets folder and credits
                void DrawStart();

                /// slider for changing the color/brightness of the screen
                pretzel::PretzelGuiRef color_slider;

                /// changes the brightness of the screen, changes with the color_slider slider
                float color_scalar_ = 1;

                /// timer that lowers the falling pieces
                cinder::Timer clock_;

                /// ow much time passes between each lower of the falling piece
                double time_increments_ = 0.5;

                /// color of the peices
                const double kRed = 235 / 255.0;
                const double kBlue = 197 / 255.0 ;
                const double kGreen = 223 / 255.0;

                /// the denominator for colors
                const double kColorMax = 255.0;


                /// game engine that will run the whole game
                tetris::GameEngine game_engine;

                /// upper bound for random rotation number
                const int kNumRotations = 4;

                bool has_printed_game_over_ = false;

                bool is_paused_ = false;

                bool is_on_starting_page_ = true;

                /// Tetris++ logo image for the start screen
                cinder::gl::Texture2dRef tetris_logo_;

            };
        }
    // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
