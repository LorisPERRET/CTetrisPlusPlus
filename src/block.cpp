#include "block.h"
#include "grid.h"

Block::Block()
{
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY) 
{
    std::vector<Position> tiles = GetCellPositions(); 

    for (Position pos : tiles)
    {
        DrawRectangle(
            pos.column * CELL_SIZE + offsetX, 
            pos.row * CELL_SIZE + offsetY, 
            CELL_SIZE - 1,
            CELL_SIZE - 1, 
            colors[id]
        );
    }      
}

void Block::Move(int row, int column)
{
    rowOffset += row;
    columnOffset += column;
}

void Block::Rotate() 
{
    rotationState++;
    if (rotationState == cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRotation() 
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;

    for (Position pos : tiles)
    {
        Position newPos = Position(pos.row + rowOffset, pos.column + columnOffset);
        movedTiles.push_back(newPos);
    };

    return movedTiles;
}