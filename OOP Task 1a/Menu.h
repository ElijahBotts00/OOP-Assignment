#pragma once
#include "raylib.h"

class Menu
{
public:

    int whichMenu();
    void predraw();
    void predraw2();
    void drawmenu();
    void drawmenu2();
    char name[15 + 1] = "\0";


private:

    Rectangle newGame = { 430, 350, 150, 20 };
    Rectangle exitGame = { 430, 410, 150, 20 };
    const char MAX = 15;
    Texture2D texture = LoadTexture("snakes.png");
    int letterCount = 0;
    Rectangle entername = { 260, 280, 340, 60 };
    int framesCounter = 0;
    bool mouseOnText4();
    bool mouseOnText2();
    bool mouseOnText();
    bool verdict;
    bool verdict2;
    bool verdict4;
    int mnum = 1;
 
};