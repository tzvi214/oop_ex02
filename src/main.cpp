#pragma once
#include "io.h"
#include "Location.h"
#include <fstream>
#include <iostream>
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

	cout << "col_level =" << col_level << endl
		<< "row_level =" << row_level << endl;


	char** m_level = new char* [row_level]; // הקצאת שורות
	for (int i = 0; i < row_level; i++)
	{
		m_level[i] = new char[col_level]; // הקצאת עמודות לכל שורה
	}

	level01.clear(); // מוודאים שאין שגיאות בסטרים
	level01.seekg(0, ios::beg); // מחזירים את הקריאה להתחלה
	
		
	for (int i = 0; i < row_level && !level01.eof(); i++) 
	{
		for (int j = 0; j < col_level && !level01.eof(); j++) 
		{
			level01 >> noskipws >> c;
			if (c == '\n') 
				j--; // דלגו על שורות ריקות
			else 
			  m_level[i][j] = c;
			
		}
	}

	
	
		for (int i = 0; i < row_level  ; i++)
		{
			for (int j = 0; j < col_level  ; j++)
			{
				cout <<   m_level[i][j];
			}
			cout << endl;
		}




		for (int i = 0; i < row_level; i++) {
			delete[] m_level[i]; // שחרור עמודות של כל שורה
		}
		delete[] m_level; // שחרור השורות
	

		return 0;
}