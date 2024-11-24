#include "Items.h"


Items::Items(Location& location, char c)
    : m_rock(location), m_exitDoor(location), m_bomb(location, 0),
    m_wall(location), m_robot(location), m_guard(location), m_space(location),
    m_is_rock(false), m_is_exitDoor(false), m_is_bomb(false),
    m_is_wall(false), m_is_robot(false), m_is_guard(false), m_is_space(false)
{
   
    if (c == '@') 
        m_is_rock = true;
    
    else if (c == 'D') 
        m_is_exitDoor = true;
    
    else if (c == '#') 
        m_is_wall = true;
    
    else if (c == '/') 
        m_is_robot = true;
    
    else if (c == '!') 
        m_is_guard = true;
    
    else if (c == ' ') 
        m_is_space = true;
    
    else if (c == 'B') 
        m_is_bomb = true;
    
}


bool Items::is_rock()
{
	return m_is_rock;
}

bool Items::is_exitDoor()
{
	return m_is_exitDoor;
}

bool Items::is_wall()
{
	return m_is_wall;
}

bool Items::is_robot()
{
	return m_is_robot;
}

bool Items::is_guard()
{
	return m_is_guard;
}

bool Items::is_space()
{
	return m_is_space;
}

