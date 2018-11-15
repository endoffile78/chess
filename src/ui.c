#include <ncurses.h>
#include <assert.h>

#include "ui.h"

void ui_init(void){
    initscr();
    cbreak();
    keypad(stdscr, true);

    start_color();

    refresh();
}

void ui_destroy(void){
    endwin();
}
