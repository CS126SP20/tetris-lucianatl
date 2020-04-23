//
// Created by Luciana Toledo-Lopez on 4/22/20.
//

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H

namespace tetris {
    class board {
    public:
        Board(Pieces pieces, int screen_height);
        int GetXPosInPixels(int pPos);
        int GetYPosInPixels(int pPos);
        bool IsFreeBlock(int x, int y);
        bool IsPossibleMovement(int pX, int pY, int pPiece, int pRotation);
        void Board::StorePiece (int x, int y, int piece, int rotation);
        void DeletePossibleLines();
        bool IsGameOver();

    private:
        enum {
            free,
            filled
        };

        int board[kBoardWidth][kBoardHeight]; // Board that contains the pieces
        // board
        Pieces pieces = Pieces();

        int mScreenHeight;

        /** fills board with frees**/
        void FillBoard();

        void DeleteLine (int y);

        // size of the tetris enviroment border
        int kBoardLineWidth = 6;
        int kBlockSize = 16;
        // Center position of the board from the left of the screen
        int kBoardPosition = 320;
        // board width in blocks
        int kBoardWidth = 10;
        // board height in blocks
        int kBoardHeight = 20;
        // Minimum vertical margin for the board limit
        int kMinVerticalMargin = 20;
        // Minimum horizontal margin for the board limit
        int kMinHorizontalMargin = 20;
        // size of the block def matrices
        int kPieceMatrixSize = 5;

    };
}



#endif //FINALPROJECT_BOARD_H
