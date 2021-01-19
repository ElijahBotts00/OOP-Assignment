#include "raylib.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

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
    const char MAX_INPUT_CHARS = 15;
    char name[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount = 0;
    Rectangle textBox = { 450, 280, 325, 60 };
    int framesCounter = 0;
    bool mouseOnText = false;
    Image image = LoadImage("snakes.png");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);
    Game game;
    game.Setup();

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        mouseOnText = true;
        if (mouseOnText)
        {
            // Get char pressed (unicode character) on the queue
            int key = GetKeyPressed();

            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                {
                    name[letterCount] = (char)key;
                    letterCount++;
                }

                key = GetKeyPressed();  // Check next character in the queue
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                if (letterCount > 0)
                    game.name = 1;

            }
        }

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;

        //---------------------------------------------------------------------------------
        BeginDrawing();

        if (game.Menu() == true)
        {
            ClearBackground(BLACK);
            DrawText("SNAKE V1.0", 510, 50, 20, LIGHTGRAY);
            DrawTexture(texture, texture.width / 2, texture.height / 10, WHITE);

            DrawRectangleRec(textBox, LIGHTGRAY);
            if (mouseOnText) DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, BLACK);
            else DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, DARKGRAY);

            DrawText(name, textBox.x + 5, textBox.y + 8, 40, BLACK);

            if (mouseOnText)
            {
                if (letterCount < MAX_INPUT_CHARS)
                {
                    if (((framesCounter / 20) % 2) == 0) DrawText("_", textBox.x + 8 + MeasureText(name, 40), textBox.y + 12, 40, BLACK);
                }
                else DrawText("Max characters used... Try backspace", 430, 350, 20, GRAY);
            }

            DrawText(": INPUT NAME AND PRESS ENTER", 430, 250, 20, LIGHTGRAY);
        }
        else
        {
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

    CloseWindow();
    return 0;
}