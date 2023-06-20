//
// Created by Kencha  Vang on 5/10/22.
//
#include "player_setup.h"
#include "board.h"
#include "player.h"
#include "play.h"
#include <map>
#include <iostream>
#include <string>

void player_setup(Board &firing_board1,Board &firing_board2, Board &placement_board1, Board &placement_board2, int row, int column, std::map<std::string , int> ship_information, Player player1, Player player2) {
    player1.set_name("Player 1");
    for (auto i: ship_information) {
        player1.hORv(player1, ship_information, i, row, column);
        char character = i.first[0];
        int len = i.second;
        placement_board1.change_array(player1.getx(), player1.gety(), character, player1, ship_information, i, row,
                                      column, len);
        placement_board1.print_board();
    }

    player2.set_name("Player 2");
    for (auto i: ship_information) {
        player2.hORv(player2, ship_information, i, row, column);
        char character = i.first[0];
        int len = i.second;
        placement_board2.change_array(player2.getx(), player2.gety(), character, player2, ship_information, i, row,
                                      column, len);
        placement_board2.print_board();
    }
    Play play_1;
    Play play_2;
    player1.create_map(ship_information, player1);
    player2.create_map(ship_information, player2);

    while(true) {
        play_1.get_attack(player1, placement_board1, firing_board1);
        play_1.valid_attack(player1, placement_board1, firing_board1, play_1);
        play_1.hit(player1, player2, placement_board1, placement_board2, firing_board1, firing_board2, play_1);
        if (placement_board2.win(placement_board2) == true) {
            std::cout << player1.get_name() << " won the game!";
            exit(0);
        }
        play_2.get_attack(player2, placement_board2, firing_board2);
        play_2.valid_attack(player2, placement_board2, firing_board2, play_2);
        play_2.hit(player2, player1, placement_board2, placement_board1, firing_board2, firing_board1, play_2);
        if (placement_board1.win(placement_board1) == true) {
            std::cout << std::endl;
            std::cout << player2.get_name() << " won the game!";
            exit(0);
        }
    }
}

