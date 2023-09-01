#include "parser.h"

using std::string, std::ifstream, std::cout, std::cerr, std::endl, std::istringstream, std::getline, std::isdigit, std::vector;

vector<vector<int>> parseLine(){
	// Open file
	vector<vector<int>> cronVector;
	vector<int> cronData;	
	ifstream file("cron.txt");
	
	if (!file.is_open()) {
		throw 1;
	}
	
	string line;
	// parses each line, default delimiter '/n' 
	while (getline(file, line)) {
		// skip over lines that are empty space or comments
		if (line.empty() || line[0] == '#')
			continue;

		istringstream seg(line);
		string token;
		string integer;

		// breaking each line down further into tokens, delimited by ' '
		// going to convert each of these tokens into integers using std::stoi
		// we only need the first five tokens: minute, hour, day, month, dayOfWeek
		for (int i = 0; i < 5; ++i){
			getline(seg, token, ' ');
			// will need to get rid of the chars, loop through each token in search for the integers and concatenate onto string integer
			for (char c: token){
				if (isdigit(c))
					integer += c;
			}
			// token is fully parsed for integers and now we convert to integer using std::stoi and push_back onto vector cronData to use for comparison against system time
			if (!integer.empty()) { //checks to make sure that integer string is not empty, else stoi will throw an exception
				int integerConverted = stoi(integer);
				cronData.push_back(integerConverted);
				integer.clear();
			}
		}
		// push back the values stored in a vector of 5 elements into cronVector, a vector of vectors
		cronVector.push_back(cronData);
		// making sure to clear the cronData vector before moving to the next line
		cronData.clear();
	}
	return cronVector;
}

