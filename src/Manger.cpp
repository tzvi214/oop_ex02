#include "Board.h"
#include "io.h"
#include "Location.h"
#include <conio.h>
#include"Rock.h"
#include"ExitDoor.h"
#include"Bomb.h"
#include"Wall.h"
#include"Robot.h"
#include"Guard.h"
#include"Space.h"
#include <iostream>
#include <vector>
#include "Manger.h"


void Manger::ran()
{
    Board board("level01.txt");

    board.print();
    Manger manger;
    Location robot_location = board.getRobotFirstLoc();
    Robot robot(robot_location);


    for (int i = 0; i < board.getVecGuardFirstLoc().size(); i++)
    {
        m_guardsMatrix.push_back(board.getVecGuardFirstLoc().at(i));
    }

    vector <Bomb> bombs_location;



    for (int i = 0; i < 15; i++)
    {

       robot.play(board);
        
       if (robot.dropBomb())
       {
           bombs_location.push_back(Bomb(robot.get_location()));
       }

       for (int i = 0; i < bombs_location.size(); i++)
       {
           if (bombs_location.at(i).isExploded())
           {

               vector <Location> indexOfExploded = bombs_location.at(i).handleExploded();
               // כאן צריך לבדוק האם אוביקטים התפצצו
               bombs_location.erase(bombs_location.begin());
               i--;
           }
           else if (bombs_location.at(i).isExploding())
           {
               bombs_location.at(i).handle_NowExploding(board);

           }
           else
           {
               bombs_location.at(i).renewTime();
           }

       }
  
    }
}
