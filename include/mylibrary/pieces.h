// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#pragma  once
#include <map>
#include <vector>

// source: http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/

namespace tetris {
    using std::vector;


    // vector that represents the I shape tetris block, and all the ways it can turn
    vector<vector<vector<int>>> i_shape =
            {
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 1, 2, 1, 1},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 2, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 1, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {1, 1, 2, 1, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 1, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 2, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0}
                    }
            };

    // vector that represents the square shape tetris block, and all the ways it can turn
    vector<vector<vector<int>>> o_shape =
            {
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 2, 1, 0},
                            {0, 0, 1, 1, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 2, 1, 0},
                            {0, 0, 1, 1, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 2, 1, 0},
                            {0, 0, 1, 1, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 2, 1, 0},
                            {0, 0, 1, 1, 0},
                            {0, 0, 0, 0, 0}
                    }
            };
    // vector that represents the L shape tetris block, and all the ways it can turn
    vector<vector<vector<int>>> l_shape =
            {
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 2, 0, 0},
                            {0, 0, 1, 1, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 1, 2, 1, 0},
                            {0, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 1, 1, 0, 0},
                            {0, 0, 2, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0},
                            {0, 1, 2, 1, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0}
                    }
            };
    // vector that represents the J shape tetris block, and all the ways it can turn
    vector<vector<vector<int>>> j_shape =
            {
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 2, 0, 0},
                            {0, 1, 1, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0},
                            {0, 1, 2, 1, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 1, 1, 0},
                            {0, 0, 2, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 1, 2, 1, 0},
                            {0, 0, 0, 1, 0},
                            {0, 0, 0, 0, 0}
                    }
            };
    // vector that represents the N shape tetris block, and all the ways it can turn
    vector<vector<vector<int>>> n_shape =
            {
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0},
                            {0, 0, 2, 1, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 1, 2, 0, 0},
                            {0, 0, 1, 1, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 1, 2, 0, 0},
                            {0, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 1, 1, 0, 0},
                            {0, 0, 2, 1, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0}
                    }
            };
    // vector that represents the mirrored N  or S shape tetris block, and all the ways it can turn
    vector<vector<vector<int>>> s_shape =
            {
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 2, 1, 0},
                            {0, 0, 0, 1, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 2, 1, 0},
                            {0, 1, 1, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0},
                            {0, 1, 2, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 1, 1, 0},
                            {0, 1, 2, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0}
                    }
            };
    // vector that represents the T shape tetris block, and all the ways it can turn
    vector<vector<vector<int>>> t_shape =
            {
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 2, 1, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 1, 2, 1, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 1, 2, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0}
                    },
                    {
                            {0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 1, 2, 1, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0}
                    }
            };

    // Displacement of the piece to the position where it is first drawn in the board when it is created
    int piece_displacement_matrices[7 /*kind */ ][4 /* r2otation */ ][2 /* position */] =
            {
                    /* Square */
                    {
                            {-2, -3},
                            {-2, -3},
                            {-2, -3},
                            {-2, -3}
                    },
                    /* I */
                    {
                            {-2, -2},
                            {-2, -3},
                            {-2, -2},
                            {-2, -3}
                    },
                    /* L */
                    {
                            {-2, -3},
                            {-2, -3},
                            {-2, -3},
                            {-2, -2}
                    },
                    /* L mirrored */
                    {
                            {-2, -3},
                            {-2, -2},
                            {-2, -3},
                            {-2, -3}
                    },
                    /* N */
                    {
                            {-2, -3},
                            {-2, -3},
                            {-2, -3},
                            {-2, -2}
                    },
                    /* N mirrored */
                    {
                            {-2, -3},
                            {-2, -3},
                            {-2, -3},
                            {-2, -2}
                    },
                    /* T */
                    {
                            {-2, -3},
                            {-2, -3},
                            {-2, -3},
                            {-2, -2}
                    },
            };

    class Pieces {
    public:
        /** Parameters: type: type of piece, rotation: 1-4 a possible rotation
         * x, y: xy pixel postion
         * return: 0 = no-block, 1 = normal block, 2 = pivot block **/
        int GetBlockType  (char type, int rotation, int x, int y);

        /** Parameters: type: piece to draw, rotation: 1-4, a possible rotation
         * return: horizontal displacement of piece, pixel to return the correct position**/
        int GetXInitialPosition (int pPiece, int pRotation);

        /** Parameters: type: piece to draw, rotation: 1-4, a possible rotation
         * return: vertical displacement of piece, pixel to return the correct position**/
        int GetYInitialPosition (int type, int rotation);
    };
}


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
