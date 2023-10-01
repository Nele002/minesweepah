#include "Cell.h"


void Cell::setPos(int xpos, int ypos) {
	this->xpos = xpos;
	this->ypos = ypos;
}

void Cell::setBomb(bool tf) {
	isBomb = tf;
}

void Cell::setCover(bool isUncovered) {
	this -> isUncovered = isUncovered;
}

void Cell::incNeighborBombs() {
	neighborBombs++;
}

bool Cell::hasBomb() const {
	return isBomb;
}