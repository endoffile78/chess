#include <stdio.h>
#include <signal.h>

#include "game.h"
#include "board.h"
#include "ui.h"
#include "window.h"

#include <ncurses.h>

int main(void) {

    ui_init();

    /*
    signal(SIGWINCH, ui_resize_handler);
    */

    Game *game = game_create();
    if (!game) {
        printf("Error allocating memory for game.");
        return 1;
    }

    int terminal_x, terminal_y, input_size = 0;
    getmaxyx(stdscr, terminal_y, terminal_x);

    Window *board = window_create("Board", terminal_x, terminal_y - input_size, 0, 0);
    Window *input = window_create("Input", terminal_x, input_size, 0, terminal_y - input_size);

    while (true) {
        game_loop(game);
        int c = getch();
        if (c == 'q') {
            break;
        }
    }

    window_destroy(board);
    window_destroy(input);

    game_end(game);

    ui_destroy();

#if 0
    Game *game = game_create();
    if (!game) {
        printf("Error allocating memory for game.");
        return 1;
    }

    //signal(SIGINT, signal_handler);

    while (!quit) {
        board_print(game->board);
        Player *player = game_current_player(game);
        if (player->type == COMPUTER) {
            continue;
        }

        switch (game->status) {
            case NORMAL: {
                Piece *piece;
                Position piece_pos, move_pos;
                uint8_t move_ret;

                do {
                    char input[2];
                    do {
                        printw("Please enter the position of the piece you would like to move: ");
                        scanf("%s", input);
                    } while (!position_parse(&piece_pos, input)
                             || !board_contains_piece(game->board, piece_pos.x, piece_pos.y)
                             || !piece_is_color(game->board[piece_pos.x][piece_pos.y], game->player_turn));

                    piece = board_get_piece(game->board, piece_pos.x, piece_pos.y);

                    char position[5]; //5 to allow for castling
                    do {
                        printw("Please enter the position you would like to move that piece to: ");
                        scanf("%s", position);
                    } while (!position_parse(&move_pos, position));
                } while ((move_ret = board_move_piece(game->board, piece, move_pos.x, move_pos.y)) == MOVE_ILLEGAL);

                char piece_name[10];
                piece = board_get_piece(game->board, move_pos.x, move_pos.y); //update pointer

                switch (move_ret) {
                    case MOVE_SUCCESS: {
                        printw("Move succesful\n");
                        break;
                    }
                    case MOVE_PROMOTION: {
                        PIECE_TYPE type = NONE;
                        do {
                            printw("What would you like to promote your pawn to (queen, rook, bishop, knight): \n");
                            scanf("%s", piece_name);
                            type = piece_convert(piece_name);
                        } while (!piece_promote(piece, type));
                        break;
                    }
                }
                break;
            }
            case CHECK: {
                Piece *piece = board_find_piece(game->board, game->player_turn, KING);
                if (!piece) {
                    printw("King could not be found, this should never happen.");
                    break;
                }

                char input[2];
                Position pos;
                do {
                    printw("Where would you like to move your king to: \n");
                    scanf("%s", input);
                } while(!position_parse(&pos, input));
                board_move_piece(game->board, piece, pos.x, pos.y);
                break;
            }
            case STALEMATE:
            case CHECKMATE:
                quit = true;
                break;
        }
    }

    printw("The game is over.\n");

    game_end(game);
#endif
    return 0;
}
