#pragma once
#include "Location.h"
#include "Board.h"

class Robot
{
public:
	Robot(Location &location);
	void setLocation(Location location);
	Location get_location();
	Location get_first_location();
	void print(const Location & location );
	bool check_if_ligel_move();
	void deleteOld_location(Location& location);
	void move(Location& location);
private:
	Location m_location;
	Location m_first_location;
	
};
