// Copyright (c) 2020 Luciana Toledo-Lopez. All rights reserved.

#include "mylibrary/pieces.h"

#include <map>
#include <vector>

namespace tetris {
    int Pieces::GetBlockType (char type, int rotation, int x, int y) {
        switch (type) {
            case 'i':
                return i_shape[rotation][x][y];
            case 'o':
                return o_shape[rotation][x][y];
            case 'l':
                return l_shape[rotation][x][y];
            case 'j':
                return j_shape[rotation][x][y];
            case 'n':
                return n_shape[rotation][x][y];
            case 't':
                return t_shape[rotation][x][y];
            case 's':
                return s_shape[rotation][x][y];
            default:
                break;
        }

    }

    int Pieces::GetXInitialPosition(char type, int rotation) {
        switch (type) {
            case 'i':
                return initial_position_i[rotation][0];
            case 'o':
                return initial_position_o[rotation][0];
            case 'l':
                return initial_position_l[rotation][0];
            case 'j':
                return initial_position_j[rotation][0];
            case 'n':
                return initial_position_n[rotation][0];
            case 't':
                return initial_position_t[rotation][0];
            case 's':
                return initial_position_s[rotation][0];
            default:
                break;
        }
    }

    int Pieces::GetYInitialPosition(char type, int rotation)  {
        switch (type) {
            case 'i':
                return initial_position_i[rotation][1];
            case 'o':
                return initial_position_o[rotation][1];
            case 'l':
                return initial_position_l[rotation][1];
            case 'j':
                return initial_position_j[rotation][1];
            case 'n':
                return initial_position_n[rotation][1];
            case 't':
                return initial_position_t[rotation][1];
            case 's':
                return initial_position_s[rotation][1];
            default:
                break;
        }
    }

}  // namespace tetris
