#include "move.h"
#include "position.h"

#include <string.h>
#include <assert.h>

bool move_parse(Move *move, Piece *piece, char *input){
    assert(move);
    assert(piece);
    assert(input);

    if (strlen(input) < 2 || strlen(input) > 5) {
        move->type = MOVE_INVALID;
        return false;
    }

    if (piece->type == KING && (strcmp(input, "O-O") == 0 || strcmp(input, "O-O-O") == 0)) {
        move->type = MOVE_CASTLE;
        memcpy(move->alg_notation, input, sizeof(move->alg_notation));
        return true;
    }

    if (!position_parse(input, &move->pos)) {
        move->type = MOVE_INVALID;
        return false;
    }

    move->piece = piece;

    return true;
}
