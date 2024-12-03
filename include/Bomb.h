#pragma once
#include "Location.h"
#include <vector>
#include "Board.h"
using namespace std;

class Bomb 
{
public:
    Bomb(const Location& location, int time = 6);// Because  the first time he takes one off.
    void deleteData(Board& board);
    int getTime() const;             
    bool isExploding() const;  
    bool isExploded() const;
    void renewTime();
    vector <Location> handle_NowExploding(Board& board);
    Location getLocation() const { return m_location; }
    vector <Location> handleExploded(Board& board);
    
    bool warningRobot() const {return m_warningRobot; }
private:
    Location m_location;   
    vector <Location> m_explodingLocation;
    int m_time;     
    bool m_warningRobot;
    void deletePrinting(Board& board);
    void print(Location& location, char c);
    void set_explodingLocation(Board& board);

};
