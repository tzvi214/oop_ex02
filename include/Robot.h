#pragma once
#include "Location.h"

class Robot
{
public:
	Robot(Location &location);
	Robot(int row, int col);
	void current_location(Location location);
	Location get_location();

private:
	Location m_location;
};
