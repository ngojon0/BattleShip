//
// Created by Kencha  Vang on 5/10/22.
#include "player.h"
#include <iostream>
#include <map>
#include <vector>

void Player::set_name(std::string player){
    std::string replace;
    std::cout << player <<" please enter your name:" << std::endl;
    std::cin >> replace;
    name = replace;
}
std::string Player::get_name() {
    return name;
}

void Player::hORv(Player &player, std::map<std::string, int> ship_information, std::pair<const std::string, int> i,int row, int column){
    std::cout  << player.get_name() << ", do you want to place " << i.first << " horizontally or vertically?" << std::endl;
    std::cout << "Enter h for horizontal or v for vertical\n"
                 "Your choice: "<< std::endl;
    std::string sub;
    std::cin >> sub;
    if ((sub != "h" ) && (sub != "v") && (sub != "H") && (sub != "V")){
        player.hORv(player , ship_information,i, row, column);
    }
    else {
        way = sub;
        player.location(player, ship_information, i, row, column);
    }

}

void Player::location(Player &player1, std::map<std::string, int> ship_information, std::pair<const std::string, int> i, int row, int column){
    std::cout << player1.get_name() << " enter the row and column you want to place "<< i.first;
    std::cout <<", which is "<< i.second  << " long, ";
    std::cout <<"at with a space in between row and col: "<< std::endl;
    std::string sub1;
    std::string sub2;
    std::cin >> sub1 >> sub2;
    if ((sub1.size() != 1) || (sub2.size() != 1)){
        hORv(player1, ship_information, i, row, column);
    }
    char sub3 = sub1[0];
    char sub4 = sub2[0];
    if ((sub3 <47)||( sub4 < 47) || (sub3 >57) || (sub4 > 57)) {
        player1.hORv(player1, ship_information, i, row, column);
    }
    int num1 = sub3 - '0';
    int num2 = sub4 - '0';

    if (((num1 > row) || (num1 < 0)) || ((num2 > column) || (num2 < 0))){
        player1.hORv(player1 , ship_information, i, row, column);
    }
    x = num1;
    y = num2;
}

std::string Player::get_way(){
    return way;
}

int Player::getx() {
    return x;
}

int Player::gety() {
    return y;
}

Player::Player() {

}
std::map<std::string, int> Player::get_map() {
    return boat_info;
}
int Player::change_map(std::string character, Player player){
    auto it = player.get_map();
    auto jt = it.find(character);
    jt ->second = jt-> second - 1;
    return jt->second;

}


void Player::create_map(std::map<std::string, int> map, Player player){
    boat_info = map;
}

