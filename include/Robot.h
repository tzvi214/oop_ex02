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

	Location get_first_location() const { return m_first_location; }
	Location get_location() const { return m_location; }
	void warningPrint() const;
	void initialization();
	void play(Board& board);
	bool touch() const {return m_touch; }
	bool dropBomb();
	bool fishnetLevel() const { return m_finshed ; }
	
private:
	Location m_location;
	Location m_first_location;
	bool m_drop_bomb;
	bool m_touch;
	bool m_finshed;
	void set_dropBomb(bool flag);
	void setLocation(Location &location);
	void move(Location& location);
	void deleteOld_location(Location& location);
	void print(const Location& location, char c = '/') const;


};
