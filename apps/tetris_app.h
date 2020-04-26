// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <pretzel/PretzelGui.h>
#include "../src/GameEngine.h"


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
    void DrawBoard() const;
    void DrawNextPiece() const;
  float mRadius;
  const int tile_size_ = 25;
  pretzel::PretzelGuiRef gui;
  tetris::GameEngine game_engine;
  int kNumRotations = 4;


};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
