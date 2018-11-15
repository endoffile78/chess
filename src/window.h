#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

#include "board.h"

#define BOARD_WIDTH 40
#define BOARD_HEIGHT 40

#define MOVES_WIDTH 20
#define MOVES_HEIGHT 30

struct window {
    WINDOW *w;
    char *title;
    int width, height;
    int x, y;
};

typedef struct window Window;

Window *window_create(char *title, int width, int height, int x, int y);

void window_board_draw(Window *win, Piece board[BOARD_ROW][BOARD_COL]);

void window_destroy(Window *win);

#endif
