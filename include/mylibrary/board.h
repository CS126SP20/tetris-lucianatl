//
// Created by Luciana Toledo-Lopez on 4/22/20.
//

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H
#include "mylibrary/pieces.h"

namespace tetris {

    static int kScreenHeight;
    static const int kBlockSize = 16;

    class Board {
    public:
        Board(Pieces pieces, int screen_height);
        int GetXPosInPixels(int pPos);
        int GetYPosInPixels(int pPos);
        bool IsFreeBlock(int x, int y);
        // This is just to check the 5x5 blocks of a piece with the appropriate area in the board
        bool IsMovementPossible(int x, int y, char piece, int rotation);
        void StorePiece(int x, int y, char piece, int rotation);
        void DeletePossibleLines();
        bool IsGameOver();

    private:
        enum {
            free,
            filled
        };

        // size of the tetris environment border
        const int kBoardLineWidth = 6;
        // Center position of the board from the left of the screen
        const int kBoardMiddle = 320;
        // board width in blocks
        static const int kBoardWidth = 10;
        // board height in blocks
        static const int kBoardHeight = 20;
        // Minimum vertical margin for the board limit
        const int kMinVerticalMargin = 20;
        // Minimum horizontal margin for the board limit
        const int kMinHorizontalMargin = 20;
        // size of the block def matrices
        const int kPieceMatrixSize = 5;

        int board[kBoardWidth][kBoardHeight]; // Board that contains the pieces
        // board
        Pieces pieces = Pieces();



        /** fills board with frees**/
        void FillBoard();

        void DeleteLine (int y);



    };
}



#endif //FINALPROJECT_BOARD_H
