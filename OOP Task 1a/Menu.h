#pragma once
#include "raylib.h"
#include <fstream>
#include <string>

class Menu
{
public:

    int whichMenu();
    void predraw();
    void predraw2();
    void predraw3();
    void drawmenu();
    void drawmenu2();
    void drawmenu3();
    char name[15 + 1] = "\0";
    char highScore[15 + 1] = "\0";
    int mnum = 1;

private:

    Rectangle newGame = { 430, 350, 150, 20 };
    Rectangle highscores = { 430, 390, 150, 20 };
    Rectangle exitGame = { 430, 410, 150, 20 };
    const char MAX = 15;
    Texture2D texture = LoadTexture("snakes.png");
    int letterCount = 0;
    Rectangle entername = { 260, 280, 340, 60 };
    int framesCounter = 0;
    bool mouseOnText4();
    bool mouseOnText2();
    bool mouseOnText3();
    bool mouseOnText();
    bool verdict;
    bool verdict2;
    bool verdict3;
    bool verdict4;

};