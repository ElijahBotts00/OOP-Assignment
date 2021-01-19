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
      bool IsWallAtPosition(int x, int y);
      bool Menu();
      bool IsTailAtPosition(int x, int y);
      int name;
      string eapple();
      string get_end_reason();
      string scores();
      string score = "0";

private:
    void apply_rules();

};