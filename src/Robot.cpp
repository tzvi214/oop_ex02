#include "Robot.h"
#include "io.h"
#include "Board.h"
#include <conio.h>
Robot::Robot(Location& location)
	:m_location {location}, m_first_location{location}, m_drop_bomb{false}
	, m_touch{false}, m_life{5}
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

Location Robot::get_first_location()
{
	return m_first_location;
}

void Robot::print(const Location& location)
{
	Screen::setLocation(location);
	cout << '/';
}

bool Robot::check_if_legal_move( Board & board)
{
	return (board.isInLevel(m_location) );
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

		if (move == Keys::B)
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

				deleteOld_location(m_location);
				setLocation(newLocation);
				print(newLocation);
				endTurn = true;
			}
			else if(_getch() == (int)' ') // צריך שיאשר על ידי הקשה על רווח
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

bool Robot::touch()
{
	return m_touch;
}

