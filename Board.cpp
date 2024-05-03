#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Board.h"
#include "Figure.h"
#include "Utils.h"

Board::Board(int inputWidth, int inputHeight) {
	boardWidth = inputWidth;
	boardHeigt = inputHeight;
	numberAlphabet = { 
		{0, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'},
		{4, 'e'}, {5, 'f'}, {6, 'g'}, {7, 'h'} 
	};
	alphabetNumber = {
		{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3},
		{'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}
	};
	blackFigures = {
		new Figure("BF", "a8", "U*"), new Figure("BF", "h8", "U*"),
		new Figure("BH", "b8", "2*"), new Figure("BH", "g8", "2*"),
		new Figure("BE", "c8", "1*"), new Figure("BE", "f8", "1*"),
		new Figure("BQ", "d8", "W*"), new Figure("BK", "e8", "V*"),
		new Figure("BS", "a7", "0*"), new Figure("BS", "h7", "0*"),
		new Figure("BS", "b7", "0*"), new Figure("BS", "g7", "0*"),
		new Figure("BS", "c7", "0*"), new Figure("BS", "f7", "0*"),
		new Figure("BS", "d7", "0*"), new Figure("BS", "e7", "0*")
	};
	whiteFigures = {
		new Figure("WF", "a1", "U "), new Figure("WF", "h1", "U "),
		new Figure("WH", "b1", "2 "), new Figure("WH", "g1", "2 "),
		new Figure("WE", "c1", "1 "), new Figure("WE", "f1", "1 "),
		new Figure("WQ", "d1", "W "), new Figure("WK", "e1", "V "),
		new Figure("WS", "a2", "0 "), new Figure("WS", "h2", "0 "),
		new Figure("WS", "b2", "0 "), new Figure("WS", "g2", "0 "),
		new Figure("WS", "c2", "0 "), new Figure("WS", "f2", "0 "),
		new Figure("WS", "d2", "0 "), new Figure("WS", "e2", "0 ")
	};
	buildBoard();
	initBlackFigures();
	initWhiteFigures();
}

void Board::outputBoard() {
	//Output letters
	Utils::outputSpacesByNumber(27);
	for (int jCounter = 0; jCounter < boardWidth; jCounter++) {
		std::cout << '[' << numberAlphabet[jCounter] << ']' << "   ";
	}
	std::cout << std::endl;
	Utils::outputSpacesByNumber(25);
	Utils::outputSpacer(48);
	Utils::outputSpacesByNumber(24);
	Utils::outputCharDecoration(9, "!");
	std::cout << std::endl;

	for (int iCounter = 0; iCounter < boardHeigt; iCounter++) {
		Utils::outputSpacesByNumber(19);
		std::cout << '[' << 8 - iCounter << ']' << "  |";
		for (int jCounter = 0; jCounter < boardWidth; jCounter++) {
			std::cout << " " << board[iCounter][jCounter] << " |";
		}
		std::cout << "  " << '[' << 8 - iCounter << ']';
		Utils::outputSpacesByNumber(19);
		std::cout << std::endl;
		Utils::outputSpacesByNumber(25);
		Utils::outputSpacer(48);
		Utils::outputSpacesByNumber(24);
		Utils::outputCharDecoration(9, "!");
		std::cout << std::endl;
	}

	//Output letters
	Utils::outputSpacesByNumber(26);
	for (int jCounter = 0; jCounter < boardWidth; jCounter++) {
		std::cout << '[' << numberAlphabet[jCounter] << ']' << "   ";
	}
	std::cout << std::endl;
}

void Board::outputReverseBoard() {
	//Output letters
	Utils::outputSpacesByNumber(27);
	for (int jCounter = boardWidth - 1; jCounter >= 0; jCounter--) {
		std::cout << '[' << numberAlphabet[jCounter] << ']' << "   ";
	}
	std::cout << std::endl;
	Utils::outputSpacesByNumber(25);
	Utils::outputSpacer(48);
	Utils::outputSpacesByNumber(24);
	Utils::outputCharDecoration(9, "!");
	std::cout << std::endl;

	for (int iCounter = boardHeigt - 1; iCounter >= 0; iCounter--) {
		Utils::outputSpacesByNumber(19);
		std::cout << '[' << 8 - iCounter << ']' << "  |";
		for (int jCounter = boardWidth - 1; jCounter >= 0; jCounter--) {
			std::cout << ' ' << board[iCounter][jCounter] << " |";
		}
		std::cout << "  " << '[' << 8 - iCounter << ']';
		Utils::outputSpacesByNumber(19);
		std::cout << std::endl;
		Utils::outputSpacesByNumber(25);
		Utils::outputSpacer(48);
		Utils::outputSpacesByNumber(24);
		Utils::outputCharDecoration(9, "!");
		std::cout << std::endl;
	}

	//Output letters
	Utils::outputSpacesByNumber(26);
	for (int jCounter = boardWidth - 1; jCounter >= 0; jCounter--) {
		std::cout << '[' << numberAlphabet[jCounter] << ']' << "   ";
	}
	std::cout << std::endl;
}

void Board::changePosition(std::string figureView, std::string startPosition, 
							std::string endPosition) {
	Figure* currentFigure = nullptr;
	int figureIndex = -1;
	int getValueByLetter = -1;
	int getValueByCharNumber = -1;

	if (figureView[1] == ' ') {
		currentFigure = Utils::findFigure(whiteFigures, figureView, startPosition);
		figureIndex = Utils::findFigureIndex(whiteFigures, figureView, startPosition);
		currentFigure->setPosition(endPosition);
		whiteFigures[figureIndex] = currentFigure;
	} else {
		currentFigure = Utils::findFigure(blackFigures, figureView, startPosition);
		figureIndex = Utils::findFigureIndex(blackFigures, figureView, startPosition);
		currentFigure->setPosition(endPosition);
		blackFigures[figureIndex] = currentFigure;
	}
	
	getValueByLetter = alphabetNumber[startPosition[0]];
	getValueByCharNumber = 8 - Utils::charToInt(startPosition[1]);
	board[getValueByCharNumber][getValueByLetter] = " . ";

	getValueByLetter = alphabetNumber[endPosition[0]];
	getValueByCharNumber = 8 - Utils::charToInt(endPosition[1]);
	board[getValueByCharNumber][getValueByLetter] = " " + figureView;
}

void Board::changeView(std::string currentFigureView, std::string neededFigureView, 
						std::string currentFigurePosition) {
	Figure* currentFigure = nullptr;
	int figureIndex = -1;
	int getValueByLetter = -1;
	int getValueByCharNumber = -1;

	if (currentFigureView[1] == ' ') {
		currentFigure = Utils::findFigure(whiteFigures, currentFigureView, currentFigurePosition);
		figureIndex = Utils::findFigureIndex(whiteFigures, currentFigureView, currentFigurePosition);
		currentFigure->setViewFigure(neededFigureView);
		whiteFigures[figureIndex] = currentFigure;
	}
	else {
		currentFigure = Utils::findFigure(blackFigures, currentFigureView, currentFigurePosition);
		figureIndex = Utils::findFigureIndex(blackFigures, currentFigureView, currentFigurePosition);
		currentFigure->setPosition(neededFigureView);
		blackFigures[figureIndex] = currentFigure;
	}
	getValueByLetter = alphabetNumber[currentFigurePosition[0]];
	getValueByCharNumber = 8 - Utils::charToInt(currentFigurePosition[1]);
	board[getValueByCharNumber][getValueByLetter] = " " + neededFigureView;
}

void Board::makeShortGoToHome(std::string color) {
	if (color == "white") {
		changePosition("V ", "e1", "g1");
		changePosition("U ", "h1", "f1");
	} else {
		changePosition("V*", "e8", "g8");
		changePosition("U*", "h8", "f8");
	}
}

void Board::makeLongGoToHome(std::string color) {
	if (color == "white") {
		changePosition("V ", "e1", "c1");
		changePosition("U ", "a1", "d1");
	}
	else {
		changePosition("V*", "e8", "c8");
		changePosition("U*", "a8", "d8");
	}
}

void Board::turnController(std::string inputTurn) {
	if (inputTurn.size() == 4) {
		if (inputTurn[1] == ' ') {
			makeShortGoToHome("white");
		} else {
			makeShortGoToHome("black");
		}
	}
	else {
		std::string firstPart = inputTurn.substr(0, 2);
		std::string secondPart = inputTurn.substr(2, 2);
		std::string thirdPart = inputTurn.substr(4, 2);
		std::string viewForChange = "";
		Figure* currentFigure = nullptr;
		int figureIndex = -1;

		if (secondPart == "-0" && thirdPart == "-0") {
			if (firstPart[1] == ' ') {
				makeLongGoToHome("white");
			} else {
				makeLongGoToHome("black");
			}
		} else {
			if (firstPart[1] == ' ') {
				changePosition(firstPart, secondPart, thirdPart);

				if (firstPart == "0 " && thirdPart[1] == '8') {
					std::cout << "Use magick (U/2/?/W): ";
					std::cin >> viewForChange;
					changeView(firstPart, viewForChange, thirdPart);
				}
			}
			else {
				changePosition(firstPart, secondPart, thirdPart);

				if (firstPart == "0*" && thirdPart[1] == '1') {
					std::cout << "Use magick (U/2/?/W): ";
					std::cin >> viewForChange;
					changeView(firstPart, viewForChange + '*', thirdPart);
				}
			}
		}
	}
}

void Board::buildBoard() {
	for (int iCounter = 0; iCounter < boardHeigt; iCounter++) {
		std::vector<std::string> tempVector(boardWidth, " . ");
		board.push_back(tempVector);
	}
}

void Board::initBlackFigures() {
	for (int jCounter = 0; jCounter < blackFigures.size(); jCounter++) {
		int getValueByLetter = alphabetNumber[blackFigures[jCounter]->getCurrentPositionFigure()[0]];
		int getValueByCharNumber = 8 - Utils::charToInt(blackFigures[jCounter]->getCurrentPositionFigure()[1]);
		board[getValueByCharNumber][getValueByLetter] = " " + blackFigures[jCounter]->getViewFigure();
	}
}

void Board::initWhiteFigures() {
	for (int jCounter = 0; jCounter < whiteFigures.size(); jCounter++) {
		int getValueByLetter = alphabetNumber[whiteFigures[jCounter]->getCurrentPositionFigure()[0]];
		int getValueByCharNumber = 8 - Utils::charToInt(whiteFigures[jCounter]->getCurrentPositionFigure()[1]);
		board[getValueByCharNumber][getValueByLetter] = " " + whiteFigures[jCounter]->getViewFigure();
	}
}