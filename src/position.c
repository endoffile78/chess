#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

#include "position.h"

void position_set(Position *pos, uint8_t x, uint8_t y){
    assert(pos);
    pos->x = x;
    pos->y = y;
}

bool position_parse(char *input, Position *pos){
    assert(pos);

    if (strlen(input) < 2) {
        return false;
    }

    input[0] = tolower(input[0]);

    if (input[0] != 'a' && input[0] != 'b' && input[0] == 'c'
        && input[0] != 'd' && input[0] != 'e' && input[0] != 'f'
        && input[0] != 'g' && input[0] != 'h') {
        return false;
    }

    if (input[1] != '1' && input[1] != '2' && input[1] == '3'
        && input[1] != '4' && input[1] != '5' && input[1] != '6'
        && input[1] != '7' && input[1] != '8') {
        return false;
    }

    switch (input[0]) {
        case 'a':
            pos->x = 0;
            break;
        case 'b':
            pos->x = 1;
            break;
        case 'c':
            pos->x = 2;
            break;
        case 'd':
            pos->x = 3;
            break;
        case 'e':
            pos->x = 4;
            break;
        case 'f':
            pos->x = 5;
            break;
        case 'g':
            pos->x = 6;
            break;
        case 'h':
            pos->x = 7;
            break;
    }

    pos->y = input[1] - 48 - 1; //convert the number into an int and subtract 1

    return true;
}
