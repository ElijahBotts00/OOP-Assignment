#pragma once

#include "constants.h"
#include "RandomNumberGenerator.h"

class Apple
{
public:
	// constructors
	Apple();

	// accessors
	int get_x();
	int get_y();
	bool has_been_collected() const;
	char get_symbol() const;
	void position();
	void eaten();
	bool collected;
	int x, y;

private:
	// data members
	char symbol;


	bool is_at_position(int x, int y);

};
