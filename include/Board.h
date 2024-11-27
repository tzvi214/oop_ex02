#pragma once
#include "Location.h"
#include <fstream>
#include <iostream>
#include <string>
#include"Guard.h"
#include <vector>
#include "io.h"
using namespace std;

class Board {
public:
    Board(const std::string& fileName);
    ~Board();

    void print() const;
    char** getLevel() const { return m_level; }
   int getRowCount() const { return m_rowCount; }
    int getColCount() const { return m_colCount; }
    Location getRobot_first_Location() const { return m_robotLocation; }
    vector <Guard> get_guard_first_location() const { return m_guardsMatrix; }
    bool isWall(const Location& location);
    bool isInArray(const Location& location);
   
private:
    string m_fileName;
    int m_rowCount ;
    int m_colCount ;
    Location m_robotLocation;
    char** m_level ;
    vector <Guard> m_guardsMatrix;

    void load(const string& filename);
    void freeMemory();
};
