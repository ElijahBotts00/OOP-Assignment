#pragma once
#include "Constants.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Tail
{
public:
	//constructors
	Tail();
	Tail(int x, int y);

	//assessors
	char GetSymbol() const;
	bool IsAtPosition(int x, int y);
	void IncreaseTail();
	string WhatIsXY(Tail);

	//mutators
	int x;
	int y;
	void Move(int x, int y);
	int Length;
	vector<Tail> tailPosition;


private:
	//data members
	char symbol;
};
