#include "Menu.h"
#include <fstream>
#include <string>
using namespace std;


bool Menu::mouseOnBack()
{
    return  ehsbool;
}
bool Menu::mouseOnNgBack()
{
    return  ngbbool;
}
bool Menu::mouseOnExit()
{
    return  egbool;
}
bool Menu::mouseOnNewGame()
{
    return  ngbool;
}
bool Menu::mouseOnText()
{
    return  verdict;
}
bool Menu::mouseOnhighScores()
{
    return  hsbool;
}
bool Menu::mouseOnContinue()
{
    return  cbool;
}



int Menu::whichMenu()
{
    return mnum;
}

void Menu::predrawhsmenu()
{
    if (CheckCollisionPointRec(GetMousePosition(), exitHighscore)) ehsbool = true;
    else ehsbool = false;
    if (ehsbool) framesCounter++;
    else framesCounter = 0;
}

void Menu::predrawngmenu()
{
    if (CheckCollisionPointRec(GetMousePosition(), ngback)) ngbbool = true;
    else ngbbool = false;
    if (ngbbool) framesCounter++;
    else framesCounter = 0;

    if (mouseOnText())
    {

        // Get char pressed (unicode character) on the queue
        int key = GetKeyPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0)
        {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (letterCount < MAX))
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
                mnum = 0;
        }
    }
    if (mouseOnText()) framesCounter++;
    else framesCounter = 0;
}

void Menu::predrawmenu()
{

    if (CheckCollisionPointRec(GetMousePosition(), newGame)) ngbool = true;
    else ngbool = false;
    if (ngbool) framesCounter++;
    else framesCounter = 0;

    if (CheckCollisionPointRec(GetMousePosition(), exitGame)) egbool = true;
    else egbool = false;
    if (egbool) framesCounter++;
    else framesCounter = 0;


    if (CheckCollisionPointRec(GetMousePosition(), highscores)) hsbool = true;
    else hsbool = false;
    if (hsbool) framesCounter++;
    else framesCounter = 0;

    if (CheckCollisionPointRec(GetMousePosition(), continRect)) cbool = true;
    else cbool = false;
    if (cbool) framesCounter++;
    else framesCounter = 0;
}

void Menu::drawmenu()
{
    ClearBackground(BLACK);
    DrawText("SNAKE V1.0", 360, 50, 20, LIGHTGRAY);
    DrawTexture(texture, texture.width / 2, texture.height / 10, WHITE);
    if (mouseOnNewGame()) {
        DrawText(": NEW GAME", 430, 350, 20, RED);
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            mnum = 2;
        }
    }
    else  DrawText(": NEW GAME", 430, 350, 20, WHITE);


    if (mouseOnContinue()) {
        DrawText(": CONTINUE", 430, 370, 20, RED);
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            mnum = 5;
        }
    }
    else      DrawText(": CONTINUE", 430, 370, 20, WHITE);

    if (mouseOnhighScores()) {
        DrawText(": HIGH SCORES", 430, 390, 20, RED);
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            mnum = 3;
        }
    }
    else  DrawText(": HIGH SCORES", 430, 390, 20, WHITE);


    if (mouseOnExit()) {
        DrawText(": EXIT", 430, 410, 20, RED);
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            mnum = 4;
        }
    }
    else  DrawText(": EXIT", 430, 410, 20, WHITE);

}

void Menu::drawngmenu()
{
    ClearBackground(BLACK);
    DrawText("SNAKE V1.0", 360, 50, 20, LIGHTGRAY);
    DrawRectangleRec(entername, LIGHTGRAY);
    if (mouseOnText()) DrawRectangleLines(entername.x, entername.y, entername.width, entername.height, RED);
    else DrawRectangleLines(entername.x, entername.y, entername.width, entername.height, DARKGRAY);

    DrawText(name, entername.x + 5, entername.y + 8, 40, RED);

    if (mouseOnText())
    {
        if (letterCount < MAX)
        {
            if (((framesCounter / 20) % 2) == 0) DrawText("_", entername.x + 8 + MeasureText(name, 40), entername.y + 12, 40, RED);
        }
        else DrawText("Max characters used... Try backspace", 260, 350, 20, GRAY);
    }

    DrawText("INPUT NAME AND PRESS ENTER", 260, 250, 20, LIGHTGRAY);

    if (mouseOnNgBack()) {
        DrawText(": BACK", 630, 410, 20, RED);
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            mnum = 1;
        }
    }
    else  DrawText(": BACK", 630, 410, 20, WHITE);
}

void Menu::drawhsmenu()
{
    ClearBackground(BLACK);
    DrawText("SNAKE V1.0", 360, 50, 20, LIGHTGRAY);
    int numberOfStrings = 0;
    string temp[20];
    ifstream myFile_Handler;

    myFile_Handler.open("scores.txt");

    if (myFile_Handler.is_open())
    {
        while (getline(myFile_Handler, temp[numberOfStrings]))
        {
            if (numberOfStrings < 10) {
                numberOfStrings++;
            }
        }
        myFile_Handler.close();
    }

    int height = 150;
    for (int i = 0; i < numberOfStrings; i++)
    {
        strcpy_s(highScore, temp[i].c_str());
        DrawText(highScore, 260, height, 20, LIGHTGRAY);
        height = height + 20;
    }

    if (mouseOnBack()) {
        DrawText(": BACK", 630, 410, 20, RED);
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            mnum = 1;
        }
    }
    else  DrawText(": BACK", 630, 410, 20, WHITE);
}


