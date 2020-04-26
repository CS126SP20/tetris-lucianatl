//
// Created by Luciana Toledo-Lopez on 4/24/20.
//

#ifndef FINALPROJECT_GAMEENGINE_H
#define FINALPROJECT_GAMEENGINE_H

#include <mylibrary/board.h>

namespace tetris {

    int kScreenHeight;

    class GameEngine {
    public:
        /// constructor, sets board peices to instance variables and sets screen height to namespace variable
        GameEngine(Board board, Pieces pieces, int screen_height);

        GameEngine();

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

        Board board;
        Pieces pieces;

    private:
        /// x postion of the next piece
        int next_piece_x;
        ///y position of the next piece
        int next_piece_y;
        /// type of the next piece
        char next_piece_type;
        /// rotation of the next piece
        int next_piece_rotation;

        char piece_type_array[6] = {'i', 'o', 'j', 'l', 'n', 't'};
        


        int GetRandomInt(int min, int max);
        void InitGame();
        void DrawPiece(int x, int y, int piece, int rotation);
        void DrawBoard();
    };

}



#endif //FINALPROJECT_GAMEENGINE_H
