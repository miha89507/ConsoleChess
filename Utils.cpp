#include "Utils.h"
#include <iostream>

Utils::Utils(){}

Utils::~Utils(){}

int Utils::charToInt(char input) {
	return (int)(input - '0');
}

void Utils::outputSpacer(int lengthSpacer) {
	for (int iCounter = 0; iCounter < lengthSpacer; iCounter++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}

void Utils::outputSpacesByNumber(int amountSpaces) {
	for (int iCounter = 0; iCounter < amountSpaces; iCounter++) {
		std::cout << " ";
	}
}

void Utils::outputCharDecoration(int inputAmount, std::string outputString) {
	for (int iCounter = 0; iCounter < inputAmount; iCounter++) {
		std::cout << outputString << "     ";
	}
}

Figure* Utils::findFigure(std::vector<Figure*> inputArray, std::string searchNameFigure,
							std::string currentPosition) {
	for (int iCounter = 0; iCounter < inputArray.size(); iCounter++) {
		if (inputArray[iCounter]->getViewFigure() == searchNameFigure && 
			inputArray[iCounter]->getCurrentPositionFigure() == currentPosition) {
			return inputArray[iCounter];
		}
	}
	return nullptr;
}

int Utils::findFigureIndex(std::vector<Figure*> inputArray, std::string searchNameFigure,
							std::string currentPosition) {
	for (int iCounter = 0; iCounter < inputArray.size(); iCounter++) {
		if (inputArray[iCounter]->getViewFigure() == searchNameFigure &&
			inputArray[iCounter]->getCurrentPositionFigure() == currentPosition) {
			return iCounter;
		}
	}
	return -1;
}

void Utils::outputLog(Logger* logger) {
	if (logger->getLog().size() >= 2) {
		std::cout << "History: ";
		for (int iCounter = 0; iCounter < logger->getLog().size(); iCounter++) {
			if (iCounter % 10 == 0 && iCounter != 0) {
				std::cout << std::endl;
			}

			if (iCounter % 2 == 0) {
				std::cout << (int) (iCounter / 2) + 1 << ".";
			}

			std::cout << logger->getLog()[iCounter].erase(1, 1) << " ";

		}
	}
}
