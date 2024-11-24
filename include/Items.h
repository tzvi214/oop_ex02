#pragma once
#include "Location.h"
#include"Rock.h"
#include"ExitDoor.h"
#include"Bomb.h"
#include"Wall.h"
#include"Robot.h"
#include"Guard.h"
#include"Space.h"

class Items
{
public:
	Items( Location & location,  char c);
	bool is_rock();
	bool is_exitDoor();
	bool is_wall();
	bool is_robot();
	bool is_guard();
	bool is_space();

private:
	Rock m_rock;
	ExitDoor m_exitDoor;
	Bomb m_bomb;
	Wall m_wall;
	Robot m_robot;
	Guard m_guard;
	Space m_space;
	
	bool m_is_rock;
	bool m_is_exitDoor;
	bool m_is_bomb;
	bool m_is_wall;
	bool m_is_robot;
	bool m_is_guard;
	bool m_is_space;


};
