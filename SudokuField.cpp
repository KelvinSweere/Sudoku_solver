#include "SudokuField.h"
#include <iostream>

int _convert2StartValueField(int row);
int _convert2StartValue(int row);

/*
*	@brief constructor
*/
SudokuField::SudokuField()
{
	std::cout << "Sudokufield is aangemaakt\n\n";
}

void SudokuField::setDataToField(int field, int row, int column)
{
	SudokuField::data[field][row][column];
}


int SudokuField::getDataFromField(int field, int row, int column)
{
	return SudokuField::data[field][row][column];	//field, x, y
}

bool SudokuField::checkRow(int row, int val)
{
	//algortime.
	return true;
}

int *SudokuField::getRow(int row)
{
	/*
	Row 0 -> 8
	*/
	if (row >= 0 && row < 9)
	{
		static int row_values[9];

		int field;

		//get according field and row 
		field = _convert2StartValueField(row);	//0, 3, 6.
		row = _convert2StartValue(row);		//0,1,2	

		#ifdef DEBUG
		std::cout << "field = " << field << " row_start " << row << std::endl;
		#endif

		const int field_max = field + 3;	//bv 3,4,5

		for (int i=0; field < field_max; field++)
		{
			for (int y = 0; y < 3; y++)
			{
				#ifdef DEBUG
				std::cout << "[" << field << "] [" << row << "] [" << y << "]" << std::endl;
				#endif
				row_values[i] = getDataFromField(field, row, y);
				i++;
				//-------------------------------------------------
			}
		}
		return row_values;
	}
	else
		std::cout << "Wrong row number!" << std::endl;
}

int* SudokuField::getColumn(int colum)
{
	/*
	Column 0 -> 8
	*/
	if (colum >= 0 && colum < 9)
	{
		static int column_values[9];

		int field;

		//get according field and row 
		field = _convert2StartValueField(colum);	//0, 3, 6.
		colum = _convert2StartValue(colum);		//0,1,2	

		#ifdef DEBUG
		std::cout << "field = " << field << " colum_start " << colum << std::endl;
		#endif

		const int field_max = field + 3;	//bv 3,4,5
		

		for (int i = 0; field < field_max; field++)
		{
			for (int x = 0; x < 3; x++)
			{
				#ifdef DEBUG
				std::cout << "[" << field << "] [" << colum << "] [" << y << "]" << std::endl;
				#endif
				column_values[i] = getDataFromField(field, x, colum);
				i++;
				//-------------------------------------------------
			}
		}
		return column_values;
	}
	else
		std::cout << "Wrong colum number!" << std::endl;
}

int _convert2StartValueField(int row)
{
	int field;
	if (row < 3)		field = 0;		//0,1,2
	else if (row >= 3 && row < 6)	field = 3;	//3,4,6
	else if (row >= 6 && row < 9)	field = 6;	//6,7,8
	else
		std::cout << "Row is out of boundry, because row = " << row << std::endl;

	return field;
}


/*
* Tested. Doesn't make the situation better. 
*/
int _convert2StartValue(int row)
{
	int row_start = 0;

	if		(row == 2	|| row == 5 || row == 8)	row_start = 2;
	else if (row == 1	|| row == 4 || row == 7)	row_start = 1;
	else if (row == 0	|| row == 3 || row == 6)	row_start = 0;
	else
		std::cout << "Row is out of boundry, because row = " << row << std::endl;

	return row_start;
}


void SudokuField::printField(void)
{
	static int ar[9];
	int *parray;
	
	
	for (int row_num = 0; row_num < 9; row_num++)
	{
		parray = SudokuField::getRow(row_num);
		//print row
		for (int i = 0; i < 9; i++)
		{
			ar[i] = (int)*(parray + i);

			if (i % 3 == 0 && i != 0)
				std::cout << " || ";

			std::cout << ar[i] << " ";
		}

		//print vertical lines
		if ((row_num+1) % 3 == 0 && row_num != 8)
		{
			std::cout << std::endl;
			for (int i = 0; i < 25; i++)
				std::cout << "-";
		}
		std::cout << std::endl;
	}
		
}
