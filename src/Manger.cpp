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
    Location robot_location = board.getRobot_first_Location();
    Robot robot(robot_location);

    m_guardsMatrix = board.get_guard_first_location();
    vector <Bomb> bombs_location;


    char** level = board.getLevel();
   

    for (int i = 0; i < 10; i++)
    {



       robot.move(board, manger);
        
       if (robot.dropBomb())
       {
           bombs_location.push_back(Bomb(robot.get_location()));
       }

       for (int i = 0; i < bombs_location.size(); i++)
       {


       }

        //int size = bombs_location.size();
        //for (int i = 0; i < size; i++)
        //{
        //    if (bombs_location.at(i).isExploded())
        //    {
        //        level[bombs_location.at(i).getLocation().row][bombs_location.at(i).getLocation().col] = ' ';
        //        bombs_location.erase(bombs_location.begin());
        //        i--;
        //        size--;
        //        continue;
        //    }

        //    else if (bombs_location.at(i).isExploding())
        //        level[bombs_location.at(i).getLocation().row][bombs_location.at(i).getLocation().col] = '*';


        //    else
        //        level[bombs_location.at(i).getLocation().row][bombs_location.at(i).getLocation().col] = '0' + bombs_location.at(i).getTime();

        //    bombs_location.at(i).renwTime();

        //}
       
    }
}
