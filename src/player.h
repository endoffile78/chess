#ifndef PLAYER_H
#define PLAYER_H

extern const char *player_names[2];

enum PLAYER {
    PLAYER_WHITE,
    PLAYER_BLACK,
};

typedef enum PLAYER PLAYER;

enum PLAYER_TYPE {
    HUMAN,
    COMPUTER,
};

typedef enum PLAYER_TYPE PLAYER_TYPE;

struct player {
    PLAYER_TYPE type;
    PLAYER color;
};

typedef struct player Player;

void player_init(Player *player, PLAYER color, PLAYER_TYPE type);

/*
 * returns the oppisite player
 */
PLAYER player_switch(PLAYER current_player);

#endif
