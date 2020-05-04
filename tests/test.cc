// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>
#include <mylibrary/GameEngine.h>

#include "mylibrary/pieces.h"


TEST_CASE("GetBlockType test", "[pieces]") {
    tetris::Pieces piece = tetris::Pieces();
    REQUIRE(piece.GetBlockType('i', 0, 0, 0) == 0);
    REQUIRE(piece.GetBlockType('i', 0, 1, 2) == 1);
    REQUIRE(piece.GetBlockType('i', 0, 2, 2) == 2);
}

TEST_CASE("GetInitialPosition test", "[pieces]") {
    tetris::Pieces piece = tetris::Pieces();
    REQUIRE(piece.GetXInitialPosition('i', 1) == -2);
    REQUIRE(piece.GetYInitialPosition('i', 1) == -3);

}

TEST_CASE("GetInitialPosition test", "[GameEngine]") {
    tetris::Board board = tetris::Board(800);
    tetris::GameEngine engine = tetris::GameEngine(board);
    char old_next_type = engine.next_piece_type;
    int old_next_rotation = engine.next_piece_rotation;
    int old_next_x = engine.next_piece_x;
    int old_next_y = engine.next_piece_y;
    engine.CreateNewPiece();
    REQUIRE(engine.falling_piece_type == old_next_type);
    REQUIRE(engine.falling_piece_rotation == old_next_rotation);
    REQUIRE(engine.falling_piece_x == old_next_x);
    REQUIRE(engine.falling_piece_y == old_next_y);

}



TEST_CASE("GetInitialPosition test", "[GameEngine]") {
    tetris::Board board = tetris::Board(800);
    tetris::GameEngine engine = tetris::GameEngine(board);
    char old_next_type = engine.next_piece_type;
    int old_next_rotation = engine.next_piece_rotation;
    int old_next_x = engine.next_piece_x;
    int old_next_y = engine.next_piece_y;
    engine.CreateNewPiece();
    REQUIRE(engine.falling_piece_type == old_next_type);
    REQUIRE(engine.falling_piece_rotation == old_next_rotation);
    REQUIRE(engine.falling_piece_x == old_next_x);
    REQUIRE(engine.falling_piece_y == old_next_y);

}

/**BOARD
* Board(int screen_height);

  Board();

  int GetXPosInPixels(int pPos);
  int GetYPosInPixels(int pPos);
  bool IsFreeBlock(int x, int y);
  // This is just to check the 5x5 blocks of a piece with the appropriate area in the board
  bool IsMovementPossible(int x, int y, char piece, int rotation);
  void StorePiece(int x, int y, char piece, int rotation);
  void DeletePossibleLines();
  bool IsGameOver();
  int GetScreenHeight() const; **/
