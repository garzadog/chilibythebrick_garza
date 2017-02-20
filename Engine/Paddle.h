#pragma once
#include "Hammer.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle {
public:
	void	Update(const Keyboard & kbd);
	void	ClampToScreen();
	void	ProcessRebound(Hammer & hammer);
	bool	IsColliding(Hammer & hammer);
	void	Draw(Graphics& gfx) const;
	int		GetX() const;
	int		GetY() const;
	int		GetWidth() const;
	int		GetHeight() const;

private:
	int		xPos = 100;
	int		yPos = 500;
	int		speed = 10;
	int		width = 100;
	int		height = 5;
	int		center = xPos + (width/2);
	int		left = xPos + (width/4);
	int		right = xPos + ((3*width)/4);
	int		hammerSpeed = 5;
};