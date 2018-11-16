#include <assert.h>

#include "player.h"

const char *player_names[2] = {
    "white",
    "black"
};

void player_init(Player *player, PLAYER color, PLAYER_TYPE type){
    assert(player);
    player->type = type;
    player->color = color;
}

PLAYER player_switch(PLAYER current_player){
    if (current_player == PLAYER_WHITE) {
        return PLAYER_BLACK;
    }

    return PLAYER_WHITE;
}
