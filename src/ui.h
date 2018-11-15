#ifndef UI_H
#define UI_H

#include "board.h"
#include <ncurses.h>

void ui_init(void);

WINDOW *ui_create_window(int width, int height, int x, int y);

void ui_destroy_window(WINDOW *win);

void ui_resize_handler(int sig);

void ui_destroy(void);

void draw_window(WINDOW* win, int height, int width, char c);

void get_window_dimensions(void);

void ui_draw_board(Piece board[BOARD_ROW][BOARD_COL]);

#endif
