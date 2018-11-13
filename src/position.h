#ifndef POSITION_H
#define POSITION_H

#include <stdint.h>
#include <stdbool.h>

struct position {
    uint8_t x, y;
};

typedef struct position Position;

/*
 * Sets x and y for the supplied position
 */
void position_set(Position *pos, uint8_t x, uint8_t y);

/*
 * Parses the users input to determine the position on the board
 * returns true on success
 * returns false on error
 */
bool position_parse(char *input, uint8_t *x, uint8_t *y);

#endif
