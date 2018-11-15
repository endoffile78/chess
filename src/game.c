#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ncurses.h>

#include "game.h"

#include "player.h"
#include "position.h"
#include "window.h"

Game *game_create(void){
    Game *game = calloc(1, sizeof(Game));
    if (!game) {
        return NULL;
    }

    board_create(game->board);
    player_init(&game->players[0], PLAYER_WHITE, HUMAN);
    player_init(&game->players[1], PLAYER_BLACK, HUMAN);
    game->player_turn = PLAYER_WHITE; //white always goes first
    game->status = NORMAL;

    return game;
}

#if 0
void game_loop(Game *game){
    assert(game);

    board_print(game->board);

    window_board_draw(game->board);
    refresh();

    printw("It is %s's turn.\n", player_names[game->player_turn]);

    Player player = game->players[game->player_turn];
    if (player.type == COMPUTER) {
        return;
    }

    Piece *piece = NULL;
    Position piece_pos, move_pos;
    uint8_t move_ret = 0;

    do {
        char input[2];
        do {
            printw("Please enter the position of the piece you would like to move: ");
            scanf("%s", piece_pos);
        } while (!position_parse(piece_pos, &piece_letter, &piece_num)
                 || !board_contains_piece(game->board, piece_letter, piece_num)
                 || !piece_is_color(game->board[piece_num][piece_letter], game->player_turn));

        piece = board_get_piece(game->board, piece_pos.x, piece_pos.y);

        char position[5]; //5 to allow for castling
        do {
            printw("Please enter the position you would like to move that piece to: ");
            scanf("%s", position);
        } while (!position_parse(&move_pos, position));
    } while ((move_ret = board_move_piece(game->board, piece, move_pos.x, move_pos.y)) == MOVE_ILLEGAL);

    char piece_name[10];
    PIECE_TYPE type = NONE;
    piece = board_get_piece(game->board, move_pos.x, move_pos.y);

    switch (move_ret) {
        case MOVE_SUCCESS:
            printw("Move succesful\n");
            break;
        case MOVE_PROMOTION:
            do {
                printw("What would you like to promote your pawn to (queen, rook, bishop, knight): \n");
                scanf("%s", piece_name);
                type = piece_convert(piece_name);
            } while (!piece_promote(piece, type));
            break;
    }

    game->player_turn = player_switch(game->player_turn);
}
#endif

void game_loop(Game *game){
    assert(game);

    game->player_turn = player_switch(game->player_turn);
}

Player *game_current_player(Game *game){
    return &game->players[game->player_turn];
}

void game_end(Game *game){
    free(game);
}
