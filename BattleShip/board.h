//
// Created by Kencha Vang on 5/3/22.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <vector>
#include <string>
#include "player.h"

class Board {

    public:
        Board();
        void print_board();
        void create_board(int row, int column);
        int get_column();
        int get_row();
        void set_column(int col);
        void set_row(int num);
        void change_array(int row, int column, char character, Player &player, std::map<std::string , int> ship_information, std::pair<const std::string, int> i, int rows, int columns, int len);
        std::vector<std::string> get_array();
        void hit(int row, int column, char character);
        bool win(Board placement);



    private:
        int column;
        int row;
        std::vector<std:: string> array;

    };


#endif //BATTLESHIP_BOARD_H
