#pragma once
#include "Location.h"
#include <fstream>
#include <iostream>
#include <string>
class Board;

class Guard
{
public:
	Guard(const Location& location);
	Location get_location();
	void set_location(Location& location);
	Location get_first_location();
	void print(Location);
	void move(Board&); // NOT CONST!!
	Location chooseNewLocation(Location);

private:
	Location m_location;
	Location m_first_location;
};
