#pragma once
#include "Location.h"
#include <fstream>
#include <iostream>
#include <string>
#include"Guard.h"
#include <vector>

using namespace std;

class Board {
public:
    Board(const std::string& fileName);
    ~Board();

    void print() const;
    char** getLevel() const { return m_level; }
   int getRowCount() const { return m_rowCount; }
    int getColCount() const { return m_colCount; }
    Location getRobotLocation() const { return m_robotLocation; }
    vector <Guard> get_guardMatrix() const { return m_guardsMatrix; }
private:
    string m_fileName;
    char** m_level = nullptr;
    int m_rowCount = 0;
    int m_colCount = 0;
    Location m_robotLocation;
    void load(const std::string& filename);
    vector <Guard> m_guardsMatrix;

    void freeMemory();
};
