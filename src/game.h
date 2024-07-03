#include "grid.h"
#include "blocks.cpp"

#ifndef __GAME_H__
#define __GAME_H__

class Game
{
public:
    bool gameOver;
    int score;

    Game();

    void Draw();
    void HandleInput();
    void MoveBlockDown();

private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;

    bool IsBlockOutiside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
};

#endif // __GAME_H__