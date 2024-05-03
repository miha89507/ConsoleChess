#pragma once
#include <vector>
#include "Figure.h"
#include "Logger.h"

class Utils {
public:
	Utils();
	~Utils();
	static int charToInt(char input);
	static void outputSpacer(int lengthSpacer);
	static void outputSpacesByNumber(int amountSpaces);
	static void outputCharDecoration(int inputAmount, std::string outputString);
	static Figure* findFigure(std::vector<Figure*> inputArray, std::string searchNameFigure, 
								std::string currentPosition);
	static int findFigureIndex(std::vector<Figure*> inputArray, std::string searchNameFigure, 
								std::string currentPosition);
	static void outputLog(Logger* logger);
};