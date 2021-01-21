#include "raylib.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "Menu.h"


using namespace std;

int main()
{
    char option = 'U';
    InitWindow(900, 600, "OOP Assignment 1");
    SetTargetFPS(60);
mylabel:
    Game game;
    Menu menu;
    game.Setup();
    while (!WindowShouldClose())
    {
   
           switch (menu.whichMenu()) {
        case 1:
            menu.predrawmenu();
            break;
        case 2:
            menu.predrawngmenu();
            break;
        case 3:
            menu.predrawhsmenu();
            break;
        }
            if (menu.whichMenu() != 0)
            {
                switch (menu.whichMenu()) {
                case 1:
                    menu.drawmenu();
                    break;
                case 2:
                    menu.drawngmenu();
                    break;
                case 3:
                    menu.drawhsmenu();
                    break;
                case 4:
                    CloseWindow();
                    return 0;
                    break;
                case 5:
                    game.LoadGame();
                 
                    menu.mnum = 0;
                    break;
                }
            }
            else
            {
                ClearBackground(DARKGRAY);
                if (game.IsRunning())

                {
                    game.cname = menu.name;
                    if (game.conti == true)
                    {
                       
                    }


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
                    if (IsKeyPressed(KEY_S)) { game.SaveGame(); DrawText("GAME SAVED", 610, 60, 20, LIGHTGRAY); } 
                    DrawText(FormatText("Name: %s", menu.name), 610, 10, 20, MAROON);
                    DrawText(game.scores().c_str(), 610, 30, 30, MAROON);
                    /////
                    /////
                }
                else
                {


                    DrawText(FormatText("Name: %s", menu.name), 610, 10, 20, MAROON);
                    DrawText(game.scores().c_str(), 610, 30, 30, MAROON);
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
            if (!game.IsRunning() && menu.mnum == 0)
            {
                DrawText("PRESS Y/N TO GO TO MENU!", 200, 200, 40, YELLOW); //raylib
                if (IsKeyPressed(KEY_Y))
                {
                    menu.mnum = 1;
                    goto mylabel;
                }
                if (IsKeyPressed(KEY_N))
                {
                    CloseWindow();
                    return 0;
                }
            }
            EndDrawing();

    }

        game.UpdateScore();

    CloseWindow();
    return 0;
}