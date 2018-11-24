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
void piece_init(Piece *piece, uint8_t type, PLAYER color, uint8_t x, uint8_t y);

/*
 * Prints out a piece
 */
void piece_print(Piece piece);

/*
 * Checks if the piece is the same color as the specificed color
 */
bool piece_is_color(Piece piece, PLAYER color);

uint8_t piece_convert(const char *name);

bool piece_promote(Piece *piece, uint8_t new_type);

#endif
