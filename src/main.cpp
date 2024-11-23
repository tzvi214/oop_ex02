#pragma once
#include "io.h"
#include "Location.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	auto level01 = std::ifstream("level01.txt");


	int row_level =1, col_level =0;

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
	

	char i;

	while (level01 >> i)
	{
		std::cout << i;

		if (level01.peek() == '\n')
		{
			std::cout << "\n";
		}

		else
			while (level01.peek() == ' ')
			{
				std::cout << " ";
				level01.get();
			}
	}
}