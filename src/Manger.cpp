#include "Board.h"
#include "io.h"
#include "Location.h"
#include <conio.h>
#include"Rock.h"
#include"ExitDoor.h"
#include"Bomb.h"
#include"Wall.h"
#include"Guard.h"
#include"Space.h"
#include <iostream>
#include <vector>
#include "Manger.h"
#include <thread>
#include <chrono>
using namespace std::chrono_literals;




void Manger::ran()
{
    int counter = 1;
    while (true) // A loop that opens all files.
    {
        string fileName = std::string("level") + (counter < 10 ? "0" : "") + std::to_string(counter) + ".txt";

        Board board(fileName);
        if (!board.getIsFileOpen())
        {
            system("cls");
            std::cout << "No more levels to load. Exiting..." << std::endl;
            std::cin.get(); 
            return; // Exit the loop if the file couldn't be opened
           

        }

        system("cls");

        board.print();
        ranFile(board);
      
        counter++; // add the counter.
    }


}
//-----------------------------------------------
void Manger::ranFile(Board& board)
{
   
    Location robot_location = board.getRobotFirstLoc();
    Robot robot(robot_location);
    board.printScoreAndLife(m_score,m_life);


    for (int i = 0; i < board.getVecGuardFirstLoc().size(); i++)
    {
        m_guardsMatrix.push_back(board.getVecGuardFirstLoc().at(i));
    }

  

 while(!robot.fishnetLevel())
  {    
     robot.play(board);
      
     if (robot.dropBomb())
       m_bombs_location.push_back(Bomb(robot.get_location()));
     if (robot.touch())
     {
         restart(robot, board);
         continue;
     }
     if (robot.fishnetLevel())
     {
         m_score += 25;
         board.printScoreAndLife(m_score, m_life);
         Screen::resetLocation();
         system("cls");
        std::cout << "Congratulations, you have completed the step," << std::endl 
                  << "press enter to move to the next step.";
         std::cin.get();
         break;// return;
     }

     bombs(board, robot);
 
    for (int i = 0; i < m_guardsMatrix.size(); i++)
    {
        m_guardsMatrix[i].move(board);
        if (m_guardsMatrix.at(i).getTouch())
        {
            restart(robot, board);
            break;
        }
        std::this_thread::sleep_for(50ms);
    }

  }

}

//-----------------------------------------------
void Manger::bombs(Board& board, Robot& robot)
{
  for (int i = 0; i < m_bombs_location.size(); i++)
  {
      if (m_bombs_location.at(i).isExploded())
      {
          vector <Location> indexOfExploded = m_bombs_location.at(i).handleExploded(board);
          for (int k = 0; k < indexOfExploded.size(); k++)
          {
              for (int j = 0; j < m_guardsMatrix.size(); j++)
                  if (equal(indexOfExploded.at(k), m_guardsMatrix.at(j).get_location()))
                  {
                      board.setLocation(m_guardsMatrix.at(j).get_location(), m_guardsMatrix.at(j).get_location(),' ');
                      m_guardsMatrix.erase(m_guardsMatrix.begin() + j);
                      m_score += 3;
                      board.printScoreAndLife(m_score, m_life);
                      j--;
                  }
              if (equal(robot.get_location(), indexOfExploded.at(k)))
                  restart(robot, board);
          }

          m_bombs_location.erase(m_bombs_location.begin());
          i--;
       }
      else if (m_bombs_location.at(i).isExploding())
      {
          m_bombs_location.at(i).handle_NowExploding(board);
          if (m_bombs_location.at(i).warningRobot())
              robot.touchingBomb();

      }
      else
      {
          m_bombs_location.at(i).renewTime();
          if (equal(m_bombs_location.at(i).getLocation(), robot.get_location()))
              robot.touchingBomb();

      }
  }
}
//-----------------------------------------------
void Manger::restart(Robot& robot, Board& board)
{
    m_life--;
    board.setLocation(robot.get_location(), robot.get_first_location(),'/');
    robot.initialization();
    board.printScoreAndLife(m_score, m_life);
  //  m_bombs_location.clear();
    for (int i = 0; i < m_guardsMatrix.size(); i++)
    {
        board.setLocation(m_guardsMatrix.at(i).get_location(), m_guardsMatrix.at(i).get_first_location(), '!');
        m_guardsMatrix.at(i).initialization();

    }
}
//-----------------------------------------------
bool Manger::equal(const Location& loc1, const Location& loc2)
{
    return (loc1.col == loc2.col && loc1.row == loc2.row);
}