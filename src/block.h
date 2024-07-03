#include <vector>
#include <map>
#include "raylib.h"
#include "position.h"
#include "colors.h"

#ifndef __BLOCK_H__
#define __BLOCK_H__

class Block
{
public:
    int id;
    std::map<int, std::vector<Position>> cells;
    
    Block();

    void Draw(int offsetX, int offsetY);
    void Move(int row, int column);
    void Rotate();
    void UndoRotation();
    std::vector<Position> GetCellPositions();

private:
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};

#endif // __BLOCK_H__