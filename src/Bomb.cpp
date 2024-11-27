#include "Bomb.h"
#include <io.h>
#include <iostream>

Bomb::Bomb(const Location& location, int time)
    : m_location(location), m_time(time)
{}

int Bomb::getTime() const 
{
    return m_time;
}

bool Bomb::isExploding() const 
{
   
        return (m_time == 0);

}

bool Bomb::isExploded() const
{
    return (m_time < 0);
}

void Bomb::renewTime()
{
   
    m_time--;
   
}

void Bomb::print(Location& location, char c)
{
    Screen::setLocation(location);
    std::cout << c;
}

void Bomb::handle_NowExploding(Board& board)
{
    set_explodingLocation(board);
    for (int i = 0; i < m_explodingLocation.size(); i++)
    {
        print(m_explodingLocation.at(i), '*');
    }

}

vector<Location> Bomb::handleExploded()
{
    for (int i = 0; i < m_explodingLocation.size(); i++)
    {
        print(m_explodingLocation.at(i), ' ');
    }
    return m_explodingLocation;
}


void Bomb::printTime()
{
    print(m_location, (char)m_time);
}

void Bomb::set_explodingLocation( Board& board)
{
   m_explodingLocation.push_back(m_location);
   Location up = Location{m_location.row-1,m_location.col};
   Location down = Location{ m_location.row +1,m_location.col };
   Location right = Location{ m_location.row - 1,m_location.col };
   Location left = Location{ m_location.row + 1,m_location.col };
    
   if (board.isInArray(up) && !board.isWall(up))
        m_explodingLocation.push_back(up);
    
   if (board.isInArray(down) && !board.isWall(down))
        m_explodingLocation.push_back(down);
    
   if (board.isInArray(right) && !board.isWall(right))
        m_explodingLocation.push_back(right);
    
   if (board.isInArray(left) && !board.isWall(left))
        m_explodingLocation.push_back(left);

}

