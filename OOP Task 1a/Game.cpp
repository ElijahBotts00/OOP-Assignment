#include "Game.h"

void Game::Setup()
{
    walls.push_back(Wall(4, 7));
    walls.push_back(Wall(9, 15));
    walls.push_back(Wall(15, 4));
}

void Game::UpdatePossition()
{
    apply_rules();
    tail.Move(player.GetX(), player.GetY());
    player.Move();
   // cout << to_string(player.GetX()) + "*" + to_string(player.GetY()) + " ";
    
}
                                            
void Game::UpdateDirection(int key)
{
    player.GetDirection(key);
}

/// <summary>
/// This function builds up a 2D grid of characters representing the current state of the game.
/// The characters are later used to decide which colour sqaure to display, but you could display images instead.
/// </summary>
vector<vector<char>> Game::PrepareGrid()
{
    // create the 2D grid
    vector<vector<char>> grid;

    // for each row
    for (int row = 1; row <= SIZE; ++row)
    {
        // create the inner vector to add to the 2D grid
        vector<char> line;

        // for each column, work out what's in that position and add the relevant char to the 2D grid
        for (int col = 1; col <= SIZE; ++col)
        {
            if (row == player.GetY() && col == player.GetX())
            {
                line.push_back(player.GetSymbol());
            }
            else if (IsTailAtPosition(col, row))
            {
                line.push_back(TAIL);
            }
            else if ((row == apple.get_y() && col == apple.get_x() && apple.collected != true))
            {
                line.push_back(apple.get_symbol());
            }
            else if (IsWallAtPosition(col, row))
            {
                line.push_back(WALL);
            }
            else
            {
                line.push_back(FLOOR);
            }
        }

        // now that the row is full, add it to the 2D grid
        grid.push_back(line);
    }

    return grid;
}

bool Game::IsWallAtPosition(int x, int y)
{
    for (size_t i = 0; i < walls.size(); ++i)
    {
        if (walls[i].IsAtPosition(x, y))
        {
            return true;
        }
    }

    return false;
}

bool Game::IsTailAtPosition(int x, int y)
{
    for (size_t i = 0; i < tail.tailPosition.size(); ++i)
    {
        if (tail.tailPosition[i].IsAtPosition(x, y))
        {
            return true;
        }
    }

    return false;
}

void Game::apply_rules()
{
    if (player.EatenApple(apple))
    {
        apple.eaten();
        score++;
        apple.~Apple();            // destroy the old one first.
        new (&apple) Apple();      // Call the constructor 
        if (IsWallAtPosition(apple.get_x(), apple.get_y()))
        {
            apple.~Apple();            // destroy the old one first.
            new (&apple) Apple();      // Call the constructor 
        }
        if (player.IsAtPosition(apple.get_x(), apple.get_y()))
        {
            apple.~Apple();            // destroy the old one first.
            new (&apple) Apple();      // Call the constructor 
        }
        if (tail.IsAtPosition(apple.get_x(), apple.get_y()))
        {
            apple.~Apple();            // destroy the old one first.
            new (&apple) Apple();      // Call the constructor 
        }

    }
    if (IsWallAtPosition(apple.get_x(), apple.get_y()))
    {
        apple.~Apple();            // destroy the old one first.
        new (&apple) Apple();      // Call the constructor 
    }
    if (player.IsAtPosition(apple.get_x(), apple.get_y()))
    {
        apple.~Apple();            // destroy the old one first.
        new (&apple) Apple();      // Call the constructor 
    }
    if (tail.IsAtPosition(apple.get_x(), apple.get_y()))
    {
        apple.~Apple();            // destroy the old one first.
        new (&apple) Apple();      // Call the constructor 
    }


}

bool Game::IsRunning()
{
    if (IsWallAtPosition(player.GetX(), player.GetY()))
    {
        return false;
    }
    // depending on your game you'll need to modify this to return false
    // maybe it's when the player runs out of moves, maybe it's when they get caught, it's up to you!
    return player.isalive();
}

bool Game::Menu()
{
    if (name == 0)
        return true;

    if (name == 1)
        return false;
}
string Game::eapple()
{
    if (apple.collected == true)
        return "You SCORED!";
}

string Game::get_end_reason()
{

    return "You hit a wall!";
}

int Game::scores()
{
    return score;
}