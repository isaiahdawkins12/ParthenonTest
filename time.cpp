#include "parser.h"
#include "time.h"

using std::time_t, std::tm, std::localtime, std::ctime;
	
void calcNextExec(const cronJob& job){		
	// get system time and convert to a time_t format
	auto currentTime = std::chrono::system_clock::now();

	// move from time_t to tm	
	time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	tm current_tm = *localtime(&currentTime_t);

	// if -1 flag set, we need to set as current day or time	

	if (job.isEveryMinute == true) {	
		current_tm.tm_min = job.minute + job.minute;
	} else {
		current_tm.tm_min = job.minute;
	}
	if (job.isEveryHour == true){
		current_tm.tm_hour = job.hour + job.hour;
	} else {
		current_tm.tm_hour = job.hour + 1;
	}
	if (job.isEveryDay == true){
		current_tm.tm_mday = job.day + job.day;
	} else {
		current_tm.tm_mday = job.day;
	}
	if (job.isEveryMonth == true){
		current_tm.tm_mon = job.month + job.month;
	} else {
		current_tm.tm_mon = job.month;	
	}
	current_tm.tm_sec = 0;

	// calculate difference between execution and current job time
	auto nextExecutionTime = std::chrono::system_clock::from_time_t(std::mktime(&current_tm));

	time_t nextExecutionTime_t = std::chrono::system_clock::to_time_t(nextExecutionTime);
	cout << "Next execution time: " << std::ctime(&nextExecutionTime_t);
	
	return;
}
