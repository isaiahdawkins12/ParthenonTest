#include <iostream>
#include <vector>
#include "parser.h"
using std::cout, std::endl, std::vector;

int main(){
	vector<cronJob> parsedCronJobs;
	try {
		parsedCronJobs= parseLine();	
	} 
	catch(int error_num) {
		if (error_num == 1)
			cout << "Error: Couldn't read file" << endl;
	}

	printCronJobs(parsedCronJobs);	
	return 0;	
}
