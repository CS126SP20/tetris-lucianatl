//
// Created by Luciana Toledo-Lopez on 4/24/20.
//

#include "mylibrary/GameEngine.h"
#include "mylibrary/board.h"

namespace  tetris {


    GameEngine::GameEngine(Board board) {
        this->board = board;

        // First piece
        falling_piece_type = piece_type_array[GetRandomInt(0, 6)];
        falling_piece_rotation = GetRandomInt(0, 3);
        falling_piece_x = (kBoardWidth / 2) + this->board.pieces.GetXInitialPosition(falling_piece_type, falling_piece_rotation);
        falling_piece_y = this->board.pieces.GetYInitialPosition(falling_piece_type, falling_piece_rotation);

        //  Next piece
        next_piece_type = piece_type_array[GetRandomInt(0, 6)];
        next_piece_rotation = GetRandomInt(0, 3);
        next_piece_x = kBoardWidth + 5;
        next_piece_y = 5;
    }

    int GameEngine::GetRandomInt(int min, int max) {
        return rand () % (max - min + 1) + min;
    }

    void GameEngine::CreateNewPiece() {
        // The new piece
        falling_piece_type = next_piece_type;
        falling_piece_rotation = next_piece_rotation;
        falling_piece_x = (kBoardWidth / 2) + board.pieces.GetXInitialPosition(next_piece_type, next_piece_rotation);
        falling_piece_y = board.pieces.GetYInitialPosition(next_piece_type, next_piece_rotation);

        // Random next piece
        next_piece_type = piece_type_array[GetRandomInt(0, 6)];
        next_piece_rotation = GetRandomInt(0, 3);
    }

    GameEngine::GameEngine() {}

}