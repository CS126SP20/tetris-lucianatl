//
// Created by Luciana Toledo-Lopez on 4/24/20.
//

#ifndef FINALPROJECT_GAMEENGINE_H
#define FINALPROJECT_GAMEENGINE_H

#include <mylibrary/board.h>

namespace tetris {

    class GameEngine {
    public:


        GameEngine(Board *pBoard, Pieces *pPieces, int pScreenHeight);

        void DrawScene ();
        void CreateNewPiece ();
        /// x position fo the falling piece
        int falling_piece_x;
        /// y position of the falling piece
        int falling_piece_y;
        /// type of piece that is falling
        char falling_piece_type;
        /// rotation of the piece that is falling
        int falling_piece_rotation;

    private:
        int mNextPosX, mNextPosY;       // Position of the next piece
        int mNextPiece, mNextRotation;  // Kind and rotation of the next piece

        Board *mBoard;
        Pieces *mPieces;

        int GetRand (int pA, int pB);
        void InitGame();
        void DrawPiece (int pX, int pY, int pPiece, int pRotation);
        void DrawBoard ();
    };

}



#endif //FINALPROJECT_GAMEENGINE_H
