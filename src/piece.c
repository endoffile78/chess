#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "piece.h"
#include "player.h"
#include "position.h"

void piece_init(Piece *piece, uint8_t type, PLAYER color, int x, int y){
    assert(piece);
    piece->type = type;
    piece->color = color;
    piece->has_moved = false;
    position_set(&piece->pos, x, y);
}

void piece_print(Piece piece){
    char c = '-'; //representation for empty spots
    switch (piece.type) {
        case PAWN:
            c = 'P';
            break;
        case ROOK:
            c = 'R';
            break;
        case KNIGHT:
            c = 'N';
            break;
        case BISHOP:
            c = 'B';
            break;
        case KING:
            c = 'K';
            break;
        case QUEEN:
            c = 'Q';
            break;
        default:
            break;
    }

    if (piece.color == PLAYER_BLACK) {
        c = tolower(c); //distinguish between the owner of the pieces
    }

    printf("%c", c);
}

bool piece_is_color(Piece piece, PLAYER color){
    return piece.color == color;
}

uint8_t piece_convert(char *name){
    if (strcmp(name, "king") == 0) {
        return KING;
    } else if (strcmp(name, "queen") == 0) {
        return QUEEN;
    } else if (strcmp(name, "bishop") == 0) {
        return BISHOP;
    } else if (strcmp(name, "knight") == 0) {
        return KNIGHT;
    } else if (strcmp(name, "rook") == 0) {
        return ROOK;
    } else if (strcmp(name, "pawn") == 0) {
        return PAWN;
    } else {
        return NONE;
    }
}

bool piece_promote(Piece *piece, uint8_t new_type){
    assert(piece);
    assert(piece->type == PAWN);

    if (new_type != QUEEN && new_type != ROOK
        && new_type != KNIGHT && new_type != BISHOP) {
        return false;
    }

    piece->type = new_type;

    return true;
}
