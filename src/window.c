#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#include "board.h"
#include "piece.h"
#include "window.h"

Window *window_create(char *title, int width, int height, int x, int y){
    Window *win = calloc(1, sizeof(Window));
    if (!win) {
        return NULL;
    }

    win->title = title;
    win->w = newwin(height, width, y, x);
    win->width = width;
    win->height = height;
    win->x = x;
    win->y = y;

    box(win->w, 0, 0);
    wrefresh(win->w);

    return win;
}

void window_draw_tite(Window *win){
    mvwprintw(win->w, 0, 5, win->title);
    wrefresh(win->w);
}

void piece_print(Window *win, Piece piece){
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

    wprintw(win->w, "%c", c);
}

void window_board_draw(Window *win, Piece board[BOARD_ROW][BOARD_COL]){
    assert(board);
    clear();
    window_draw_tite(win);
    mvwprintw(win->w, 1, 1, "    ---------------\n");
    for (int i = 0; i < BOARD_ROW; i++) {
        mvwprintw(win->w, i + 2, 1, "%d | ", i + 1);
        for (int j = 0; j < BOARD_COL; j++) {
            piece_print(win, board[i][j]);
            wprintw(win->w, " ");
        }
        wprintw(win->w, "| \n");
    }
    wprintw(win->w, "    ---------------\n");
    wprintw(win->w, "    a b c d e f g h\n");
}

void window_destroy(Window *win){
    wrefresh(win->w);
    delwin(win->w);
    free(win);
}
