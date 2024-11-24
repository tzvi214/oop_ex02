#include "Board.h"
#include "Robot.h"
#include "io.h"
#include "Location.h"
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
    Board board("level01.txt");
   // board.load("level01.txt");
    // הדפסת הלוח
    board.print();

    // יצירת רובוט
    Location robotLocation = board.getRobotLocation();
    Robot robot(robotLocation);

    //// תנועת הרובוט
    int row = robotLocation.row;
    int col = robotLocation.col;
    char** level = board.getLevel();
    int rowCount = board.getRowCount();
    int colCount = board.getColCount();

    for (int i = 0; i < 10; i++) {
        if (_getch() == Keys::SPECIAL_KEY) {
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
                robot.current_location(Location(row, col));
            }

            // הדפסת הלוח מחדש
           
            board.print();
        }
    }

    return 0;
}
