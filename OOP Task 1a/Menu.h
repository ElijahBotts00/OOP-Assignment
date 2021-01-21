#pragma once
#include "raylib.h"
#include <fstream>
#include <string>

class Menu
{
public:

    int whichMenu();
    void predrawmenu();
    void predrawngmenu();
    void predrawhsmenu();
    void drawmenu();
    void drawngmenu();
    void drawhsmenu();
    char name[15 + 1] = "\0";
    char highScore[15 + 1] = "\0";
    int mnum = 1;

private:

    const Rectangle newGame = { 430, 350, 150, 20 };
    const Rectangle highscores = { 430, 390, 150, 20 };
    const Rectangle ngback = { 630, 410, 150, 20 };
    const Rectangle exitGame = { 430, 410, 150, 20 };
    const Rectangle exitHighscore = { 630, 410, 150, 20 };
    const Rectangle continRect = { 430, 370, 150, 20 };
    const char MAX = 15;
    const Texture2D texture = LoadTexture("snakes.png");
    int letterCount = 0;
    const Rectangle entername = { 260, 280, 340, 60 };
    int framesCounter = 0;
    bool mouseOnBack();
    bool mouseOnExit();
    bool mouseOnNewGame();
    bool mouseOnContinue();
    bool mouseOnhighScores();
    bool mouseOnText();
    bool mouseOnNgBack();
    bool ngbool;
    bool ngbbool;
    bool verdict;
    bool hsbool;
    bool egbool;
    bool ehsbool;
    bool cbool;

};