#include "parser.h"
#include "time.h"

using std::chrono, std::time_t, std::tm, std::localtime;
	
void calcNextExec(const cronJob& job){		
	// get system time and convert to a time_t format
	auto currentTime = chrono::system_clock::now();

	// move from time_t to tm	
	time_t currentTime_t = chrono::system_clock::to_time_t(currentTime);
	tm current_tm = *localtime(&currentTime_t);
	
	// variable to store and manipulate the execution time we are looking for
	auto nextExecutionTime = currentTime;	

	// formula for finding the next run time should be something like:
	// current time % job time increment = time increment until next run
	int minutes = current_tm.tm_min;
	int remainder = minutes % job.minute;
	if (remainder == 0) {
		nextExecutionTime += chrono::minutes(job.minute);
	}
	if (job.minute != 0) {
		nextExecutionTime = chrono::minutes(remainder);
	}
	
	
	
}
