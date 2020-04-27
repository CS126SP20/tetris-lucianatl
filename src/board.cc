//
// Created by Luciana Toledo-Lopez on 4/22/20.
//

#include "mylibrary/board.h"
#include "GameEngine.h"


namespace tetris {

    Board::Board(int screen_height) {
        kScreenHeight = screen_height;
        FillBoard();
    }

    Board::Board() {}

    void Board::FillBoard() {
        for (int i = 0; i < kBoardWidth; i++) {
            for (int j = 0; j < kBoardHeight; j++) {
                board[i][j] = free;
            }
        }
    }

    // double check
    void Board::StorePiece(int x, int y, char piece, int rotation) {
        // Store each block of the piece into the board
        for (int i_board = x, i_matrix = 0; i_board < x + kPieceMatrixSize; i_board++, i_matrix++) {
            for (int j_board = y, j_matrix = 0; j_board < y + kPieceMatrixSize; j_board++, j_matrix++) {
                // Store only the blocks of the piece that are not holes
                // are the i and j backwards?
                if (pieces.GetBlockType(piece, rotation, j_matrix, i_matrix) != 0) {
                    board[i_board][j_board] = filled;
                }

            }
        }
    }

    bool Board::IsGameOver() {
        //check if the first line has blocks
        for (int i = 0; i < kBoardWidth; i++) {
            if (board[i][0] == filled) {
                return true;
            }
        }
        return false;
    }

    void Board::DeleteLine(int y) {
        // Moves all the upper lines one row down
        for (int j = y; j > 0; j--) {
            for (auto & i : board) {
                i[j] = i[j-1];
            }
        }
    }
    // double check to make sure this works
    void Board::DeletePossibleLines() {
        for (int j = 0; j < kBoardHeight; j++) {
            for (int i = 0; i < kBoardWidth; i++) {
                if (board[i][j] != filled) {
                    if (i == kBoardWidth) {
                        DeleteLine(j);
                    }
                    break;
                }
            }
        }
    }

    bool Board::IsFreeBlock (int x, int y) {
        return (board[x][y] == free);
    }

    bool Board::IsMovementPossible(int x, int y, char piece, int rotation) {
        // Checks collision with pieces already stored in the board or the board limits

        int i_matrix = 0;
        for (int i_board = x; i_board < x + kPieceMatrixSize; i_board++) {
            int j_matrix = 0;
            for (int j_board = y; j_board < y + kPieceMatrixSize; j_board++) {

                // Check if the piece is outside the limits of the board
                if (i_board < 0 || i_board > kBoardWidth - 1 || j_board > kBoardHeight - 1) {
                    // if you want to return false
                    if (pieces.GetBlockType(piece, rotation, j_matrix, i_matrix) != 0) {
                    // end game? return 0?
                        return false;
                    }
                }

                // Check if the piece have collided with a block already stored in the array
                if (j_board >= 0) {
                    if ((pieces.GetBlockType(piece, rotation, j_matrix, i_matrix) != 0) &&
                        (!IsFreeBlock(i_board, j_board))) {
                        return false;
                    }
                }
                j_matrix++;
            }
            i_matrix++;
        }
        // No collision
        return true;
    }

    int Board::GetXPosInPixels(int x_position) {
        return  ((kBoardMiddle - (kBlockSize * (kBoardWidth / 2)) ) + (x_position * kBlockSize));
    }

    int Board::GetYPosInPixels (int y_position) {
        return ((kScreenHeight - (kBlockSize * kBoardHeight)) + (y_position * kBlockSize));
    }



}