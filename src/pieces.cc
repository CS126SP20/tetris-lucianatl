// Copyright (c) 2020 Luciana Toledo-Lopez. All rights reserved.

#include "pieces.h"

#include <map>
#include <vector>

namespace pieces {
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
            default:
                break;
        }
    }

    int Pieces::GetXInitialPosition (int pPiece, int pRotation) {
        return mPiecesInitialPosition [pPiece][pRotation][0];
    }

    int Pieces::GetYInitialPosition (int pPiece, int pRotation)  {
        return mPiecesInitialPosition [pPiece][pRotation][1];
    }

}  // namespace mylibrary
