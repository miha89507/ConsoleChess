#include "Figure.h"
#include <string>

Figure::Figure(std::string inputNameFigure, std::string startPosition, std::string view) {
	nameFigure = inputNameFigure;
	currentPosition = startPosition;
	viewFigure = view;
	isAlive = true;
}

void Figure::setPosition(std::string inputPosition) {
	currentPosition = inputPosition;
}

void Figure::setViewFigure(std::string inputViewFigure) {
	viewFigure = inputViewFigure;
}

std::string Figure::getNameFigure(){
	return nameFigure;
}

std::string Figure::getCurrentPositionFigure(){
	return currentPosition;
}

std::string Figure::getViewFigure(){
	return viewFigure;
}

void Figure::kill() {
	isAlive = !isAlive;
}

Figure::~Figure() {}