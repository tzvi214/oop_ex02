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

    Location robot_location = board.getRobot_ferst_Location();
    Robot robot(robot_location);

    vector <Guard> guards_location = board.get_gard_ferst_location();
    vector <Bomb> bombs_location;



    //// תנועת הרובוט
    int row = robot_location.row;
    int col = robot_location.col;
    char** level = board.getLevel();
    int rowCount = board.getRowCount();
    int colCount = board.getColCount();

    for (int i = 0; i < 10; i++)
    {

        if (_getch() == Keys::SPECIAL_KEY)
        {
            int move = _getch();

            // עדכון מיקום חדש
            int newRow = row, newCol = col;
            if (move == SpecialKeys::UP && row > 0) newRow = row - 1;
            else if (move == SpecialKeys::DOWN && row < rowCount - 1) newRow = row + 1;
            else if (move == SpecialKeys::LEFT && col > 0) newCol = col - 1;
            else if (move == SpecialKeys::RIGHT && col < colCount - 1) newCol = col + 1;

            // עדכון הלוח
            if (level[newRow][newCol] == ' ') {
                level[row][col] = ' ';
                level[newRow][newCol] = '/';
                row = newRow;
                col = newCol;
                robot.setLocation(Location(row, col));
            }

            // הדפסת הלוח מחדש

            board.print();
        }

        else //its a bomb
            bombs_location.push_back(Bomb(robot.get_location()));



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
        board.print();
    }
}
