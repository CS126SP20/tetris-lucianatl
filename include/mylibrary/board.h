//
// Created by Luciana Toledo-Lopez on 4/22/20.
//

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H
#include "mylibrary/pieces.h"

// code based on http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/

namespace tetris {

    // size of each block
    const int kBlockSize = 32;

    // board width in blocks
    const int kBoardWidth = 10;

    // board height in blocks
    const int kBoardHeight = 20;

    // size of the tetris environment border
    const int kBoardLineWidth = 32;

    // Center position of the board from the left of the screen
    const int kBoardMiddle = 400;

    // size of the block def matrices
    const int kPieceMatrixSize = 5;

    class Board {
        public:
            /// constructors, take in the screen height
            Board(int screen_height);

            Board();

            /// gets the position of a point relative to where the board is on the screen
            int GetXPosInScreen(int x_position);
            int GetYPosInScreen(int y_position);

            /// checks if a certain position in the board is free
            bool IsFreeBlock(int x, int y);

            /// Returns true if the proposed position by parameters is not taken by another block or ot of the board
            bool IsMovementPossible(int x, int y, char piece, int rotation);

            /// Stores the piece given by parameters in the the board matrix at the position given by the parameters
            void StorePiece(int x, int y, char piece, int rotation);

            /// if a line is filled on the board matrix, it makes it free and moves down the lines on top
            void DeletePossibleLines();

            /// Returns true if any spot on the top line is filled
            bool IsGameOver();

            /// getter for screen height
            int GetScreenHeight() const;

            /// pieces object
            Pieces pieces = Pieces();

            /// score of the game, will increase by 40 if one line is deleted at once,
            int score_ = 0;

        private:

            /// for filling board
            enum {
                free,
                filled
            };

            /// Board that contains the pieces
            int board[kBoardWidth][kBoardHeight];

            int kScreenHeight;

            /// fills board with frees
            void FillBoard();

            /// called on by DeletePossibleLines() to delete the lines on the board
            void DeleteLine(int y);

            // points for each lines deleted
            int kOneLinePoints = 40;

            int kTwoLinePoints = 100;

            int kThreeLinePoints = 300;

            int kFourLinePoints = 1200;


    };
}



#endif //FINALPROJECT_BOARD_H
