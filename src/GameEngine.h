//
// Created by Luciana Toledo-Lopez on 4/24/20.
//

#ifndef FINALPROJECT_GAMEENGINE_H
#define FINALPROJECT_GAMEENGINE_H

#include <mylibrary/board.h>

namespace tetris {

    class GameEngine {
    public:
        /// constructor, sets board peices to instance variables and sets screen height to namespace variable
        GameEngine(Board board, Pieces pieces, int screen_height);

        void DrawScene();
        void CreateNewPiece();
        /// x position fo the falling piece
        int falling_piece_x;
        /// y position of the falling piece
        int falling_piece_y;
        /// type of piece that is falling
        char falling_piece_type;
        /// rotation of the piece that is falling
        int falling_piece_rotation;

    private:
        /// x postion of the next piece
        int next_piece_x;
        ///y position of the next piece
        int next_piece_y;
        /// type of the next piece
        char next_piece_type;
        /// rotation of the next piece
        int next_piece_rotation;  // Kind and rotation of the next piece

        Board board;
        Pieces pieces;

        int GetRandom(int a, int b);
        void InitGame();
        void DrawPiece(int x, int y, int piece, int rotation);
        void DrawBoard();
    };

}



#endif //FINALPROJECT_GAMEENGINE_H
