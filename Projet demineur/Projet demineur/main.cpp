#include <iostream>
#include <cstdlib>
#include "Grid.h"
#include "Cell.h"

int main()
{

        std::srand(std::time(nullptr));

        std::cout << "Bienvenue dans le Demineur !" << std::endl;

        Grid grid;

        int rowCount, colCount;
        Difficulty(&grid, rowCount, colCount);
        Initialize(&grid, rowCount, colCount);

        bool minesPlaced = false;

        while (true) {

            Display(&grid);
            int indexRow = 0;
            int indexCol = 0;

            std::cout << "Choisis ta case :" << std::endl;
            std::cin >> indexRow >> indexCol;

            if (indexRow > rowCount || indexCol > colCount)
            {
                std::cout << "Ce n'est pas dans le tableau. Recommencez :" << std::endl;
                std::cin >> indexRow >> indexCol;
            }

            grid.array[indexRow][indexCol].isRevealed = true;
            grid.array[indexRow][indexCol].isMine = false;

            
            PlaceMines(&grid, indexRow, indexCol); // placer les mines après la première case
            minesPlaced = true;
          

        }
   
    

    return 0;
}