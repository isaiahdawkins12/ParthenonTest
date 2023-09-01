#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::string, std::ifstream, std::cout, std::cerr, std::endl, std::istringstream, std::getline, std::isdigit, std::vector;

#ifndef PARSER_H
#define PARSER_H

// function to parse lines for crontab commands
vector<vector<int>> parseLine();


#endif

