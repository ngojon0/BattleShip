//
// Created by Kencha  Vang on 5/8/22.
//

#include "board.h"
#include <vector>
#include <iostream>
#include "player.h"

Board::Board(){}

void Board::print_board(){
    std::cout << "  ";
    for (int i = 0; i < get_column(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    int rowNum = 0;
    for (auto j : array) {
        std::cout << rowNum << ' ';
        for (const auto& piece : j) {
            std::cout << piece << ' ';
        }
        std::cout << std::endl;
        ++rowNum;
    }
}

void Board::create_board(int row, int column){
     std::vector<std:: string> copy (row, std::string(column, '*'));
     array = copy;
    }

int Board::get_column(){
    return column;
}

int Board::get_row(){
    return row;
}

void Board::set_column(int col) {
    column = col;
}

void Board::set_row(int num) {
    row = num;
}
 void Board::change_array(int row, int column, char character, Player &player, std::map<std::string , int> ship_information, std::pair<const std::string,int> i, int rows, int columns, int len) {

     if (player.gety() + 1 > columns) {
         player.hORv(player, ship_information, i, row, column);
     }
     if (player.getx() + 1 > rows) {
         player.hORv(player, ship_information, i, row, column);
     }

     if (array.at(row).at(column) != '*') {
         player.hORv(player, ship_information, i, row, column);
     }

     if (player.get_way() == "h") {
         for (int i = 0; i < len; i++) {
             array.at(row).at(column+i) = character;
         }
     } else if (player.get_way() == "v") {
         for (int i = 0; i < len; i++) {
             array.at(row +i).at(column) = character;
         }
     } else {
             array.at(row).at(column) = character;
         }
     }

std::vector<std::string> Board::get_array() {
    return array;
}

void Board::hit(int row, int column, char character){
    array.at(row).at(column) = character;
}

bool Board::win(Board placement){
    for(int i = 0; i < placement.get_row(); i++){
        for(int j = 0; j < placement.get_column(); j++){
            if ((array.at(i).at(j) != '*') && (array.at(i).at(j) != 'O') && (array.at(i).at(j) != 'X')) {
                return false;
            }
        }
    }
    return true;
}


// Check Array
// Check map
// check while loop
