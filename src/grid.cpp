#include "grid.h"
#include <iostream>
#include "raylib.h"
#include "colors.h"

Grid::Grid() 
{
    colors = GetCellColors();
    Initialize();
}

void Grid::Initialize() 
{
    for (int row = 0; row < NB_ROWS; row++) 
    {
        for (int column = 0; column < NB_COLUMNS; column++) 
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print()
{
    for (int row = 0; row < NB_ROWS; row++) 
    {
        for (int column = 0; column < NB_COLUMNS; column++) 
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for (int row = 0; row < NB_ROWS; row++) 
    {
        for (int column = 0; column < NB_COLUMNS; column++) 
        {
            int cell = grid[row][column];
            
            DrawRectangle(column * CELL_SIZE + 11, row * CELL_SIZE + 11, CELL_SIZE - 1, CELL_SIZE - 1, colors[cell]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < NB_ROWS && column >= 0 && column < NB_COLUMNS) return false;
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0) return true;
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;

    for (int row = NB_ROWS - 1; row >= 0; row--) 
    {
        std::cout << row << std::endl;
        std::cout << IsRowFull(row) << std::endl;
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        } 
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }

    return completed;
}

bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < NB_COLUMNS; column++) 
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int column = 0; column < NB_COLUMNS; column++) 
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int nbRows)
{
    for (int column = 0; column < NB_COLUMNS; column++) 
    {
        grid[row + nbRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
