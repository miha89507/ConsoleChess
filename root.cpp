#include <iostream>
#include <vector>
#include <math.h>
#include "Board.h"
#include "Logger.h"
#include "Utils.h"

void main() {
	Board* boardVar = new Board(8, 8);
	Logger* loggerVar = new Logger();
	int turnCounter = 0;
	std::string needTurnToDo = "";

	while (true) {
		std::cout << "Chess.exe (c) Starygin, 2024" << std::endl;
		std::cout << " 1 - Soldier  U - Fort  2 - Horse 1 - Elephant W - Queen V - King" << std::endl;

		switch (turnCounter) {
			case 0: {
				boardVar->outputBoard();
				turnCounter++;
				Utils::outputLog(loggerVar);
				std::cout << std::endl << "Input turn for white: ";
				break;
			}
			case 1: {
				boardVar->outputReverseBoard();
				turnCounter = 0;
				Utils::outputLog(loggerVar);
				std::cout << std::endl << "Input turn for black: ";
				break;
			}
		}
		std::cin >> needTurnToDo;

		switch (turnCounter) {
			case 0: {
				needTurnToDo.insert(1, "*");
				break;
			}
			case 1: {
				needTurnToDo.insert(1, " ");
				break;
			}
		}
		boardVar->turnController(needTurnToDo);
		loggerVar->writeToLog(needTurnToDo);
		needTurnToDo = "";
		getchar();
		system("cls");
	}
	system("pause");
}