#include "player.h"

PLAYER player_switch(PLAYER current_player){
    if (current_player == PLAYER_WHITE) {
        return PLAYER_BLACK;
    }

    return PLAYER_WHITE;
}
