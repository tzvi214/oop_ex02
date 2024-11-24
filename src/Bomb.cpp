#include "Bomb.h"

Bomb::Bomb(const Location& location, int time)
    : m_location(location), m_time(time) 
{}

int Bomb::getTime() const 
{
    return m_time;
}

void Bomb::setTime(int time)
{
    m_time = time;
}

bool Bomb::isExploding() const 
{
    return (m_time == 0);
}
