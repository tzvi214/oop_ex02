#include "Robot.h"
#include "io.h"
#include "Board.h"
#include <conio.h>
Robot::Robot(Location& location)
	:m_location {location}, m_first_location{location}, m_drop_bomb{false}
	, m_touch{false}, m_finshed{false}
{
}


void Robot::setLocation(Location location)
{
	m_location = location;
}

Location Robot::get_location()
{
	return m_location;
}

void Robot::print(const Location& location, char c)
{
	Screen::setLocation(location);
	cout << c;
}


void Robot::deleteOld_location(Location& location)
{
	Screen::setLocation(location);
	cout << ' ';
}

void Robot::move(Location& location)
{
	m_location = location;
}
void Robot::play(Board& board)
{

	set_dropBomb(false);

	int newRow;
	int newCol;
	bool endTurn = false;

	int move;

	while (!endTurn)
	{
		move = _getch();
		newRow = m_location.row;
		newCol = m_location.col;

		if (move == Keys::b)
		 {
			set_dropBomb(true);
			endTurn = true;
		 }

		else if (move == Keys::SPECIAL_KEY)
		{
			move = _getch();

			if (move == SpecialKeys::UP) //newRow = row - 1;
				newRow--;
			else if (move == SpecialKeys::DOWN)// newRow = row + 1;
				newRow++;
			else if (move == SpecialKeys::LEFT) //newCol = col - 1;
				newCol--;
			else if (move == SpecialKeys::RIGHT) //newCol = col + 1;
				newCol++;

			Location newLocation(newRow, newCol);
			if (board.isInLevel(newLocation) && !board.isWall(newLocation)
				                            && !board.isRock(newLocation))
			{
				if (board.isGuard(newLocation))
				{
					m_touch = true;
					break;
				}
				if (board.isDoor(newLocation))
				{
					m_finshed = true;
					endTurn = true;
					break;
				}
				board.setLocation(m_location, newLocation, '/');
				deleteOld_location(m_location);
				setLocation(newLocation);
				print(newLocation);
				endTurn = true;
				
			}
			else if(_getch() == Keys::SPACE) // ���� ����� �� ��� ���� �� ����
				endTurn = true;
		
		}
		
	}
}

void Robot::set_dropBomb(bool flag)
{
	m_drop_bomb = flag;
}

bool Robot::dropBomb()
{
	return m_drop_bomb;
}

void Robot::warningPrint() const
{
	Screen::setLocation(m_location);
	cout << '%';

}

void Robot::initialization()
{
	Screen::setLocation(m_location);
	cout << ' ';
	m_location = m_first_location;
	print(m_location);
	m_touch = false;
}

