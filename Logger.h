#pragma once
#include <vector>
#include <string>

class Logger {
public:
	Logger();
	~Logger();
	void writeToLog(std::string inputTurn);
	std::vector<std::string> getLog();

private:
	std::vector<std::string> logHistory;
};