#include <stdlib.h>
#include <assert.h>

#include "board.h"
#include "piece.h"
#include "window.h"

#define MAX_WINDOWS 5

Window wins[MAX_WINDOWS];

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

    return win;
}

void window_board_draw(Piece board[BOARD_ROW][BOARD_COL]){
    assert(board);
    clear();
    printw("    ---------------\n");
    for (int i = 0; i < BOARD_ROW; i++) {
        printw("%d | ", i + 1);
        for (int j = 0; j < BOARD_COL; j++) {
            piece_print(board[i][j]);
            printw(" ");
        }
        printw("| \n");
    }
    printw("    ---------------\n");
    printw("    a b c d e f g h\n");
}

void window_destroy(Window *win){
    wrefresh(win->w);
    delwin(win->w);
    free(win);
}
