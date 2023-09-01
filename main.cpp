#include <iostream>
#include <vector>
#include "parser.h"
using std::string, std::ifstream, std::cout, std::cerr, std::endl, std::istringstream, std::getline, std::isdigit, std::vector;

int main(){
	vector<cronJob> parsedCronJobs;
	try {
		parsedCronJobs= parseLine();	
	} 
	catch(int error_num) {
		if (error_num == 1)
			cout << "Error: Couldn't read file" << endl;
	}
		
	

	// testing vector data
	for (const cronJob& job : parsedCronJobs){
		cout << " ************************* " << endl;
		cout << "Minute: " << job.minute << endl;
		cout << "Hour: " << job.hour << endl;
		cout << "Day: " << job.day << endl;
		cout << "Month: " << job.month << endl;
		cout << "Day of Week: " << job.dayOfWeek << endl;
		cout << " ************************* " << endl;
	}	
	/*	
	unsigned int vecSize = parsedData.size();
	for (unsigned int i = 0; i < vecSize; ++i){
		cout << parsedData[i] << " "; 
	}
	*/	
	return 0;	
}
