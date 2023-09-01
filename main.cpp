#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::string, std::ifstream, std::cout, std::cerr, std::endl, std::istringstream, std::getline, std::isdigit, std::vector;

vector<int> parseLine(){
	// Open file
	vector<int> cronData;	
	int minute, hour, day, month, dayOfWeek;
	ifstream file("cron.txt");
	
	if (!file.is_open()) {
		throw 1;
	}
	
	string line;
	// parses each line, default delimiter '/n' 
	while (getline(file, line)) {
		istringstream seg(line);
		string token;
		string integer;
	
	// breaking each line down further into tokens, delimited by ' '
	// going to convert each of these tokens into integers using std::stoi
	// we only need the first five tokens: minute, hour, day, month, dayOfWeek.		
		for (int i = 0; i < 5; ++i){
			getline(seg, token, ' ');

			// will need to get rid of the chars, loop through each token in search for the integers and concatenate onto string integer
			for (char c: token){
				// if the current char is a 
				if (isdigit(c))
					integer += c;
			}
			// token is fully parsed for integers and now we convert to integer using std::stoi and push_back onto vector cronData to use for comparison against system time
			int integerConverted = stoi(integer);
			cronData.push_back(integerConverted);
		}
	}
	return cronData;
}
int main(){
	try {
		parseLine();	
	} 
	catch(int error_num) {
		if (error_num == 1)
			cout << "Error: Coulnd't read file" << endl;
	}
	return 0;	
}
