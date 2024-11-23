#pragma once
#include "io.h"
#include "Location.h"
#include <fstream>
#include <iostream>
#include "Robot.h"
#include <conio.h>
using namespace std;

int main()
{
	auto level01 = std::ifstream("level01.txt");


	int row_level = 1, col_level = 0;

	while (level01.get() != '\n')
		col_level++;
	level01.clear(); // מוודאים שאין שגיאות בסטרים
	level01.seekg(0, ios::beg); // מחזירים את הקריאה להתחלה

	char c;
	while (level01 >> c)
	{
		if (level01.peek() == '\n')
			row_level++;
	}

	/*cout << "col_level =" << col_level << endl
		<< "row_level =" << row_level << endl;*/


	char** m_level = new char* [row_level]; // הקצאת שורות
	for (int i = 0; i < row_level; i++)
	{
		m_level[i] = new char[col_level]; // הקצאת עמודות לכל שורה
	}

	level01.clear(); // מוודאים שאין שגיאות בסטרים
	level01.seekg(0, ios::beg); // מחזירים את הקריאה להתחלה
	
	Location robot_location;
	int row = 0, col = 0;

	for (int i = 0; i < row_level && !level01.eof(); i++) 
	{
		for (int j = 0; j < col_level && !level01.eof(); j++) 
		{
			level01 >> noskipws >> c;
			if (c == '/')
			{
				robot_location = Location(i, j);
				row = i;
				col = j;
			}

			if (c == '\n') 
				j--; // דלגו על שורות ריקות
			else 
			  m_level[i][j] = c;
			
		}
	}

	Robot robot(robot_location);
	//cout << endl <<  robot.get_location().row << "," << robot.get_location().col << endl;
	
		for (int i = 0; i < row_level  ; i++)
		{
			for (int j = 0; j < col_level  ; j++)
			{
				cout <<   m_level[i][j];
			}
			cout << endl;
		}
		

//-------------------robot_moving--------------//

		
		for (int i = 0; i < 10; i++)
		{
			if (_getch() == Keys::SPECIAL_KEY)
			{
				int move = _getch();
				if (move == SpecialKeys::UP)
				{
					m_level[row - 1][col] = '/';
					m_level[row][col] = ' ';
					row--;
					robot.current_location(Location(row, col));
				}
				else if (move == SpecialKeys::DOWN)
				{
					m_level[row + 1][col] = '/';
					m_level[row][col] = ' ';
					row++;
					robot.current_location(Location(row, col));


				}
				else if (move == SpecialKeys::RIGHT)
				{
					m_level[row][col + 1] = '/';
					m_level[row][col] = ' ';
					col++;
					robot.current_location(Location(row, col));

				}
				else if (move == SpecialKeys::LEFT)
				{
					m_level[row][col - 1] = '/';
					m_level[row][col] = ' ';
					col--;
					robot.current_location(Location(row, col));

				}

			}
		/*	Screen::resetLocation();
			Screen::setLocation(Location(row, col));*/
		}

		for (int i = 0; i < row_level; i++)
		{
			for (int j = 0; j < col_level; j++)
			{
				cout << m_level[i][j];
			}
			cout << endl;
		}
		


//------------------end_robot_moving---------------//




		for (int i = 0; i < row_level; i++) 
		{
			delete[] m_level[i]; // שחרור עמודות של כל שורה
		}
		delete[] m_level; // שחרור השורות
	

		return 0;
}