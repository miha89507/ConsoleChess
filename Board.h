#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Figure.h"

class Board {
public:
	Board(int inputWidth, int inputHeight);
	void outputBoard();
	void outputReverseBoard();
	void turnController(std::string inputTurn);
	~Board() {};
private:
	int										boardWidth = 0;
	int										boardHeigt = 0;
	std::vector<std::vector<std::string>>	board;
	std::map<int, char>						numberAlphabet;
	std::map<char, int>						alphabetNumber;
	std::vector<Figure*>					blackFigures;
	std::vector<Figure*>					whiteFigures;
	void									buildBoard();
	void									initBlackFigures();
	void									initWhiteFigures();
	void									changePosition(std::string figureView,
															std::string startPosition, 
															std::string endPosition
											);
	void									changeView(std::string currentFigureView,
														std::string neededFigureView,
														std::string currentFigurePosition);
	void									makeShortGoToHome(std::string color);
	void									makeLongGoToHome(std::string color);
};
