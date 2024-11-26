#include "Robot.h"

Robot::Robot(Location& location)
	:m_location {location}, m_first_location{location}
{
}


void Robot::setLocation(Location location)
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

void Robot::print(const Location& location)
{
	Screen::setLocation(location);
	cout << '/';
}

bool Robot::check_if_ligel_move()
{
	return false;
}

void Robot::deleteOld_location(Location& location)
{
	Screen::setLocation(location);
	cout << ' ';
}
void Robot::move(Location& location)
{
	m_location = location;
}
//Board & 
//void Robot::move(Board& board, Manager& manager)
