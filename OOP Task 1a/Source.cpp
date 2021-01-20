#include "raylib.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "Menu.h"


using namespace std;

typedef enum {
    STORAGE_POSITION_SCORE = 0,
    STORAGE_POSITION_HISCORE = 1
} StorageData;

int main()
{
    //string score;
    int hiScore = 0;
    InitWindow(900, 600, "OOP Assignment 1");
    SetTargetFPS(60);
    Game game;
    Menu menu;
    game.Setup();

    while (!WindowShouldClose())
    {
        if (menu.whichMenu() == 1)
        {
            menu.predraw();
        }
        if (menu.whichMenu() == 2)
        {
            menu.predraw2();
        }
        if (menu.whichMenu() == 3)
        {
            menu.predraw3();
        }
        BeginDrawing();
        if (menu.whichMenu() != 0)
        {
            if (menu.whichMenu() == 1)
            {
                menu.drawmenu();
            }
            if (menu.whichMenu() == 2)
            {
                menu.drawmenu2();
            }
            if (menu.whichMenu() == 3)
            {
                menu.drawmenu3();
            }
            if (menu.whichMenu() == 4)
            {
              
                CloseWindow();
                return 0;
            }
        }
        else
        {
            ClearBackground(DARKGRAY);

            if (game.IsRunning())
               
            {
                game.cname = menu.name;
                
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
                DrawText(FormatText("Name: %s", name), 610, 10, 20, MAROON);
                DrawText(TextFormat("SCORE: %i", game.score), 610, 30, 30, MAROON);
            }
            else
            {
                DrawText(FormatText("Name: %s", name), 610, 10, 20, MAROON);
                DrawText(TextFormat("SCORE: %i", game.score), 610, 30, 30, MAROON);
                DrawText(game.get_end_reason().c_str(), 610, 60, 20, LIGHTGRAY); //raylib
                
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
                    case FLOOR:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN);break;
                    case WALL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);    break;
                    case PLAYER: DrawRectangle(xPosition, yPosition, cellSize, cellSize, PURPLE);   break;
                    case TAIL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, BROWN);    break;
                    case APPLE:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);      break;
                    default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
                    
                    }

                    // draw lines around each tile, remove this if you don't like it!
                    DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
                }
            }
        }
        EndDrawing();
     
  
    }

        game.UpdateScore();

    CloseWindow();
    return 0;
}