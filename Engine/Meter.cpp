#include "Meter.h"

Meter::Meter(int in_x, int in_y, Color in_c)
{
	x = in_x;
	y = in_y;
	c = in_c;
}

void Meter::IncreaseLevel( int l)
{
	level = l;
}

int Meter::GetLevel() const
{
	return level;
}

void Meter::Draw(Graphics & gfx) const
{
	gfx.DrawRectDim(x, y, level*scale, girth, c);
}
