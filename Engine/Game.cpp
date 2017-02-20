/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <random>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(50, 620),
	yDist(50, 120),
	hxDist(50, 620),
	hyDist(220, 320),
	meter1(20, 30, Colors::Red),
	meter2(20, 10, Colors::Magenta)
{
	for (int i = 0; i < nBrick; i++) {

		bricks[i].Init(xDist(rng), yDist(rng), false);

	}
	Beep(523, 100);
	Beep(587, 100);
	Beep(659, 100);
	Beep(698, 100);
	Beep(784, 100);

}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//status update
	option.Update(wnd.kbd);

	for (int i = 0; i <= nBrick; i++) {
		if (!bricks[i].IsBroken()) {
			bricks[i].UpdateColor();
		}
	}

	int counter = -1;
	for (int i = 0; i <= nBrick; i++) {
		if (bricks[i].IsBroken()) {
			counter++;
		}
	}
	meter1.IncreaseLevel(counter);


	//serv
	if (option.IsServed()) {
		hammer.Init(hxDist(rng), hyDist(rng), speed, -speed);
		option.SetServed(false);
	}

	//play
	hammer.Update();
	paddle.Update(wnd.kbd);
	paddle.ProcessRebound(hammer);


	//Break Bricks
	for (int i = 0; i <= nBrick; i++) {
		if (!bricks[i].IsBroken()) {
			bricks[i].ProcessConsumption(hammer);
		}
	}

	//foul
	if (hammer.GetOutaBouds()) {
		option.SetGameOver(true);
		hammer.Init(400, 400, 0, 0);
		hammer.SetOutaBouds(false);
		for (int i = 0; i < nBrick; i++) {
			bricks[i].Init(xDist(rng), yDist(rng), false);
		}
		level = 0;
		meter2.IncreaseLevel(level);
	}

	bool allBroken = true;
	for (int i = 0; i < nBrick; i++) {
		allBroken = allBroken && bricks[i].IsBroken();
	}

	if (allBroken) {
		hammer.Bounce(0, 0);
		level++;
		meter2.IncreaseLevel(level);
		ResetMap();
	}



	//paddle.Update(wnd.kbd);
	//paddle.ProcessRebound(hammer);

}
void Game::ResetMap()
{
	option.SetOpeningCredits(true);
	option.SetStarted(false);
	option.SetServed(false);
	option.SetGameOver(false);
	hammer.Init(400, 400, 0, 0);
	hammer.SetOutaBouds(false);
	for (int i = 0; i < nBrick; i++) {
		bricks[i].Init(xDist(rng), yDist(rng), false);
	}

}
//end UpdateModel

void Game::ComposeFrame() {
	gfx.BackgroundColor();
	gfx.ForegroundColor();
	gfx.DrawFoulLine();

	if (option.GetOpeningCredits()) {

		option.DrawIntro(gfx, 250, 300);

	}
	else if(option.IsGameOver()) {

		option.DrawGameOver(gfx, 250, 300);

	}
	else {
		paddle.Draw(gfx);
		hammer.Draw(gfx);
		meter1.Draw(gfx);
		meter2.Draw(gfx);

		for (int i = 0; i <= nBrick; i++) {
			if (!bricks[i].IsBroken()) {
				bricks[i].Draw(gfx);
			}
		}
	}

}//end ComposeFrame

//endGame.cpp