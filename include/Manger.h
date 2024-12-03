#pragma once
#include <vector>
#include "Guard.h"
#include <Bomb.h>
#include"Robot.h"



class Manger
{

public:
    void ran();
    void ranFile(Board& board);
    void restart(Robot& robot, Board &board);
   bool equal(const Location &loc1, const Location &loc2);//
   void bombs(Board &board, Robot &robot);
   
  private:
     std:: vector <Guard> m_guardsMatrix;
     std::vector <Bomb> m_bombsMatrix;
     int m_score = 0;
     int m_life = 5;
     bool eraseExplodedRobotAndGuards(Robot& robot, Board& board,std::vector<Location> & vec);
};


