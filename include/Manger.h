#pragma once
#include <vector>
#include "Guard.h"
//#include "Robot.h"

class Manger
{

public:
    void ran();

  private:
     std:: vector <Guard> m_guardsMatrix;
    // Robot m_robot;
};

