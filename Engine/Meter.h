#pragma once
#include "Graphics.h"

class Meter {
public:
	Meter(int in_x, int in_y, Color c);
	void	IncreaseLevel( int l );
	int		GetLevel() const;
	void	Draw(Graphics& gfx)const;
private:
	Color c;
	static constexpr int girth = 12;
	static constexpr int scale = 8;
	int		level = 0;
	int		x = 20;
	int		y = 20;
};