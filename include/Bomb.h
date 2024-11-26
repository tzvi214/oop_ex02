#pragma once
#include "Location.h"

class Bomb 
{
public:
    Bomb(const Location& location, int time =5 );

    int getTime() const;             
    void setTime(int time);
    bool isExploding() const;  
    bool isExploded() const;
    void renwTime();
    Location getLocation() { return m_location; }
    int showTime() {return m_time ; }

private:
    Location m_location;             
    int m_time;      
};
