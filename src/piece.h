#ifndef PIECE_H
#define PIECE_H

#include <stdint.h>
#include <stdbool.h>

#include "position.h"
#include "player.h"

enum {
    NONE,
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    KING,
    QUEEN,
};

struct piece {
    uint8_t type;
    PLAYER color;
    bool has_moved; //used for pawns, kings, and rooks
    Position pos;
};

typedef struct piece Piece;

/*
 * Intitializes a piece
 */
void piece_init(Piece *piece, uint8_t type, PLAYER owner, int x, int y);

/*
 * Prints out a piece
 */
void piece_print(Piece piece);

bool piece_is_color(Piece piece, PLAYER color);

void piece_valid_moves(Piece piece);

#endif
