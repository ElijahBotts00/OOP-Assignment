#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"
#include "Apple.h"

using namespace std;

class Game
{
   public:
      Player player;
      Apple apple;
      vector<Wall> walls;
      void Setup();
      void UpdatePossition();
      void UpdateDirection(int key);
      vector<vector<char>> PrepareGrid();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y);
};