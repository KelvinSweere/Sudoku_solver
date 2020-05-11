#include "SudokuField.h"
#include <iostream>
#include <fstream>

int _conv_X_or_Y_2_3DObject(int val);

/*
*	@brief constructor
*/
SudokuField::SudokuField(std::string name)
{
	std::cout << "Sudokufield is aangemaakt\n\n";
	
	SudokuField::setCompleteFieldFromFile(name);
}


//---------------------SETTERS---------------------
/*
* @brief Set value to 3D space of the object.
*/
void SudokuField::setDataToField(int field, int row, int column, int val)
{
	SudokuField::data[field][row][column] = val;
}

/*
* @brief Set complete file from constructor to the datafield.
*/
void SudokuField::setCompleteFieldFromFile(std::string name)
{
	std::ifstream myfile;
	myfile.open(name);

	char line[24];

	static int data[9];


	if (myfile)  // same as: if (myfile.good())
	{
		int row = 0;
		bool add_row = false;
		while (myfile.getline(line, 24))  // same as: while (getline( myfile, line ).good())
		{
			//std::cout << line << "\n";
			for (int x = 0, i = 0; x < 24; x += 8)
			{
				for (int y = 1; y < 6; y += 2)
				{
					if (line[x + y] != '-')
					{
						add_row = true;
						if (line[x + y] == '.')
							line[x + y] = '0';

						data[i] = (int)line[x + y] - '0';
						i++;
					}
					else add_row = false;

				}
			}

			if (add_row)
			{
				SudokuField::setRow(row, data);

				row++;
			}

		}

		myfile.close();
	}
}

/*
* @brief Set row to the object.
*/
void SudokuField::setRow(int row, int* pdata)
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

		for (int i = 0; field < field_max; field++)
		{
			for (int y = 0; y < 3; y++, i++)
			{
#ifdef DEBUG
				std::cout << "[" << field << "] [" << row << "] [" << y << "]" << std::endl;
#endif
				SudokuField::setDataToField(field, row, y, (int)pdata[i]);
				//-------------------------------------------------
			}
		}
	}
	else
	{
		std::cout << "Wrong row number!" << std::endl;
	}
}

/*
* @brief convert x,y to 3D object. E.g. 6 -> 0, 7 -> 1, 8 -> 2.
*/
int _conv_X_or_Y_2_3DObject(int val)
{
	int section;
	if (val < 3)
		section = 0;
	else if (val < 6)
		section = 1;
	else
		section = 2;

	return (val - (section * 3));
}

int _conv_X_or_y_2_Field_value(int x, int y)
{

	//conv x,y to field
	int field;
	if (x < 3)
		field = 0;
	else if (x < 6)
		field = 3;
	else
		field = 6;


	if (y < 3)
		field += 0;
	else if (y < 6)
		field += 1;
	else
		field += 2;
	return field;
}
/*
* @brief Convert X,Y values to 3D space inside the object.
* @param x range between 0,8.
* @param y range between 0,8.
*/
int SudokuField::getDataFromXY(int x, int y)	//row, column
{
	int field = _conv_X_or_y_2_Field_value(x, y);
	int row = _conv_X_or_Y_2_3DObject(x);
	int column= _conv_X_or_Y_2_3DObject(y);

	//std::cout << "x = " << row << " y = " << column << " field = " << field << std::endl;

	return SudokuField::getDataFromField(field, row, column);
}


//---------------------GETTERS---------------------
/*
* @brief Get value from the object.
*/
int SudokuField::getDataFromField(int field, int row, int column)
{
	return SudokuField::data[field][row][column];	//field, x, y
}

/*
* @brief Get 9 values that are in the field.
*/
int* SudokuField::getField(int field)
{
	/*
	Column 0 -> 8
	*/
	if (field >= 0 && field < 9)
	{
		static int column_values[9];

		//get according field and row 

#ifdef DEBUG	
		std::cout << "field = " << field << " colum_start " << colum << std::endl;
#endif

		int i = 0;

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
#ifdef DEBUG
				std::cout << "[" << field << "] [" << colum << "] [" << y << "]" << std::endl;
#endif
				column_values[i] = SudokuField::getDataFromField(field, x, y);
				i++;
				//-------------------------------------------------
			}
		}
		return column_values;
	}
	else
	{
		std::cout << "Wrong colum number!" << std::endl;
		return NULL;
	}
}

/*
* @brief Get 9 values that are in the column.
*/
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
	{
		std::cout << "Wrong colum number!" << std::endl;
		return NULL;
	}
}

/*
* @brief Get 9 values that are in the row.
*/
int* SudokuField::getRow(int row)
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

		for (int i = 0; field < field_max; field++)
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
	{
		std::cout << "Wrong row number!" << std::endl;
		return NULL;
	}
}

//--------------------CHECKERS--------------------

//TODO: think of a strategy how to use the checkers...
bool SudokuField::checkFieldAvailability(int field, int val)
{
	if (SudokuField::checkField(field, val))
		std::cout << "val = " << val << " is in Field #" << field << std::endl;
	else
		std::cout << "val = " << val << " is NOT in Field #" << field << std::endl;

	return (SudokuField::checkField(field, val)) ? true : false;
}

/*
* @brief checks if value from x,y is in the correct field.
*/
bool SudokuField::checkFieldFromXY(int x, int y, int val)
{
	//check if value is in # field.

	//conv x,y to field num
	int field = _conv_X_or_y_2_Field_value(x, y);
	int tel = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			if (SudokuField::getDataFromField(field, row, column) == val)
				return false;
		}
	}

	return true;
}

/*
	@brief checks if number is in the row. Returns true if it's posible to place that number, false if not.
*/
bool SudokuField::checkRow(int row, int val)
{
	//algortime.
	int* pdata = SudokuField::getRow(row);
	return _checkIfDataIsInArray(pdata, val);

}

/*
	@brief checks if number is in the field. Returns true if it's posible to place that number, false if not.
*/
bool SudokuField::checkField(int field, int val)
{
	int* pdata = SudokuField::getField(field);
	return _checkIfDataIsInArray(pdata, val);	//1 if it's already in, 0 if not. 
}

/*
	@brief checks if number is in the column. Returns true if it's posible to place that number, false if not.
*/
bool SudokuField::checkColumn(int row, int val)
{
	//algortime.
	int* pdata = SudokuField::getColumn(row);
	return _checkIfDataIsInArray(pdata, val);

}


//--------------------FUNCTIONAL--------------------
/*
* @brief prints complete field with current data.
*/
void SudokuField::printField(void)
{
	static int ar[9];
	int* parray;


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
		if ((row_num + 1) % 3 == 0 && row_num != 8)
		{
			std::cout << std::endl;
			for (int i = 0; i < 25; i++)
				std::cout << "-";
		}
		std::cout << std::endl;
	}

}
