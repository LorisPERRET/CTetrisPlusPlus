#include "game.h"
#include <random>
#include <iostream>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }

    int index = rand() % blocks.size();
    Block block = blocks[index];

    blocks.erase(blocks.begin() + index);

    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw(11, 11);
    switch (nextBlock.id)
    {
    case 3:
        nextBlock.Draw(255, 290);
        break;
    case 4:
        nextBlock.Draw(255, 280);
        break;
    
    default:
        nextBlock.Draw(270, 270);
        break;
    }
}

void Game::HandleInput()
{
    int key = GetKeyPressed();

    if (gameOver && key != 0)
    {
        gameOver = false;
        Reset();
    }
    
    switch (key)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    
    case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        break;
    
    case KEY_SPACE:
        RotateBlock();
        break;
    
    default:
        break;
    }
}

void Game::MoveBlockLeft()
{
    if (gameOver) return;

    currentBlock.Move(0, -1);
    if (IsBlockOutiside() || !BlockFits())
    {
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight()
{
    if (gameOver) return;

    currentBlock.Move(0, 1);
    if (IsBlockOutiside() || !BlockFits())
    {
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown()
{
    if (gameOver) return;

    currentBlock.Move(1, 0);
    if (IsBlockOutiside() || !BlockFits())
    {
        currentBlock.Move(-1, 0);
        LockBlock();
    }
}

bool Game::IsBlockOutiside()
{
    for (Position item: currentBlock.GetCellPositions()) 
    {
        if (grid.IsCellOutside(item.row, item.column)) 
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock() 
{
    if (gameOver) return;

    currentBlock.Rotate();
    if (IsBlockOutiside() || !BlockFits())
    {
        currentBlock.UndoRotation();
    }
}

void Game::LockBlock() 
{
    for (Position item: currentBlock.GetCellPositions())
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }

    currentBlock = nextBlock;

    if (!BlockFits()) {
        gameOver = true;
    }

    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
}

bool Game::BlockFits()
{
    for (Position item: currentBlock.GetCellPositions())
    {
        if (!grid.IsCellEmpty(item.row, item.column)) 
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch (linesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDownPoints;
}
