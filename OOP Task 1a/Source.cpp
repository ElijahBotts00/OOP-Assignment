#include "raylib.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    InitWindow(600, 600, "SNAKE");
    SetTargetFPS(60);

    Game game;
    game.Setup();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        
        if (game.IsRunning())
        {
            /// <summary>
            /// Uses constant loop of game running to constantly update position of the snake in the direction of key input
            /// On arrow key press direction is updated.
            /// ---Fergus
            /// </summary>
            game.UpdatePossition();
            if (IsKeyPressed(KEY_RIGHT))  game.UpdateDirection(KEY_RIGHT);
            if (IsKeyPressed(KEY_LEFT))   game.UpdateDirection(KEY_LEFT);
            if (IsKeyPressed(KEY_UP))     game.UpdateDirection(KEY_UP);
            if (IsKeyPressed(KEY_DOWN))   game.UpdateDirection(KEY_DOWN);
            std::this_thread::sleep_for(125ms);
        }
        else
        {
            DrawText("TODO: Why did the game end?", 610, 10, 20, LIGHTGRAY);
        }

        const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));

        const auto grid = game.PrepareGrid();

        for (int x = 0; x < SIZE; x++)
        {
            for (int y = 0; y < SIZE; y++)
            {
                int xPosition = x * cellSize;
                int yPosition = y * cellSize;

                switch (grid[y][x])
                {
                    case FLOOR:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN); break;
                    case WALL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK); break;
                    case PLAYER: DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);     break;
                    case APPLE:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);     break;
                    default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
                }

                // draw lines around each tile, remove this if you don't like it!
                DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}