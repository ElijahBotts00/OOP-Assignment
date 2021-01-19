#include "Player.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;

Player::Player() : symbol(PLAYER), x(0), y(0), alive(true), escaped(false), dx(0), dy(0)
{
    PositionInMiddleOfGrid();
}

int Player::GetX()
{
    return x;
}

int Player::GetY()
{
    return y;
}

char Player::GetSymbol() const
{
    return symbol;
}

bool Player::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}

/// <summary>
/// This function gets key inputs and records inputs and returns as char direction (L - Left, R - Right ect..)
/// Direction is then used in the case statement below to update position of the snake depending on current direction.
/// ---Fergus
/// </summary>
char Player::GetDirection(int key)
{
    if (key == KEY_LEFT)
    {
        direction = 'L';
    }
    else if (key == KEY_RIGHT)
    {
        direction = 'R';
    }
    else if (key == KEY_UP)
    {
        direction = 'U';
    }
    else if (key == KEY_DOWN)
    {
        direction = 'D';
    }
    return direction;
}

void Player::Move()
{
    std::this_thread::sleep_for(125ms);
    switch (direction)
    {
    case 'L':
        dx = -1;
        dy = 0;
        break;
    case 'R':
        dx = +1;
        dy = 0;
        break;
    case 'U':
        dx = 0;
        dy = -1;
        break;
    case 'D':
        dx = 0;
        dy = +1;
        break;
    default:
        break;
    }
    // update mouse coordinates if move is possible
    if (((x + dx) >= 1) && ((x + dx) <= SIZE) && ((y + dy) >= 1) && ((y + dy) <= SIZE))
    {
        UpdatePosition(dx, dy);
    }
}

bool Player::EatenApple(Apple nu)
{

    if (IsAtPosition(nu.get_x(), nu.get_y()))
    {
        return true;
    }

    return false;
}


void Player::UpdatePosition(int dx, int dy)
{
    x += dx;
    y += dy;
}

void Player::PositionInMiddleOfGrid()
{
    x = SIZE / 2;
    y = SIZE / 2;
}