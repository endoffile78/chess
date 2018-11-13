#include <stdio.h>
#include <signal.h>

#include "game.h"

bool quit = false;

void signal_handler(int signal) {
    (void) signal;
    quit = true;
}

int main(void) {
    Game *game = game_create();
    if (!game) {
        printf("Error allocating memory for game.");
        return 1;
    }

    //signal(SIGINT, signal_handler);

    while (game->status != CHECKMATE
           && game->status != STALEMATE
           && !quit) {
        game_loop(game);
    }

    game_end(game);

    return 0;
}
