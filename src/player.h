#ifndef PLAYER_H
#define PLAYER_H

enum PLAYER {
    PLAYER_WHITE,
    PLAYER_BLACK,
};

typedef enum PLAYER PLAYER;

PLAYER player_switch(PLAYER current_player);

#endif
