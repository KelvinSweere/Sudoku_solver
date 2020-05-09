#pragma once

#ifndef SUDOKUFIELD_TH
#define SUDOKUFIELD_TH

#define NUM_ROWS 9
#define NUM_COLUMNS 9

#include <iostream>

int _convert2StartValueField(int row);
int _convert2StartValue(int val);
bool _checkIfDataIsInArray(int* pdata, int val);


class SudokuField
{
private:
	int tmp;

	int data[9][3][3];

public:
	SudokuField(std::string name);
	void setDataToField(int field, int row, int column, int val);
	void setRow(int row, int* pdata);
	void setCompleteFieldFromFile(std::string name);

	int getDataFromField(int field, int row, int column);

	int* getRow(int row);
	int* getColumn(int colum);
	int* getField(int field);

	int getDataFromXY(int x, int y);	//row, column
	bool checkFieldFromXY(int x, int y, int val);

	void printField(void);
	
	bool checkRow(int row, int val);	//returns true if val is posible, false if not posible. 
	bool checkColumn(int row, int val);
	bool checkField(int field, int val);

	bool checkFieldAvailability(int field, int val);

	int* _convXY2Object(int x, int y);

};


#endif