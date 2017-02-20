#include "Paddle.h"
#include "Graphics.h"

void Paddle::Update( const Keyboard & kbd)
{
	if (kbd.KeyIsPressed(VK_RIGHT)) {
		xPos += speed;
		left += speed;
		center += speed;
		right += speed;
	}
	if (kbd.KeyIsPressed(VK_LEFT)) {
		xPos -= speed;
		left -= speed;
		center -= speed;
		right -= speed;
	}
	if (kbd.KeyIsPressed(VK_UP)) {
		yPos -= speed;
	}
	if (kbd.KeyIsPressed(VK_DOWN)) {
		yPos += speed;
	}
	ClampToScreen();
}

void Paddle::ClampToScreen()
{
	//test if xPos is out of bounds
	if (xPos < 51) {
		xPos = 51;
	}
	else if (xPos >= Graphics::ScreenWidth - 50 - width) {
		xPos = (Graphics::ScreenWidth - 51 - width);
	}
	//set left center

	if (left < 50 + (width / 4)) {
		left = 51 + (width / 4);
	}
	else if (left >= Graphics::ScreenWidth - 50 - width + (width / 4)) {
		left = Graphics::ScreenWidth - 51 - width + (width / 4);
	}
	//set center center
	if (center < 50 + (width / 2)) {
		center = 51 + (width / 2);
	}
	else if (center >= Graphics::ScreenWidth - 50 - width + (width / 2)) {
		center = Graphics::ScreenWidth - 50 - width + (width / 2);
	}
	//set right center

	if (right < 50 + ((3 * width) / 4)) {
		right = 51 + ((3 * width) / 4);
	}
	else if (right >= Graphics::ScreenWidth - 50 - width + ((3 * width) / 4)) {
		right = Graphics::ScreenWidth - 51 - width + ((3 * width) / 4);
	}

	if (yPos >= Graphics::ScreenHeight - 50 - height) {
		yPos = Graphics::ScreenHeight - 51 - height;
	}
	if (yPos <= 450) {
		yPos = 451;
	}
}

void Paddle::ProcessRebound(Hammer & hammer)
{
	if (IsColliding(hammer)) {
		Beep(587, 100);

		if ((hammer.GetVX() > 0) && (hammer.GetX() <= left)) {
			hammer.Bounce(-hammerSpeed, -hammerSpeed);
		}
		else if ((hammer.GetVX() > 0) && (hammer.GetX() >= right)) {
			hammer.Bounce(hammerSpeed, -hammerSpeed);
		}
		else if ((hammer.GetVX() < 0) && (hammer.GetX() >= right)) {
			hammer.Bounce(hammerSpeed, -hammerSpeed);
		}
		else if ((hammer.GetVX() < 0) && (hammer.GetX() <= left)) {
			hammer.Bounce(-hammerSpeed, -hammerSpeed);
		}
		else if ((hammer.GetVX() > 0 || hammer.GetVX() < 0) && (hammer.GetX() > left && hammer.GetX() < right)) {
			hammer.Bounce(0, -hammerSpeed);
		}
		else if ((hammer.GetVX() == 0) && (hammer.GetX() > left && hammer.GetX() < right)) {
			hammer.Bounce(0, -hammerSpeed);
		}
		else if ((hammer.GetVX() == 0) && (hammer.GetX() <= left)) {
			hammer.Bounce(-hammerSpeed, -hammerSpeed);
		}
		else if ((hammer.GetVX() == 0) && (hammer.GetX() >= right)) {
			hammer.Bounce(hammerSpeed, -hammerSpeed);
		}
	}
}

bool Paddle::IsColliding(Hammer & hammer)
{
	const int right0 = hammer.GetX() + hammer.GetWidth();
	const int bottom0 = hammer.GetY() +hammer.GetHeight();
	const int right1 = xPos + width;
	const int bottom1 = yPos + height;

	return
		right0 >= xPos &&
		hammer.GetX() <= right1 &&
		bottom0 >= yPos &&
		hammer.GetY() <= bottom1;
}

void Paddle::Draw(Graphics& gfx) const
{
	for (int r = 0; r <= height; r++) {
		for (int c = 0; c <= width; c++) {
			if (c == width / 2) {
				gfx.PutPixel(c + xPos, r + yPos, 255, 0, 0);
			}
			else if (c == width / 4) {
				gfx.PutPixel(c + xPos, r + yPos, 0, 255, 0);
			}
			else if (c == (3 *width) / 4) {
				gfx.PutPixel(c + xPos, r + yPos, 0, 255, 0);
			}
			else {
				gfx.PutPixel(c + xPos, r + yPos, 0, 0, 0);
			}

		}
	}
}

int Paddle::GetX() const
{
	return xPos;
}

int Paddle::GetY() const
{
	return yPos;
}

int Paddle::GetWidth() const
{
	return width;
}

int Paddle::GetHeight() const
{
	return height;
}
