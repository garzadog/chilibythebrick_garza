#include "Brick.h"

void Brick::Init(int in_x, int in_y , bool in_value)
{
	x = in_x;
	y = in_y;
	isBroken = false;
}

void Brick::ProcessConsumption(Hammer & hammer)
{
	if (IsColliding(hammer)) {

		Beep(523, 50);
		
		isBroken = true;

		if ((hammer.GetVX() > 0) && (hammer.GetX() < left)) {
			hammer.Bounce(-hammerSpeed, hammerSpeed);
		}
		else if ((hammer.GetVX() > 0) && (hammer.GetX() > right)) {
			hammer.Bounce(-hammerSpeed, hammerSpeed);
		}
		else if ((hammer.GetVX() < 0) && (hammer.GetX() > right)) {
			hammer.Bounce(hammerSpeed, hammerSpeed);
		}
		else if ((hammer.GetVX() < 0) && (hammer.GetX() < left)) {
			hammer.Bounce(-hammerSpeed, hammerSpeed);
		}
		else if ((hammer.GetVX() > 0 || hammer.GetVX() < 0) && (hammer.GetX() > left && hammer.GetX() < right)) {
			hammer.Bounce(0, -hammerSpeed);
		}
		else if ((hammer.GetVX() == 0) && (hammer.GetX() > left && hammer.GetX() < right)) {
			hammer.Bounce(0, hammerSpeed);
		}
		else if ((hammer.GetVX() == 0) && (hammer.GetX() < left)) {
			hammer.Bounce(-hammerSpeed, hammerSpeed);
		}
		else if ((hammer.GetVX() == 0) && (hammer.GetX() > right)) {
			hammer.Bounce(hammerSpeed, hammerSpeed);
		}

	}
	else {

	}
}

bool Brick::IsColliding(Hammer & hammer)
{
	const int right0 = hammer.GetX() + hammer.GetWidth();
	const int bottom0 = hammer.GetY() + hammer.GetHeight();
	const int right1 = x + width;
	const int bottom1 = y + height;

	return
		right0 >= x &&
		hammer.GetX() <= right1 &&
		bottom0 >= y &&
		hammer.GetY() <= bottom1;
}

void Brick::Draw( Graphics& gfx ) const
{
	gfx.DrawRectDim(x, y, width, height, c);
}

bool Brick::IsBroken()
{
	return isBroken;
}

void Brick::SetBroken(bool value)
{
	isBroken = value;
}

void Brick::UpdateColor()
{
	if (colorIncreasing) {
		if (c.GetR() >= 254) {
			colorIncreasing = false;
		}
		else {
			c = Color(c.GetR() + 2, c.GetG() + 4,0);
		}
	}
	else
	{
		if (c.GetR() <= 200) {
			colorIncreasing = true;
		}
		else {
			c = Color(c.GetR() - 2, c.GetG() - 4,0);
		}
	}
}

