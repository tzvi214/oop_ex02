#include "Bomb.h"
#include <io.h>
#include <iostream>

Bomb::Bomb(const Location& location, int time)
    : m_location{ location }, m_time{ time }
    ,m_warningRobot{false}
{}

 void Bomb::deleteData(Board& board)
{
    Screen::setLocation(m_location);
    std::cout << ' ';
    if (m_time <= 1)
    {
        deletePrinting(board);
    }
}

int Bomb::getTime() const 
{
    return m_time;
}

bool Bomb::isExploding() const 
{
   return (m_time == 1);
}

bool Bomb::isExploded() const
{
    return (m_time < 1);
}

void Bomb::renewTime()
{
    m_time--;
    print(m_location, (char) '0' +m_time);
}

void Bomb::print(Location& location, char c)
{
    Screen::setLocation(location);
    std::cout << c;
}

vector <Location> Bomb::handle_NowExploding(Board& board)
{
    m_warningRobot = false;
    m_time--;
    set_explodingLocation(board);
    for (int i = 0; i < m_explodingLocation.size(); i++)
    {
        print(m_explodingLocation.at(i), '*');
        if (board.isRobot(m_explodingLocation.at(i)))
            m_warningRobot = true;
    }
    return m_explodingLocation;

}
//-------------------------------------
vector<Location> Bomb::handleExploded(Board &board)
{
    deletePrinting(board);
    return m_explodingLocation;
}
//-------------------------------------
void Bomb::deletePrinting(Board& board)
{
for (int i = 0; i < m_explodingLocation.size(); i++)
    {
        print(m_explodingLocation.at(i), ' ');
        board.setLocation(m_explodingLocation.at(i), m_explodingLocation.at(i), ' '); //to delete rock
    }

}


void Bomb::set_explodingLocation(Board& board)
{
   m_explodingLocation.push_back(m_location);
   Location up = Location{m_location.row-1,m_location.col};
   Location down = Location{ m_location.row +1,m_location.col };
   Location right = Location{ m_location.row ,m_location.col+1 };
   Location left = Location{ m_location.row ,m_location.col-1 };
    
   if (board.isInLevel(up) && !board.isWall(up) && !board.isExitDoor(up))
       m_explodingLocation.push_back(up);
       
   if (board.isInLevel(down) && !board.isWall(down) && !board.isExitDoor(down))
       m_explodingLocation.push_back(down);
       
   if (board.isInLevel(right) && !board.isWall(right) && !board.isExitDoor(right))
        m_explodingLocation.push_back(right);
      
   if (board.isInLevel(left) && !board.isWall(left) && !board.isExitDoor(left))
       m_explodingLocation.push_back(left);
       
}

