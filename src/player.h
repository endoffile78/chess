#ifndef PLAYER_H
#define PLAYER_H

enum PLAYER {
    PLAYER_WHITE,
    PLAYER_BLACK,
};

extern const char *player_names[2];

typedef enum PLAYER PLAYER;

/*
 * returns the oppisite player
 */
PLAYER player_switch(PLAYER current_player);

#endif
