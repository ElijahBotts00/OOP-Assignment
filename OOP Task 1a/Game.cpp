#include "Game.h"
#include <fstream>
#include <sstream>


void Game::Setup()
{
    walls.push_back(Wall(4, 7));
    walls.push_back(Wall(9, 15));
    walls.push_back(Wall(15, 4));
    while (player.IsAtPosition(apple.get_x(), apple.get_y()))
    {
        apple.collected = false;
        apple.position();
    }
     while (IsTailAtPosition(apple.get_x(), apple.get_y()))
     {
            apple.collected = false;
            apple.position();
      }
     while (IsWallAtPosition(apple.get_x(), apple.get_y()))
     {
         apple.collected = false;
         apple.position();
     }
}


void Game::UpdatePossition()
{
    apply_rules();
    tail.Move(player.GetX(), player.GetY());
    player.Move();
   // cout << to_string(player.GetX()) + "*" + to_string(player.GetY()) + " ";
}
void Game::UpdateScore()
{
    ofstream foutput;
    ifstream finput;
    finput.open("scores.txt");
    foutput.open("scores.txt", ios::app);
    if (finput.is_open())
    foutput << cname << "\n" << score<< "\n";
    finput.close();
    foutput.close();

}
                                            
void Game::UpdateDirection(int key)
{
    conti = false;
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
            if (conti == true)
            {
                if (row == sgplayerY && col == sgplayerX)
                {
                    line.push_back(player.GetSymbol());
                }
                else if ((row == sgappleY && col == sgappleX && apple.collected != true))
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
            if (conti == false)
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
        int i;
        i = atoi(score.c_str());
        i++;
        score = to_string(i);
        tail.IncreaseTail();
        Setup();

    }
}

bool Game::IsRunning()
{
    if (IsTailAtPosition(player.GetX(), player.GetY()))
    {
        return false;
    }
    if (IsWallAtPosition(player.GetX(), player.GetY()))
    {
        return false;
    }
    // depending on your game you'll need to modify this to return false
    // maybe it's when the player runs out of moves, maybe it's when they get caught, it's up to you!
    return player.isalive();
}

/*void Game::updateHS()
{
    //Stores the values from current highscore so they can be checked against the new score
    string Name1, Name2, Name3, Name4, Name5, NewName;
    int Score1, Score2, Score3, Score4, Score5, NewScore;

    vector <int> Scores;

    // Create a text string, which is used to output the text file


    int number = 0;
    string temp[10];
    ifstream Handler;
    Handler.open("save.txt");
    if (Handler.is_open())
    {

        for (int i = 0; i < 10; i++)
        {
            getline(Handler, temp[i]);
            number++;
        }

        Handler.close();
    }

    string load[10];
    int i = 0;
    stringstream ssin(temp[i]);
    while (ssin.good() && i < 10) {
        ssin >> load[i];
        ++i;
    }



    Name1 = load[0];
    if (sscanf_s(load[1].c_str(), "%d", &Score1) != 1);
    Name2 = load[2];
    if (sscanf_s(load[3].c_str(), "%d", &Score2) != 1);
    Name3 = load[4];
    if (sscanf_s(load[5].c_str(), "%d", &Score3) != 1);
    Name4 = load[6];
    if (sscanf_s(load[7].c_str(), "%d", &Score4) != 1);
    Name5 = load[8];
    if (sscanf_s(load[9].c_str(), "%d", &Score5) != 1);


    cout << load[3];

    /*
    for (int i = 0; i < Names.size(); i++)
        std::cout << Names.at(i) << ' ';

    cout << " ** ";

    for (int i = 0; i < Scores.size(); i++)
        std::cout << Scores.at(i) << ' ';


    ofstream foutput;
    ifstream finput;
    finput.open("scores.txt");
    foutput.open("scores.txt", ios::app);
    if (finput.is_open())
    foutput << cname << " " << score<< "\n";
    finput.close();
    foutput.close();
    */


    /*int number = 0;
    string temp[20];
    ifstream Handler;
    Handler.open("save.txt");
    if (Handler.is_open())
    {

        for (int i = 0; i < 10; i++)
        {
            getline(Handler, temp[i]);
            number++;
        }

        Handler.close();
    }

    string load[10];
    int i = 0;
    stringstream ssin(temp[10]);
    while (ssin.good() && i < 10) {
        ssin >> load[i];
        ++i;
    }

}*/
        



void Game::SaveGame()
{
    std::ofstream ofs;
    ofs.open("save.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofstream foutput;
    ifstream finput;
    finput.open("save.txt");
    foutput.open("save.txt", ios::app);
    if (finput.is_open())
        foutput << cname << " " << score << " " << apple.get_x() << " " << apple.get_y() << " " << player.GetX() << " " << player.GetY();
    finput.close();
    foutput.close();
}

void Game::LoadGame()
{
    int number = 0;
    string temp;
    ifstream Handler;
    Handler.open("save.txt");
    if (Handler.is_open())
    {
        while (getline(Handler, temp))
        {
                number++;
        }
        Handler.close();
    }

    string load[6];
    int i = 0;
    stringstream ssin(temp);
    while (ssin.good() && i < 6) {
        ssin >> load[i];
        ++i;
     }
    
    if (sscanf_s(load[5].c_str(), "%d", &sgplayerY) != 1);
        if (sscanf_s(load[4].c_str(), "%d", &sgplayerX) != 1);
            if (sscanf_s(load[2].c_str(), "%d", &sgappleX) != 1);
                if (sscanf_s(load[3].c_str(), "%d", &sgappleY) != 1);
    sgname = load[0];
    scoreload = load[1];

    conti = true;

    int scoretemp;
    apple.x = sgappleX;
    apple.y = sgappleY;
    player.x = sgplayerX;
    player.y = sgplayerY;
    score = scoreload;

    if (sscanf_s(score.c_str(), "%d", &scoretemp) != 1)

    strcpy_s(sname, sgname.c_str());

    tail.Length = scoretemp;
}

string Game::eapple()
{
    if (apple.collected == true)
        return "You SCORED!";
}

string Game::get_end_reason()
{

    return "You died!";
}

string Game::scores()
{
    return score;
}
