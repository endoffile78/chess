#ifndef PIECE_H
#define PIECE_H

#include <stdint.h>
#include <stdbool.h>

#include "position.h"
#include "player.h"

enum PIECE_TYPE {
    NONE,
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    KING,
    QUEEN,
};

typedef enum PIECE_TYPE PIECE_TYPE;

struct piece {
    PIECE_TYPE type;
    PLAYER color;
    bool has_moved; //used for pawns, kings, and rooks
    Position pos;
};

typedef struct piece Piece;

/*
 * Intitializes a piece
 */
void piece_init(Piece *piece, PIECE_TYPE type, PLAYER color, uint8_t x, uint8_t y);

/*
 * Prints out a piece
 */
void piece_print(Piece piece);

/*
 * Checks if the piece is the same color as the specificed color
 */
bool piece_is_color(Piece piece, PLAYER color);

PIECE_TYPE piece_convert(const char *name);

bool piece_promote(Piece *piece, PIECE_TYPE new_type);

#endif
