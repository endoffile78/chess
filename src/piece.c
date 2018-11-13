#include <stdio.h>
#include <ctype.h>

#include "piece.h"
#include "player.h"
#include "position.h"

void piece_init(Piece *piece, uint8_t type, PLAYER color, int x, int y){
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

void piece_valid_moves(Piece piece){
    switch (piece.type) {
        case PAWN:
            break;
        case ROOK:
            break;
        case KNIGHT:
            break;
        case BISHOP:
            break;
        case KING:
            break;
        case QUEEN:
            break;
    }
}
