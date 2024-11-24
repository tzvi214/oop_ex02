#pragma once
#include "Location.h"

class Robot
{
public:
	Robot(Location &location);
	void current_location(Location location);
	Location get_location();
	Location get_first_location();
private:
	Location m_location;
	Location m_first_location;
};
