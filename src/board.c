#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "board.h"

#include "piece.h"
#include "player.h"

void board_create(Piece board[BOARD_ROW][BOARD_COL]){
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

bool board_contains_piece(Piece board[BOARD_ROW][BOARD_COL], uint8_t letter, uint8_t number){
    assert(board);
    return board[number][letter].type != NONE;
}

Piece *board_get_piece(Piece board[BOARD_ROW][BOARD_COL], uint8_t letter, uint8_t number){
    assert(board);
    return &board[number][letter];
}

bool board_move_piece(Piece board[BOARD_ROW][BOARD_COL], Piece *piece, uint8_t letter, uint8_t number){
    assert(board);
    assert(piece);
    assert(piece->type != NONE);

    uint8_t previous_letter = piece->pos.y, previous_number = piece->pos.x;

    piece->has_moved = true;
    board[number][letter] = *piece;
    position_set(&board[number][letter].pos, letter, number);

    board[previous_number][previous_letter].type = NONE;

    return true;
}
