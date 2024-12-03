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
	bool getTouch();
	Location get_first_location();
	void move(Board&, const Location&);
	void initialization();

private:
	Location m_location;
	Location m_first_location;
	bool m_touch;
	void chooseNewLoc(Board&, const Location&, int&, Location&);
	void set_location(Location& location);
	void print(Location);

};