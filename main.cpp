#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "funcs.h"

using std::string, std::ifstream, std::cout, std::cerr, std::endl, std::istringstream, std::getline

int parseLine(){
	// Open file
	ifstream file("cron.txt");
	
	if (!file.is_open()) {
		cerr << "Error opening file" << endl;
		return 1;	
	}
	
	string line;
	// parses each line, default delimiter '/n' 
	while (getline(file, line)) {
		istringstream string(line);
		string token;

		// breaking each line down further into tokens, delimited by ' '
		while (getline(string, token, ' ')){
			
		}
			
	}
}
int main(){
	
	
}
