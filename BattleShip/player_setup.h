//
// Created by Kencha  Vang on 5/10/22.
//

#ifndef BATTLESHIP_PLAYER_SETUP_H
#define BATTLESHIP_PLAYER_SETUP_H
#include "board.h"
#include "player.h"
#include <map>

void player_setup(Board &firing_board1,Board &firing_board2, Board &placement_board1, Board &placement_board2, int row, int column, std::map<std::string , int> ship_information, Player player1, Player player2);



#endif //BATTLESHIP_PLAYER_SETUP_H
