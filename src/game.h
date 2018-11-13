#ifndef GAME_H
#define GAME_H

#include "piece.h"
#include "board.h"
#include "player.h"

enum {
    NORMAL,
    CHECK,
    CHECKMATE,
    STALEMATE,
};

struct game {
    Piece board[BOARD_ROW][BOARD_COL];
    PLAYER player_turn;
    uint8_t status;
};

typedef struct game Game;

Game *game_create(void);

void game_loop(Game *game);

void game_end(Game *game);

#endif
