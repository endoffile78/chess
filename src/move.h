#ifndef MOVE_H
#define MOVE_H

#include "piece.h"
#include "position.h"

enum MOVE_TYPE {
    MOVE_INVALID,
    MOVE_NORMAL,
    MOVE_CASTLE,
};

typedef enum MOVE_TYPE MOVE_TYPE;

struct move {
    MOVE_TYPE type;
    Piece *piece;
    Position pos;
    char alg_notation[5];
};

typedef struct move Move;

bool move_parse(Move *move, Piece *piece, char *input);

#endif
