#include "parser.h"
#include "time.h"

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
		for (int i = 0; i < 6; ++i){
			
			// getline(seg, token, ' ');
			seg >> token;
			// will need to get rid of the chars, loop through each token in search for the integers and concatenate onto string integer
			bool wildcard = false; 
			for (char c: token){
				if (c == '*'){
					wildcard = true;	
				}
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
			} else if (integer.empty()) { // else if integer was empty, set the field to 1, because it means thatits wildcard??
				if (i == 0) {
					job.minute = 1;
				} else if (i == 1) {
					job.hour = 1;
				} else if (i == 2) {
					job.day = 1;
				} else if (i == 3) {
					job.month = 1;
				} else if (i == 4) {
					job.dayOfWeek = 1;
				}
			
			integer.clear();
			}
			// if an '*' was found, we want to set the isEvery___ flag true for so that we can make the proper calculation for displaying the next runtime
			if (wildcard == true){
				if (i == 0){
					job.isEveryMinute = true;
				}else if (i == 1){
					job.isEveryHour = true;
				}else if (i == 2){
					job.isEveryDay = true;
				}else if (i == 3){
					job.isEveryMonth = true;
				}else if (i == 4){
					job.isEveryDayOfWeek = true;
				}
			}
		}
	
		getline(seg, job.command);
		cronJobsVector.push_back(job);
	}
	return cronJobsVector;
}

void printCronJobs(const vector<cronJob>& cronJobsVec){
	for (const cronJob& job : cronJobsVec){
		cout << "Minute: " << job.minute << endl;
		cout << "Hour: " << job.hour << endl;
		cout << "Day: " << job.day << endl;
		cout << "Month: " << job.month << endl;
		cout << "Day of Week: " << job.dayOfWeek << endl;
		cout << "Command: " << job.command << endl;
		calcNextExec(job);
		cout << " ****************************** " << endl;		
	}
	return;
}

