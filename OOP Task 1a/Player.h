#pragma once

#include "constants.h"
#include "Apple.h"


class Player
{
    public:
        // constructor
        Player();

        // assessors
        int GetX();
        int GetY();
        char GetSymbol() const;
        bool IsAtPosition(int x, int y);
        char GetDirection(int key);
        bool EatenApple(Apple apple);
        bool isalive();

        // mutators
        void Move();
        char symbol;
        char direction;
        int  x, y;

    private:
        // data members
        bool alive;
        bool escaped;
        int dx;
        int dy;
        

        // supporting functions 
        void PositionInMiddleOfGrid();
        void UpdatePosition(int dx, int dy);
};