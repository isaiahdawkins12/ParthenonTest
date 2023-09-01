#include "parser.h"

using std::string, std::ifstream, std::cout, std::cerr, std::endl, std::istringstream, std::getline, std::isdigit, std::vector;


vector<cronJob> parseLine(){
	// Open file
	vector<cronJob> cronJobsVector;	
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
		
		cronJob job;
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
			if (!integer.empty()) {
				int integerConverted = stoi(integer);
				if (i == 0) {
					job.minute = integerConverted;	
				} else if (i == 1) {
					job.hour = integerConverted;
				} else if (i == 2) {
					job.day = integerConverted;
				} else if (i == 3) {
					job.month = integerConverted;
				} else if (i == 4) {
					job.dayOfWeek = integerConverted;
				}
				integer.clear();

			} else if (integer.empty()) {
				if (i == 0) {
					job.minute = 0;
				} else if (i == 1) {
					job.hour = 0;
				} else if (i == 2) {
					job.day = 0;
				} else if (i == 3) {
					job.month = 0;
				} else if (i == 4) {
					job.dayOfWeek = 0;
				}
				integer.clear();
			}
		}
		cronJobsVector.push_back(job);
	}
	return cronJobsVector;
}

