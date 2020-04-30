#pragma once

#ifndef SUDOKUFIELD_TH
#define SUDOKUFIELD_TH

#define NUM_ROWS 9
#define NUM_COLUMNS 9

#include <iostream>

class SudokuField
{
private:
	int tmp;

	int data[9][3][3] = {
		//0
		{{1, 2, 3},
		{2, 2, 2},
		{0, 0, 0}},

		//1
		{{4, 5, 6},
		{2, 2, 2},
		{0, 0, 0}},

		//2
		{{7, 8, 9},
		{2, 2, 2},
		{0, 5, 0}},

		//3
		{{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}},

		//4
		{{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}},

		//5
		{{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}},

		//6
		{{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}},

		//7
		{{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}},

		//8
		{{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}}
	};

public:
	SudokuField();
	void setDataToField(int field, int row, int column);
	int getDataFromField(int field, int row, int column);

	int* getRow(int row);
	int* getColumn(int colum);
	void printField(void);
	
	bool checkRow(int row, int val);	//returns true if val is posible, false if not posible. 
};


#endif