#include "parser.h"
#include "time.h"

using std::std::chrono, std::time_t, std::tm, std::localtime, std::ctime;
	
void calcNextExec(const cronJob& job){		
	// get system time and convert to a time_t format
	auto currentTime = std::chrono::system_clock::now();

	// move from time_t to tm	
	time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	tm current_tm = *localtime(&currentTime_t);
	
	// variable to store and manipulate the execution time we are looking for
	auto nextExecutionTime = currentTime;	

	// formula for finding the next run time should be something like:
	// current time % job time increment = time increment until next run
	int minutes = current_tm.tm_min;
	int remainder = minutes % job.minute;
	if (remainder == 0) {
		nextExecutionTime += std::chrono::minutes(job.minute);
	}
	if (job.minute != 0) {
		nextExecutionTime = std::chrono::minutes(remainder);
	}
	
	int hours = current_tm.tm_hour;
	remainder = hours % job.hour;
	if (remainder == 0) {
		nextExecutionTime += std::chrono::hours(job.hours);
	}
	if (job.minute != 0) {
		nextExecutionTime = std::chrono::hours(remainder);
	}

	int day = current_tm.tm_mday;
	remainder = days % job.day;
	if (remainder == 0) {
		nextExecutionTime += std::chrono::day(job.day);
	}
	if (job.minute != 0) {
		nextExecutionTime = std::chrono::day(remainder);
	}	

	int month = current_tm.tm_mon;
	remainder = month % job.month;
	if (remainder == 0) {
		nextExecutionTime += std::chrono::month(job.month);
	}
	if (job.minute != 0) {
		nextExecutionTime = std::chrono::month(remainder);
	}
	
	int weekDay = current_tm.tm_wday;
	remainder = weekday % job.dayOfWeek;
	if (remainder == 0) {
		nextExecutionTime += std::chrono::weekday(job.dayOfWeek);
	}
	if (job.minute != 0) {
		nextExecutionTime = std::chrono::weekday(remainder);
	}

	time_t nextExecutionTime_t = std::chrono::system_clock::to_time_t(nextExecutionTime);	
	cout << "Next execution time: " << ctime(&nextExecutionTime_t); 
}
