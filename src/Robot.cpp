#include "Robot.h"
#include "io.h"
#include "Board.h"
#include <conio.h>
Robot::Robot(Location& location)
	:m_location {location}, m_first_location{location}, m_drop_bomb{false}
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

bool Robot::check_if_ligel_move( Board & board)
{
	return (board.isInArry(m_location) && board.is_legaleMove(m_location));
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
void Robot::move(Board& board, Manger& manager)
{
	
	
	int row = m_location.row;
	int col = m_location.col;
    int move = _getch();

	if (move == Keys::B)
		set_dropBomb(true);

	else if (move == Keys::SPECIAL_KEY)
	{

			move = _getch();
			if (move == SpecialKeys::UP) //newRow = row - 1;
			{
				if (check_if_ligel_move(board))
				{
					deleteOld_location(m_location);
					row--;

					setLocation(Location(row, col));
					print(Location(row, col));

				}
				else // צריך שיאשר על ידי הקשה על רווח
				{
				}
			}

			else if (move == SpecialKeys::DOWN)// newRow = row + 1;
			{
				if (check_if_ligel_move(board))
				{
					deleteOld_location(m_location);
					row++;

					setLocation(Location(row, col));
					print(Location(row, col));

				}
				else // צריך שיאשר על ידי הקשה על רווח
				{
				}

			}
			else if (move == SpecialKeys::LEFT) //newCol = col - 1;
			{
				if (check_if_ligel_move(board))
				{
					deleteOld_location(m_location);
					col--;

					setLocation(Location(row, col));
					print(Location(row, col));

				}
				else // צריך שיאשר על ידי הקשה על רווח
				{
				}
			}
			else if (move == SpecialKeys::RIGHT) //newCol = col + 1;
			{
				if (check_if_ligel_move(board))
				{
					deleteOld_location(m_location);
					col++;
					setLocation(Location(row, col));
					print(Location(row, col));


				}
				else // צריך שיאשר על ידי הקשה על רווח
				{
				}
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

