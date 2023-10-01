#pragma once

#ifndef Cell_h
#define Cell_h

class Cell {
private:
	int xpos;
	int ypos;
	bool isBomb;
	bool isUncovered;
	int neighborBombs = 0;
public:
	Cell() {}

	void setPos(int xpos, int ypos);
	void setBomb(bool tf);
	void setCover(bool isUncovered);
	void incNeighborBombs();
	bool hasBomb() const;

};

#endif