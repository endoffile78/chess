#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

#define BOARD_ROW 8
#define BOARD_COL 8

enum {
    MOVE_ILLEGAL,
    MOVE_SUCCESS,
    MOVE_PROMOTION,
};

/*
 * Initializes the board to a standard chess board
 */
void board_create(Piece board[BOARD_ROW][BOARD_COL]);

/*
 * Prints out the board
 */
void board_print(Piece board[BOARD_ROW][BOARD_COL]);

/*
 * Checks if there is a piece at the specified location
 */
bool board_contains_piece(Piece board[BOARD_ROW][BOARD_COL], uint8_t x, uint8_t y);

/*
 * Gets the piece at the specified location
 */
Piece *board_get_piece(Piece board[BOARD_ROW][BOARD_COL], uint8_t x, uint8_t y);

/*
 * Moves a piece on the board
 * returns MOVE_ILLEGAL on an illegal move
 * returns MOVE_SUCCESS on a succesful move
 * returns MOVE_PROMOTION on a move that results in a promotion
 */
uint8_t board_move_piece(Piece board[BOARD_ROW][BOARD_COL], Piece *piece, uint8_t x, uint8_t y);

#endif
