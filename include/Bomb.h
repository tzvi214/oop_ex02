#pragma once
#include "Location.h"

class Bomb 
{
public:
    Bomb(const Location& location, int time);

    int getTime() const;             
    void setTime(int time);
    bool isExploding() const;        

private:
    Location m_location;             
    int m_time;              
};
