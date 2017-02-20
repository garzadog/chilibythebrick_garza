#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Options {
public:
	void Update(const Keyboard & kbd);
	void DrawIntro(Graphics& gfx, int x, int y) const;
	void DrawGameOver(Graphics& gfx, int x, int y) const;
	bool GetOpeningCredits();
	void SetOpeningCredits( bool value);
	bool GetStarted();
	void SetStarted(bool value);
	bool IsServed();
	void SetServed(bool value);
	bool GetLevelUp();
	void setLevelUp( bool value);
	bool IsGameOver();
	void SetGameOver(bool value);

private:
	bool OpeningCredits = true;
	bool started = false;
	bool served = false;
	bool levelUp = false;
	bool GameOver = false;
	int	 speed = 5;

};