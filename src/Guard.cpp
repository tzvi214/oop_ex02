#include "Guard.h"

guard::guard(Location& location)
: m_location(location), m_first_loction (location)
{}

Location guard::get_location() 
{
	return m_location;
}

void guard::set_location(Location& location)
{
	m_location = location;
}

Location guard::get_first_loction()
{
	return m_first_loction;
}
