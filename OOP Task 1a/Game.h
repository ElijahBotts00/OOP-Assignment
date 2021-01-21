#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"
#include "Tail.h"
#include "Apple.h"


using namespace std;

class Game
{
   public:
      Player player;
      Apple apple;
      Tail tail;
      vector<Wall> walls;
      void Setup();
      void UpdatePossition();
      void UpdateDirection(int key);
      vector<vector<char>> PrepareGrid();
      bool IsRunning();
      string eapple();
      string get_end_reason();
      string scores();
      string score = "0";
      string cname; /* copy of name */
      void UpdateScore();


      /* test */
      void LoadGame();
      void SaveGame();
      int sgplayerX;
      int sgplayerY;
      int sgappleX;
      int sgappleY;
      string sgname;
      string scoreload;
      bool conti;
      char sname[15 + 1] = "\0";
      bool continame = false;

      bool gpause = false;

private:
    void apply_rules();
    bool IsTailAtPosition(int x, int y);
    bool IsWallAtPosition(int x, int y);

};