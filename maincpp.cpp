#include <iostream>
#include "SudokuField.h"


int main(int argc, char* argv[])
{
	SudokuField sf("sudoku_file_v2.txt");
	sf.printField();


	return 1;
}