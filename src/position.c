#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#include "position.h"

void position_set(Position *pos, uint8_t x, uint8_t y){
    assert(pos);
    pos->x = x;
    pos->y = y;
}

bool position_parse(char *input, uint8_t *x, uint8_t *y){
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

    assert(x);
    assert(y);

    switch (input[0]) {
        case 'a':
            *x = 0;
            break;
        case 'b':
            *x = 1;
            break;
        case 'c':
            *x = 2;
            break;
        case 'd':
            *x = 3;
            break;
        case 'e':
            *x = 4;
            break;
        case 'f':
            *x = 5;
            break;
        case 'g':
            *x = 6;
            break;
        case 'h':
            *x = 7;
            break;
    }

    *y = input[1] - 48 - 1; //convert the number into an int and subtract 1

    printf("x: %d y: %d\n", *x, *y);

    return true;
}
