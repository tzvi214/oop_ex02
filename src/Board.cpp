#include <Board.h>


Board::Board(const std::string& fileName) :m_fileName{ fileName }, m_robotLoc{ 0,0 }, m_numRow{ 0 }, m_numCol{ 0 }
             , m_openFile{ true }, m_exitDoor{0,0}
{
    auto file = ifstream(fileName);
    if (!file) {
        std::cerr << "Error: Cannot open file " << fileName << endl;
       m_openFile = false;
        return;
    }
    
    string line;

    while (getline(file, line)) // reading file.
    {
        updateLevel(line);
        m_numRow++;
        m_numCol = static_cast<int>(line.size());// Convert size_t to int explicitly to avoid potential data loss warning
    }
    m_numRow--;

}

int Board::getRows()
{
    return m_numRow;
}

void Board::updateLevel(const string line)
{
    m_level.push_back(line);
    for (int col = 0; col < line.size(); col++)
    {
        Location loc(m_numRow, col);
        if (line[col] == '/') m_robotLoc = loc;
        else if (line[col] == '!') m_guardLoc.push_back(loc);
        else if (line[col] == 'D') m_exitDoor = loc;
    }
}

void Board::print() const
{
    for (int i = 0; i < m_level.size(); i++)
        cout << m_level[i] << endl;
}

bool Board::isInLevel(Location loc) const
{
    return (loc.row >= 0 && loc.row <= m_numRow && loc.col >= 0 && loc.col <= m_numCol);
}


Location Board::getRobotFirstLoc() const
{
    return m_robotLoc;
}

vector<Location> Board::getVecGuardFirstLoc() const
{
    return m_guardLoc;
}

void Board::printScoreAndLife(int score, int life) const
{
    Screen::setLocation(Location(m_numRow + 3, 0));
    std::cout << "The score is:" << score << "  ,The life is:" << life;
}

bool Board::isExitDoor(Location& loc) const
{
    return (loc.col == m_exitDoor.col && loc.row == m_exitDoor.row);
}

void Board::setLocation(Location oldLoc, Location newLoc, char c)
{
    if (newLoc.col == m_exitDoor.col && newLoc.row == m_exitDoor.row)
        c = 'D';
    else if (oldLoc.col == m_exitDoor.col && oldLoc.row == m_exitDoor.row)
    {
        m_level[oldLoc.row][oldLoc.col] = 'D';
        m_level[newLoc.row][newLoc.col] = c;
        return;
    }

    m_level[oldLoc.row][oldLoc.col] = ' ';
    m_level[newLoc.row][newLoc.col] = c;
  }

bool Board::isWall(Location loc) const
{
    return m_level[loc.row][loc.col] == '#';
}

bool Board::isSpace(Location loc) const
{
    return m_level[loc.row][loc.col] == ' ';
}

bool Board::isRobot(Location loc)const
{
    return m_level[loc.row][loc.col] == '/';
}

bool Board::isRock(Location loc)const
{
    return m_level[loc.row][loc.col] == '@';
}

bool Board::isDoor(Location loc)const
{
    return (loc.col == m_exitDoor.col && loc.row == m_exitDoor.row);
}
bool Board::isGuard(Location loc) const
{
    return m_level[loc.row][loc.col] == '!';
}

//vector<Location> board::getVecRock() const
//{
//    return m_rockLoc;
//}