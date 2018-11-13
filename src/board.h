#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

#define BOARD_ROW 8
#define BOARD_COL 8

void board_create(Piece board[BOARD_ROW][BOARD_COL]);

void board_print(Piece board[BOARD_ROW][BOARD_COL]);

bool board_contains_piece(Piece board[BOARD_ROW][BOARD_COL], uint8_t letter, uint8_t number);

Piece *board_get_piece(Piece board[BOARD_ROW][BOARD_COL], uint8_t letter, uint8_t number);

bool board_move_piece(Piece board[BOARD_ROW][BOARD_COL], Piece *piece, uint8_t letter, uint8_t number);

#endif
