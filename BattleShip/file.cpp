//
// Created by Kencha  Vang on 5/3/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "file.h"
#include "get_started.h"


void get_file(std:: string file_name) {
    std::ifstream file(file_name);
    std::vector<std::string> file_content;
    std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(file_content));
    get_started(file_content);

}