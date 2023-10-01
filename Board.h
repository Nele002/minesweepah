#pragma once

#include "Cell.h"

#ifndef Board_h
#define Board_h

class Board {
private:
	int size;
	int numOfBombs;
	Cell** cell;
public:
	Board(int size);
	~Board();

	void plantBombs(int numOfBombs);
	void updateNeighborsNeighborBombCount();
	void uncoverCells(int x, int y);
};

#endif