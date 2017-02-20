#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Hammer {
public:
	void	Init( int in_x, int in_y, int in_vx, int in_vy);
	void	Update();
	void	Draw(Graphics & gfx)const;
	void	Bounce(int lr, int ud);
	void	SetOutaBouds( bool value);
	bool	GetOutaBouds();
	int		GetWidth();
	int		GetHeight();
	int		GetX();
	int		GetY();
	int		GetVX();

private:
	int		x = 200;
	int		vx = 0;
	int		y = 200;
	int		vy = 0;
	int		width = 20;
	int		height = 20;
	int		speed = 5;
	bool	IsOutaBounds = false;
};