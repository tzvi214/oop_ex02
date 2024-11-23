#include "Robot.h"

Robot::Robot(Location& location)
	:m_location {location}
{
}

Robot::Robot(int row, int col)
	
{
	m_location = Location(row, col);
}

void Robot::current_location(Location location)
{
	m_location = location;
}

Location Robot::get_location()
{
	return m_location;
}
