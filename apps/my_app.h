// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <pretzel/PretzelGui.h>


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
  float mRadius;
  pretzel::PretzelGuiRef gui;

};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
