#include "Logger.h";

Logger::Logger(){}

Logger::~Logger(){}

void Logger::writeToLog(std::string inputTurn){
	logHistory.push_back(inputTurn);
}

std::vector<std::string> Logger::getLog(){
	return logHistory;
}
