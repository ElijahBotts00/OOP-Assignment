#include "Apple.h"



Apple::Apple() : symbol(APPLE), x(0), y(0), collected(false)
{
	position();
}

int Apple::get_x()
{
	return x;
}

int Apple::get_y()
{
	return y;
}

char Apple::get_symbol() const
{
	return symbol;
}

bool Apple::is_at_position(int x, int y)
{
	return this->x == x && this->y == y;
}

bool Apple::has_been_collected() const
{
	return collected;
}

void Apple::eaten()
{
	collected = true;
}

void Apple::position()
{
	x = (rand() % 20);
	y = (rand() % 20);
}

