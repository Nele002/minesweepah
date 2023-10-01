#include <time.h>
#include <random>
#include "SDL.h"
#include "SDL_image.h"
#include "Board.h"
#include "Cell.h"
#include "TextureManager.h"

Board::Board(int size) {
	this->size = size;
	cell = new Cell*[size];
	for (int i = 0; i < size; i++) {
		cell[i] = new Cell[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cell[i][j].setBomb(false);
			cell[i][j].setCover(false);
			cell[i][j].setPos(i, j);
		}
	}

}

Board::~Board() {
	for (int i = 0; i < size; i++) {
		delete[] cell[i];
	}

	delete cell;
}

void Board::plantBombs(int numOfBombs) {
	int p, q;
	for (int i = 0; i < numOfBombs; i++) {
		p = rand() % 16;
		q = rand() % 16;
		if(!(cell[p][q].hasBomb())){
			cell[p][q].setBomb(true);
		}
		else {
			i--;
		}
	}
}

void Board::updateNeighborsNeighborBombCount() {
}

void Board::uncoverCells(int x, int y) {
	SDL_Rect src, dest;

	src.w = src.h = 32;
	src.x = src.y = 0;

	dest.h = dest.w = 32;
	dest.x = x * 32;
	dest.y = y * 32;

	SDL_Texture* temp = TextureManager::LoadTexture("assets/bomb.png");
	TextureManager::Draw(temp, src, dest);
	std::cout << "rendered!" << std::endl;


}