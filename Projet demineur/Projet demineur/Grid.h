#pragma once

#include "Cell.h"

struct Grid
{
	Cell** array;
	int colCount;
	int rowCount;
	int nbrMines;
};

void Initialize(Grid* grid, int rowCount, int colCount);
void Display(Grid* grid);
void PlaceMines(Grid* grid, int safeRow, int safeCol);
void Difficulty(Grid* grid, int& rowCount, int& colCount);
//void Reveal(Grid* grid);