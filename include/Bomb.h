#pragma once
#include "Location.h"
#include <vector>
#include "Board.h"
using namespace std;

class Bomb 
{
public:
    Bomb(const Location& location, int time =5);

    int getTime() const;             
    bool isExploding() const;  
    bool isExploded() const;
    void renewTime();
    void print(Location &location, char c);
    void handle_NowExploding(Board& board);
    void set_explodingLocation(Board& board);
    Location getLocation() { return m_location; }
    vector <Location> handleExploded();

private:
    Location m_location;   
    vector <Location> m_explodingLocation;
    int m_time;     

    
};
