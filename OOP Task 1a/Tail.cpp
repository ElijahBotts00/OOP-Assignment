#include "Tail.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

Tail::Tail() : symbol(TAIL), x(0), y(0), Length(60)
{

}

Tail::Tail(int x, int y)
{

}

char Tail::GetSymbol() const
{
	return symbol;
}

bool Tail::IsAtPosition(int x, int y)
{
	return this->x == x && this->y == y;
}

string Tail::WhatIsXY(Tail)
{
	return "x =" + to_string(this->x) + "y =" + to_string(this->y);
}

void Tail::Move(int x, int y)
{
	Tail temp;
	Tail temp2;

	//intilise tail xys only runs till size = full length of tale
	if (tailPosition.size() < Length)
	{
		tailPosition.push_back(Tail(x, y));
	}

	//setting the currrent pos head
	temp.x = x;
	temp.y = y;
	
	for (int i = 0; i < tailPosition.size(); i++)
	{
		//take previous pos of head and shuffles
		temp2.x = tailPosition[i].x;
		temp2.y = tailPosition[i].y;
		tailPosition[i].x = temp.x;
		tailPosition[i].y = temp.y;
		temp.x = temp2.x;
		temp.y = temp2.y;
	}  
}