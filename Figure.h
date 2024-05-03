#pragma once
#include <string>

class Figure {
public:
	Figure(std::string inputNameFigure, std::string startPosition, std::string view);
	void setPosition(std::string inputPosition);
	void setViewFigure(std::string inputViewFigure);
	std::string getNameFigure();
	std::string getCurrentPositionFigure();
	std::string	getViewFigure();
	void kill();
	~Figure();
private:
	std::string nameFigure;
	std::string currentPosition;
	std::string	viewFigure;
	bool		isAlive;
};