//
// Created by Kencha Vang on 5/10/22.
//

#include "play.h"
#include "player.h"
#include "board.h"
#include <iostream>

void Play::hit(Player &player, Player &player2, Board &place1, Board &place2, Board &fire1, Board &fire2, Play &play_1){
    //checks the location of player2 placement
    if ((place2.get_array().at(play_1.get_x()).at(play_1.get_y()) != '*' ) && (place2.get_array().at(play_1.get_x()).at(play_1.get_y()) != 'X') && (place2.get_array().at(play_1.get_x()).at(play_1.get_y()) != 'O')){
        //hits
        boat = place2.get_array().at(play_1.get_x()).at(play_1.get_y());
        boat_string =  place2.get_array().at(play_1.get_x()).at(play_1.get_y());
        fire1.hit(play_1.get_x(),play_1.get_y(), 'X');
        place2.hit(play_1.get_x(),play_1.get_y(), 'X');
        fire1.print_board();
        place1.print_board();
        std::cout << player.get_name() << " hits "<< player2.get_name() <<"'s "<< boat << "!"<< std::endl;
        int value = player2.change_map(play_1.get_boat_string(), player2);
        if (value == 0){
            std::cout << player.get_name() << " destroyed " << player2.get_name() << "'s " << play_1.get_boat() << "!"<< std::endl;
        }
    }
    else {
        //no change_array of player1 firing with O at location
        boat = place2.get_array().at(play_1.get_x()).at(play_1.get_y());
        fire1.hit(play_1.get_x(),play_1.get_y(), 'O');
        place2.hit(play_1.get_x(),play_1.get_y(), 'O');
        fire1.print_board();
        place1.print_board();
        std::cout << "Missed." << std::endl;
    }

}


void Play::valid_attack(Player &player, Board place, Board fire, Play &play_1){
    //input validation if the coordinates are in the array
    //if not
    //play_1.get_attack(player, place, fire);
    //else
}

void Play::get_attack(Player &player, Board place, Board fire) {

    int num1;
    int num2;

    fire.print_board();
    std::cout << player.get_name() << "'s Firing Board" << std::endl;
    place.print_board();
    std::cout <<player.get_name() << "'s Placement Board" << std::endl;
    std::cout << player.get_name() << ", where would you like to fire?"<< std::endl <<"Enter your attack coordinate in the form row col:" << std::endl;
    std::cin >> num1 >> num2;
    x = num1;
    y = num2;

}

int Play::get_x() {
    return x;
}

int Play::get_y() {
    return y;
}

char Play::get_boat() {
    return boat;
}
std::string Play::get_boat_string() {
    return boat_string;
}