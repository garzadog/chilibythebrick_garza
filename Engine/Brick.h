#pragma once
#include "Graphics.h"
#include "Hammer.h"

class Brick{
public:
	void Init(int in_x, int in_y, bool in_value );
	void ProcessConsumption(Hammer& hammer);
	bool IsColliding(Hammer & hammer);
	void Draw(Graphics& gfx) const;
	bool IsBroken();
	void SetBroken(bool value);
	void UpdateColor();

private:
	int x;
	int y;
	static constexpr int width = 50;
	static constexpr int height = 18;
	int	left = width / 4;
	int center = width / 2;
	int right = (3 * width) / 4;
	int hammerSpeed = 5;
	bool isBroken = false; 
	bool colorIncreasing = true;
	Color c = { 200,200,0 };
};