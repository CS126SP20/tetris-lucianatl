//
// Created by Luciana Toledo-Lopez on 4/24/20.
//

#include "GameEngine.h"
#include "mylibrary/board.h"

namespace  tetris {


    GameEngine::GameEngine(Board board, Pieces pieces, int screen_height) {
        this->board = board;
        this->pieces = pieces;
        kScreenHeight = screen_height;


        // Init random numbers
        srand ((unsigned int) time(NULL));

        // First piece
        falling_piece_type = piece_type_array[GetRandomInt(0, 6)];
        falling_piece_rotation = GetRandomInt(0, 3);
        falling_piece_x = (kBoardWidth / 2) + pieces.GetXInitialPosition(falling_piece_type, falling_piece_rotation);
        falling_piece_y = pieces.GetYInitialPosition(falling_piece_type, falling_piece_rotation);

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
        falling_piece_x = (kBoardWidth / 2) + pieces.GetXInitialPosition(next_piece_type, next_piece_rotation);
        falling_piece_y = pieces.GetYInitialPosition(next_piece_type, next_piece_rotation);

        // Random next piece
        next_piece_type = piece_type_array[GetRandomInt(0, 6)];
        next_piece_rotation = GetRandomInt(0, 3);
    }

}