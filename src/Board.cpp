#include "Board.h"
#include <io.h>
using namespace std;

Board::Board(const std::string& fileName)
    : m_fileName(fileName) 
       
{
    load(fileName);
}

Board::~Board() {
    freeMemory();
}

void Board::load(const std::string& filename) {
    auto file = std::ifstream(filename); // שימוש ב-auto כמו בקוד שלך
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    // חישוב מספר השורות והעמודות
    m_rowCount = 1;
    m_colCount = 0;

    while (file.get() != '\n') {
        m_colCount++;
    }

    file.clear(); // מוודאים שאין שגיאות בסטרים
    file.seekg(0, std::ios::beg); // מחזירים את הקריאה להתחלה

    char c;
    while (file >> c) {
        if (file.peek() == '\n') {
            m_rowCount++;
        }
    }

    // הקצאת זיכרון למערך הדו-ממדי
    m_level = new char* [m_rowCount];
    for (int i = 0; i < m_rowCount; i++) {
        m_level[i] = new char[m_colCount];
    }

    file.clear(); // מוודאים שאין שגיאות בסטרים
    file.seekg(0, std::ios::beg); // מחזירים את הקריאה להתחלה

    // מילוי המערך בתוכן הקובץ
    int row = 0, col = 0;
    for (int i = 0; i < m_rowCount && !file.eof(); i++) {
        for (int j = 0; j < m_colCount && !file.eof(); j++) {
            file >> std::noskipws >> c;
            if (c == '/') {
                m_robotLocation = Location(i, j);
                row = i;
                col = j;
            }

            if (c == '\n') {
                j--; // דילוג על ירידות שורה
            } else {
                m_level[i][j] = c;
            }
        }
    }
}

void Board::print() const 
{
    Screen::resetLocation();
    for (int i = 0; i < m_rowCount; i++) 
    {

        for (int j = 0; j < m_colCount; j++) 
        {
            cout << m_level[i][j];
        }
        cout << endl;
    }
}

void Board::freeMemory() {
    for (int i = 0; i < m_rowCount; i++) {
        delete[] m_level[i];
    }
    delete[] m_level;
}
