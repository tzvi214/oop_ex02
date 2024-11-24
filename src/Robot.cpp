#include "Robot.h"

Robot::Robot(Location& location)
	:m_location {location}, m_first_location{location}
{
}



void Robot::current_location(Location location)
{
	m_location = location;
}

Location Robot::get_location()
{
	return m_location;
}

Location Robot::get_first_location()
{
	return m_first_location;
}
