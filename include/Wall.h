#pragma once
#include "Location.h"
#include <fstream>
#include <iostream>
#include <string>

class stone
{
public:

	stone(Location& location);
private:
	Location m_location;
};