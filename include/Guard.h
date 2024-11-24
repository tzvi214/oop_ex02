#pragma once
#include "Location.h"
#include <fstream>
#include <iostream>
#include <string>

class Guard
{
public:
	Guard(Location& location);
	Location get_location();
	void set_location(Location& location);
	Location get_first_loction();
 private:
	 Location m_location;
	 Location m_first_loction;
};

