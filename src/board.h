#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

#define BOARD_ROW 8
#define BOARD_COL 8

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
bool board_contains_piece(Piece board[BOARD_ROW][BOARD_COL], uint8_t letter, uint8_t number);

/*
 * Gets the piece at the specified location
 */
Piece *board_get_piece(Piece board[BOARD_ROW][BOARD_COL], uint8_t letter, uint8_t number);

/*
 * Moves a piece on the board
 * returns true on succesful move
 * returns false on illegal move
 */
bool board_move_piece(Piece board[BOARD_ROW][BOARD_COL], Piece *piece, uint8_t letter, uint8_t number);

#endif
