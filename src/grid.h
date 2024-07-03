#include <vector>
#include "raylib.h"

#ifndef GRID_H
#define GRID_H

const int NB_COLUMNS = 10;
const int NB_ROWS = 20;
const int CELL_SIZE = 30;

class Grid
{
public:
    int grid[NB_ROWS][NB_COLUMNS] = {};

    Grid();
    
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();

private:
    std::vector<Color> colors;
    
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int nbRows);
};

#endif //GRID_H