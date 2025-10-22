#include "Grid.h"
#include <iostream>

void Initialize(Grid* grid, int rowCount, int colCount) 
{
	grid->rowCount = rowCount;
	grid->colCount = colCount;

	grid->array = (Cell**)malloc(sizeof(Cell*) * rowCount);
	for (int i = 0; i < rowCount; ++i) 
	{
		grid->array[i] = (Cell*)malloc(sizeof(Cell) * colCount);

		for (int j = 0; j < colCount; ++j) 
		{
			Initialize(&grid->array[i][j]);
		}
	}
}

void Display(Grid* grid)
{
	
	for (int row = 0; row < grid->rowCount; row++)
	{
		for (int col = 0; col < grid->colCount; col++)
		{
			std::cout << "[";
				
			if (grid->array[row][col].isFlagged)
			{
				std::cout << "F";
			}

			else if (grid->array[row][col].isRevealed)
			{
				if (grid->array[row][col].isMine)
					std::cout << "*";

				else {
					std::cout << "0";
				}
			}

			else
			{
				std::cout << ".";
			}

			std::cout << "]";
		}

		std::cout << std::endl;
	}
}

void PlaceMines(Grid* grid, int safeRow, int safeCol)
{
	for (int i = 0; i < grid->rowCount; i++)
	{
		for (int j = 0; j < grid->colCount; j++)
		{
			if (i == safeRow && j == safeCol) continue; // protéger la première case

			if (rand() % 100 < 15) // 15% de chance
				grid->array[i][j].isMine = true;
				break;
		}
	}
}
void Difficulty(Grid* grid, int& rowCount, int& colCount)
{
	int diff;
	std::cout << "Choisi la difficultee : Facile (1), Normal (2), Difficile (3), Personnalise (4) :" << std::endl;
	std::cin >> diff;

	switch (diff)
	{
	case 1:
		rowCount = 9;
		colCount = 9;
		break;
	case 2:
		rowCount = 16;
		colCount = 16;
		break;
	case 3:
		rowCount = 30;
		colCount = 16;
		break;
	case 4:
		std::cout << "Choissisez votre taille (ligne x colonne) :" << std::endl;
		std::cin >> rowCount;
		std::cin >> colCount;
		break;
	default:
		std::cout << "Option invalide, on prend Normal par defaut." << std::endl;
		rowCount = 16;
		colCount = 16;
		break;

	}

}
/*
void Reveal(int size1, int size2, int** array, bool flag)
{

	for (int row = 0; row < size1; row++)
	{
		for (int col = 0; col < size2; col++)
		{

			if (array[row][col] = true)
			{
				std::cout << "[*]";
			}
			if (flag = true) {
				std::cout << "[F]";
			}

		}

		std::cout << std::endl;
	}

}


void CalculateNeighbors(Cell** array, int neighbors)
{

}

void PutFlag(bool flag, int row, int col)
{
	std::cout << "Places un drapeau :" << std::endl;
	std::cin >> row;
	std::cin >> col;

	flag = true;

}
*/