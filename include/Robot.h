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
	Location get_location();
	Location get_first_location() const {return m_first_location ; }
	void print(const Location & location, char c = '/');
	void deleteOld_location(Location& location);
	void move(Location& location);
	void play(Board& board);// ��� �� ���� manger
	void set_dropBomb( bool flag);
	void setLocation(Location location);
	bool touch() const {return m_touch; }
	bool dropBomb();
	bool touch();
	void warningPrint() const;
	void initialization();
	bool fishnetLevel() const { return m_finshed ; }
	
private:
	Location m_location;
	Location m_first_location;
	bool m_drop_bomb;
	bool m_touch;
	bool m_finshed;
};
