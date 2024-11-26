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
    Location robot_location = board.getRobot_ferst_Location();
    Robot robot(robot_location);

   // vector <Guard> guards_location = board.get_gard_ferst_location();
    m_guardsMatrix = board.get_guard_ferst_location();
    vector <Bomb> bombs_location;


    char** level = board.getLevel();
   

    for (int i = 0; i < 10; i++)
    {



       robot.move(board, manger);
        
       if (robot.dropBomb())
       {
           bombs_location.push_back(Bomb(robot.get_location()));
       }


        int size = bombs_location.size();
        for (int i = 0; i < size; i++)
        {
            if (bombs_location.at(i).isExploded())
            {
                level[bombs_location.at(i).getLocation().row][bombs_location.at(i).getLocation().col] = ' ';
                bombs_location.erase(bombs_location.begin());
                i--;
                size--;
                continue;
            }

            else if (bombs_location.at(i).isExploding())
                level[bombs_location.at(i).getLocation().row][bombs_location.at(i).getLocation().col] = '*';


            else
                level[bombs_location.at(i).getLocation().row][bombs_location.at(i).getLocation().col] = '0' + bombs_location.at(i).showTime();

            bombs_location.at(i).renwTime();

        }
       
    }
}
