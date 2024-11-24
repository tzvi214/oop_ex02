#pragma once
#include "Location.h"
#include <fstream>
#include <iostream>
#include <string>

class Board {
public:
    Board(const std::string& fileName);
    ~Board();

    void print() const;
    char** getLevel() const { return m_level; }
   int getRowCount() const { return m_rowCount; }
    int getColCount() const { return m_colCount; }
    Location getRobotLocation() const { return m_robotLocation; }//

private:
    std::string m_fileName;
    char** m_level = nullptr;
    int m_rowCount = 0;
    int m_colCount = 0;
    Location m_robotLocation;//
    void load(const std::string& filename);

    void freeMemory();
};
