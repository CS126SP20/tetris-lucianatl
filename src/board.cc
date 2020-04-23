//
// Created by Luciana Toledo-Lopez on 4/22/20.
//

#include "board.h"

namespace tetris {
    void Board::FillBoard() {
        for (int i = 0; i < kBoardWidth; i++)
            for (int j = 0; j < kBoardHeight; j++)
                board[i][j] = free;
    }
    // double check
    void Board::StorePiece(int x, int y, int piece, int rotation) {
        // Store each block of the piece into the board
        for (int i_board = x, i_matrix = 0; i_board < x + kPieceMatrixSize; i_board++, i_matrix++) {
            for (int j_board = y, j_matrix = 0; j_board < y + kPieceMatrixSize; j_board++, j_matrix++) {
                // Store only the blocks of the piece that are not holes
                // are the i and j backwards?
                if (pieces.GetBlockType(piece, rotation, j_matrix, i_matrix) != 0) {
                    board_[i_board][j_board] = filled;
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
            for (int i = 0; i < kBoardWidth; i++) {
                board[i][j] = board[i][j-1];
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
        if (board[x][y] == free) {
            return true;
        }
        return false;
    }

}

