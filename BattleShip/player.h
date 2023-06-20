//
// Created by Kencha  Vang on 5/8/22.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H
#include <map>
#include <vector>
#include <string>


class Player {

    public:
        Player();

        std::string get_name();
        void set_name(std::string player);
        void hORv(Player &player, std::map<std::string, int> ship_information, std::pair<const std::string, int> i, int row, int column);
        void location(Player &player, std::map<std::string, int> ship_information, std::pair<const std::string, int> i,
                      int row, int column);
        std::string get_way();
        int getx();
        int gety();
        std::map<std::string, int> get_map();
        int change_map(std::string character, Player player);
        void create_map(std::map<std::string, int> map, Player player);


    private:
        std::string name;
        int x;
        int y;
        std::string way;
        std::map<std::string, int> boat_info;

    };

#endif //BATTLESHIP_PLAYER_H
