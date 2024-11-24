#include "Guard.h"

Guard::Guard(Location& location)
: m_location(location), m_first_loction (location)
{}

Location Guard::get_location() 
{
	return m_location;
}

void Guard::set_location(Location& location)
{
	m_location = location;
}

Location Guard::get_first_loction()
{
	return m_first_loction;
}
