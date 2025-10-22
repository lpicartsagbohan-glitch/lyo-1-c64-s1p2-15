#include "Cell.h"
#include <iostream>

void Initialize(Cell* cell)
{
	cell->isMine = false;
	cell->isRevealed = false;
	cell->isFlagged = false;
	cell->neighbors = 0;
}
