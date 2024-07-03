#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

void DrawUI(Font font, bool gameOver, int score)
{
    ClearBackground(darkBlue);

    // Score
    DrawTextEx(font, "Score", {360, 15}, 38, 2, WHITE);
    DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

    // Score Text
    char scoreText[10];
    sprintf(scoreText, "%d", score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

    DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

    // GameOver
    if (gameOver) {
        DrawTextEx(font, "Game Over", {320, 450}, 38, 2, WHITE);
    }

    // Next block    
    DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
    DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
}

void Play()
{
    Font font = LoadFontEx("../assets/Font/Robot Crush.ttf", 64, 0, 0);
    
    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();

        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();

        DrawUI(font, game.gameOver, game.score);
        game.Draw();

        EndDrawing();
    }
}

int main()
{
    
    InitWindow(500, 620, "C Tetris ++");
    SetTargetFPS(60);

    Play();

    CloseWindow();
    
    return 0;
}