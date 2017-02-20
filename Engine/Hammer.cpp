#include "Hammer.h"
#include "Graphics.h"

void Hammer::Init(int in_x, int in_y, int in_vx, int in_vy)
{
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;

}

void Hammer::Update()
{
	x = x + vx;
	y = y + vy;

	int left = x;
	int right = x;
	int top = y;
	int bottom = y;

	if (left < 50) {

		vx = -vx;
		x = 51;
		Beep(698, 100);
	}
	else if (right >= Graphics::ScreenWidth - 50 - width) {
		vx = -vx;
		x = (Graphics::ScreenWidth - 50 - width);
		Beep(698, 100);
	}

	if (top < 50) {
		vy = -vy;
		y = 51;
		Beep(698, 100);
	}
	else if (bottom >= Graphics::ScreenHeight - 50 - height) {
		IsOutaBounds = true;
		vx = 0;
		vy = 0;
		x = Graphics::ScreenWidth - width-80;
		y = Graphics::ScreenHeight - height-450;
		Beep(350, 750);
		Beep(250, 700);
		Beep(150, 1200);
		Sleep(300);
	}
}

void Hammer::Draw(Graphics& gfx) const 
{
	for (int r = 0; r <= height; r++) {
		for (int c = 0; c <= width; c++) {
			if (r == 0 || r == height) {
				gfx.PutPixel(c + x, r + y, 0, 0, 0);
			}
			else if (c == 0 || c == width) {
				gfx.PutPixel(c + x, r + y, 0, 0, 0);
			}
			else {
				gfx.PutPixel(c + x, r + y, 66, 80, 244);
			}
		}
	}
}

void Hammer::Bounce(int lr, int ud)
{
	vx = lr;
	vy = ud;
}

void Hammer::SetOutaBouds(bool value)
{
	IsOutaBounds = value;
}

bool Hammer::GetOutaBouds()
{
	return IsOutaBounds;
}


int Hammer::GetWidth()
{
	return width;
}

int Hammer::GetHeight()
{
	return height;
}

int Hammer::GetX()
{
	return x;
}

int Hammer::GetY()
{
	return y;
}

int Hammer::GetVX()
{
	return vx;
}
