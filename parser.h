#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::string, std::ifstream, std::cout, std::cerr, std::endl, std::istringstream, std::getline, std::isdigit, std::vector;

struct cronJob {
	int minute;
	int hour;
	int day;
	int month;
	int dayOfWeek;
	string command;
	
	bool isEveryMinute = false;
	bool isEveryHour = false;
	bool isEveryDay = false;
	bool isEveryMonth = false;
	bool isEveryDayOfWeek = false;
};

// function to parse lines for crontab commands
vector<cronJob> parseLine();

void printCronJobs(const vector<cronJob>& cronJobsVec);
#endif

