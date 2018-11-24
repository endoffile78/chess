#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "board.h"

#include "piece.h"
#include "player.h"

void board_create(Piece board[BOARD_ROW][BOARD_COL]){
    assert(board);
    for (int i = 0; i < BOARD_COL; i++) { //pawns
        piece_init(&board[1][i], PAWN, PLAYER_WHITE, 1, i);
        piece_init(&board[6][i], PAWN, PLAYER_BLACK, 6, i);
    }

    //rooks
    piece_init(&board[0][0], ROOK, PLAYER_WHITE, 0, 0);
    piece_init(&board[0][7], ROOK, PLAYER_WHITE, 0, 7);
    piece_init(&board[7][0], ROOK, PLAYER_BLACK, 7, 0);
    piece_init(&board[7][7], ROOK, PLAYER_BLACK, 7, 7);

    //knights
    piece_init(&board[0][1], KNIGHT, PLAYER_WHITE, 0, 1);
    piece_init(&board[0][6], KNIGHT, PLAYER_WHITE, 0, 6);
    piece_init(&board[7][1], KNIGHT, PLAYER_BLACK, 7, 1);
    piece_init(&board[7][6], KNIGHT, PLAYER_BLACK, 7, 6);

    //bishops
    piece_init(&board[0][2], BISHOP, PLAYER_WHITE, 0, 2);
    piece_init(&board[0][5], BISHOP, PLAYER_WHITE, 0, 5);
    piece_init(&board[7][2], BISHOP, PLAYER_BLACK, 7, 2);
    piece_init(&board[7][5], BISHOP, PLAYER_BLACK, 7, 5);

    //kings
    piece_init(&board[0][3], KING, PLAYER_WHITE, 0, 3);
    piece_init(&board[7][3], KING, PLAYER_BLACK, 7, 3);

    //queens
    piece_init(&board[0][4], QUEEN, PLAYER_WHITE, 0, 4);
    piece_init(&board[7][4], QUEEN, PLAYER_BLACK, 7, 4);
}

void board_print(Piece board[BOARD_ROW][BOARD_COL]){
    assert(board);
    printf("    ---------------\n");
    for (int i = 0; i < BOARD_ROW; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < BOARD_COL; j++) {
            piece_print(board[i][j]);
            printf(" ");
        }
        printf("| \n");
    }
    printf("    ---------------\n");
    printf("    a b c d e f g h\n");
}

bool board_contains_piece(Piece board[BOARD_ROW][BOARD_COL], uint8_t x, uint8_t y){
    assert(board);
    return board[x][y].type != NONE;
}

Piece *board_get_piece(Piece board[BOARD_ROW][BOARD_COL], uint8_t x, uint8_t y){
    assert(board);
    return &board[x][y];
}

Position *board_valid_moves(Piece board[BOARD_ROW][BOARD_COL], Piece piece){
    uint8_t board_row = 0;
    if (piece_is_color(piece, PLAYER_BLACK)) {
        board_row = 7;
    }

    int letter = piece.pos.y, number = piece.pos.x;

    switch (piece.type) {
        case PAWN:
            if (!piece.has_moved) {

            }
            break;
        case ROOK:
            break;
        case KNIGHT:
            break;
        case BISHOP:
            break;
        case KING:
            if (!piece.has_moved) {

            }
            break;
        case QUEEN:
            break;
    }

    return NULL;
}

uint8_t board_move_piece(Piece board[BOARD_ROW][BOARD_COL], Piece *piece, uint8_t x, uint8_t y){
    assert(board);
    assert(piece);
    assert(piece->type != NONE);

    uint8_t previous_x = piece->pos.x, previous_y = piece->pos.y;

    piece->has_moved = true;
    board[x][y] = *piece;
    //TODO: figure out how to get rid of this if possible
    piece = board_get_piece(board, x, y); //update pointer
    position_set(&piece->pos, x, y);

    board[previous_x][previous_y].type = NONE;

    // TODO: find a better place to handle promotion
    if (piece->type == PAWN && (piece->pos.x == 7 || piece->pos.x == 0)) {
        return MOVE_PROMOTION;
    }

    return MOVE_SUCCESS;
}

Piece *board_find_piece(Piece board[BOARD_ROW][BOARD_COL], PLAYER color, PIECE_TYPE type){
    for (int i = 0; i < BOARD_ROW; i++) {
        for (int j = 0; i < BOARD_COL; j++) {
            if (board[i][j].type == type && board[i][j].color == color) {
                return &board[i][j];
            }
        }
    }

    return NULL;
}
