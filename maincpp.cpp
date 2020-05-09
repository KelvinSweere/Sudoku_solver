#include <iostream>
#include "SudokuField.h"

int main(int argc, char* argv[])
{
	SudokuField sf("sudoku_file_v2.txt");
	sf.printField();

	//2D space...
	
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			for (int val = 1; val < 9; val++)
			{
				//check wich is faster first field checken and then val checken, or the other way around...

				//TODO: last getDataFromXY! <- not stable!!!!!!
				if (sf.getDataFromXY(x, y) != val)
				{
					if (sf.checkFieldFromXY(x,y, val))
					{
						//check other xs...
						//x = 0 -> 1,2
						//x = 1 -> 0,2
						//x = 2 -> 0,1
							
						//check if the value is in one of the other x's

																   
						//check if the value is in one of the other y's
					}
				}
			}

		}
	}
}

