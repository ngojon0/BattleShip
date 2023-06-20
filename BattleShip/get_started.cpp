//
// Created by Kencha  Vang on 5/3/22.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include "get_started.h"
#include "board.h"
#include "player.h"
#include "player_setup.h"

void setup_board(Board &firing_board1, Board &firing_board2, Board &placement_board1, Board &placement_board2, int row, int column){
    firing_board1.set_row(row);
    firing_board1.set_column(column);
    firing_board1.create_board(row, column);
    firing_board2.set_row(row);
    firing_board2.set_column(column);
    firing_board2.create_board(row, column);
    placement_board1.set_row(row);
    placement_board1.set_column(column);
    placement_board1.create_board(row, column);
    placement_board2.set_row(row);
    placement_board2.set_column(column);
    placement_board2.create_board(row, column);
}

void get_started(std:: vector<std:: string> contents){
    int row = stoi (contents[0]);
    int column = stoi (contents[1]);
    int amount_ships = stoi(contents[2]);
    std::map<std::string , int> ship_information;
    Player player1;
    Player player2;
    Board firing_board1;
    Board firing_board2;
    Board placement_board1;
    Board placement_board2;

    for (int i = amount_ships; i < contents.size(); i++) {

        ship_information.insert(std::pair<std:: string, int> (contents[i],stoi(contents[i+1])));
        i += 1;
    }

    setup_board(firing_board1, firing_board2, placement_board1, placement_board2, row, column);
    player_setup(firing_board1, firing_board2, placement_board1, placement_board2, row, column, ship_information, player1, player2);


}
