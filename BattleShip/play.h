//
// Created by Kencha  Vang on 5/10/22.
//

#ifndef BATTLESHIP_PLAY_H
#define BATTLESHIP_PLAY_H

#include "player.h"
#include "board.h"

class Play {

public:
    void get_attack(Player &player, Board place, Board fire);
    void valid_attack(Player &player, Board place, Board fire, Play &play_1);
    void hit(Player &player, Player &player2, Board &place1, Board &place2, Board &fire1, Board &fire2, Play &play_1);
    int get_x();
    int get_y();
    char get_boat();
    std::string get_boat_string();

private:
    int x;
    int y;
    char boat;
    std::string boat_string;

};

#endif //BATTLESHIP_PLAY_H
