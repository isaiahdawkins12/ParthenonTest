#include <iostream>
#include <vector>
#include "parser.h"
using std::string, std::ifstream, std::cout, std::cerr, std::endl, std::istringstream, std::getline, std::isdigit, std::vector;

int main(){
	vector<vector<int>> parsedData;
	try {
		parsedData = parseLine();	
	} 
	catch(int error_num) {
		if (error_num == 1)
			cout << "Error: Couldn't read file" << endl;
	}
		
	

	// testing vector data
	for (const vector<int>& inner : parsedData){
		for (int val : inner) {
			cout << val << " ";
		}	
		cout << endl;
	}
	/*	
	unsigned int vecSize = parsedData.size();
	for (unsigned int i = 0; i < vecSize; ++i){
		cout << parsedData[i] << " "; 
	}
	*/	
	return 0;	
}
