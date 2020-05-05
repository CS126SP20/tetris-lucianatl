//
// Created by Luciana Toledo-Lopez on 4/22/20.
//

#include "mylibrary/board.h"


namespace tetris {

    Board::Board() {}

    Board::Board(int screen_height) {
        kScreenHeight = screen_height;
        FillBoard();
    }

    int Board::GetScreenHeight() const {
        return kScreenHeight;
    }

    void Board::FillBoard() {
        for (int i = 0; i < kBoardWidth; i++) {
            for (int j = 0; j < kBoardHeight; j++) {
                board[i][j] = free;
            }
        }
    }

    void Board::StorePiece(int x, int y, char piece, int rotation) {
        // Store each block of the piece into the board
        for (int i_board = x, i_matrix = 0; i_board < x + kPieceMatrixSize; i_board++, i_matrix++) {
            for (int j_board = y, j_matrix = 0; j_board < y + kPieceMatrixSize; j_board++, j_matrix++) {

                // Store only the blocks of the piece that are not holes
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
            for (int i = 0; i < kBoardWidth; i++) {
                board[i][j] = board[i][j-1];
            }
        }
    }
    // double check to make sure this works
    void Board::DeletePossibleLines() {
        for (int j = 0; j < kBoardHeight; j++) {
            int row_ = 0;
            for (int i = 0; i < kBoardWidth; i++) {
                if (board[i][j] != filled) {
                    break;
                }
                row_ = i;
            }

            int deleted_counter_ = 0 ;

            if (row_ == kBoardWidth - 1) {
                deleted_counter_++;
                DeleteLine(j);
            }
            // add points
            switch(deleted_counter_) {
                case 0 :
                    break;
                case 1 :
                    score_ += kOneLinePoints;
                    break;
                case 2 :
                    score_ += kTwoLinePoints;
                    break;
                case 3 :
                    score_ += kThreeLinePoints;
                    break;
                case 4 :
                    score_ += kFourLinePoints;
                    break;
                default :
                    score_ += kFourLinePoints;;
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

    int Board::GetXPosInScreen(int x_position) {
        return  ((kBoardMiddle - (kBlockSize * (kBoardWidth / 2))) + (x_position * kBlockSize));
    }

    int Board::GetYPosInScreen (int y_position) {
        return ((kScreenHeight - (kBlockSize * kBoardHeight)) + (y_position * kBlockSize));
    }

}