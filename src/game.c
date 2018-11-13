#include <stdio.h>
#include <stdlib.h>

#include "game.h"

#include "player.h"
#include "position.h"

Game *game_create(void){
    Game *game = calloc(1, sizeof(Game));
    if (!game) {
        return NULL;
    }

    board_create(game->board);
    game->player_turn = PLAYER_WHITE; //white always goes first
    game->status = NORMAL;

    return game;
}

void game_loop(Game *game){
    board_print(game->board);
    printf("It is player %d turn.\n", game->player_turn + 1);

    Piece *piece = NULL;
    uint8_t pos_letter = 0, pos_num = 0;

    do {
        uint8_t piece_letter, piece_num;
        char piece_pos[2];
        do {
            printf("Please enter the position of the piece you would like to move: ");
            scanf("%s", piece_pos);
        } while (!position_parse(piece_pos, &piece_letter, &piece_num)
                 || !board_contains_piece(game->board, piece_letter, piece_num)
                 || !piece_is_color(game->board[piece_letter][piece_num], game->player_turn));

        piece = board_get_piece(game->board, piece_letter, piece_num);

        char position[2];
        do {
            printf("Please enter the position you would like to move that piece to: ");
            scanf("%s", position);
        } while (!position_parse(position, &pos_letter, &pos_num));
    } while (!board_move_piece(game->board, piece, pos_letter, pos_num));

    game->player_turn = player_switch(game->player_turn);
}

void game_end(Game *game){
    free(game);
}
