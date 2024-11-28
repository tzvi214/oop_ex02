#pragma once
class Board;
class Manger;
#include "Location.h"
#include <iostream>
using namespace std;

class Robot
{
public:
	Robot(Location &location);
	void setLocation(Location location);
	Location get_location();
	Location get_first_location();
	void print(const Location & location );
	bool check_if_ligel_move( Board& board);
	void deleteOld_location(Location& location);
	void move(Location& location);
	void move(Board& board, Manger& manager);// הוא לא צריך manger
	void set_dropBomb( bool flag);
	bool dropBomb();

private:
	Location m_location;
	Location m_first_location;
	bool m_drop_bomb;
	
};
