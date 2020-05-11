#include "SudokuField.h"
#include <iostream>

/*
* @brief convert column or row to the startvalue of the suduoku (e.g. 0,3,6).
*/
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
* @brief convert column or row to the startvalue of the suduoku (e.g. 0,1,2).
*/
int _convert2StartValue(int val)
{
	int val_start = 0;

	if (val == 2 || val == 5 || val == 8)	val_start = 2;
	else if (val == 1 || val == 4 || val == 7)	val_start = 1;
	else if (val == 0 || val == 3 || val == 6)	val_start = 0;
	else
		std::cout << "val is out of boundry, because val = " << val << std::endl;

	return val_start;
}

/*
	@brief checks if param val is in the pdata array. Returns false if it's minimal one time in the array.
*/
bool _checkIfDataIsInArray(int* pdata, int val)
{
	for (int i = 0; i < 9; i++)
	{
#ifdef DEBUG
		std::cout << *(pdata + i) << " ";
#endif	

		if ((int)*(pdata + i) == val)
			return true;
	}

	return false;
}

