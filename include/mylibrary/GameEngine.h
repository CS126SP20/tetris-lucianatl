//
// Created by Luciana Toledo-Lopez on 4/24/20.
//

#ifndef FINALPROJECT_GAMEENGINE_H
#define FINALPROJECT_GAMEENGINE_H

#include "mylibrary/board.h"

namespace tetris {

    class GameEngine {
    public:

        /// constructor, sets board pieces to instance variables and sets screen height to namespace variable
        GameEngine(Board board);

        GameEngine();

        /// moves next pieces variables into falling piece variables and randomly generates a new piece
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

        /// type of the next piece
        char next_piece_type;
        /// rotation of the next piece
        int next_piece_rotation;
        /// x postion of the next piece
        int next_piece_x;
        ///y position of the next piece
        int next_piece_y;
    private:

        // all the possible shape types
        char piece_type_array[7] = {'i', 'o', 'j', 'l', 'n', 't', 's'};

        /// returns a random integer between 0-max
        int GetRandomInt(int max);
    };

}



#endif //FINALPROJECT_GAMEENGINE_H
