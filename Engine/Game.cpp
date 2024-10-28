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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	pad({ gfx.ScreenWidth / 2.0f,(gfx.ScreenHeight * 3.0f) / 4.0f }, 80.0f, 10.0f, 200.0f),
	ball({ gfx.ScreenWidth / 2.0f,(gfx.ScreenHeight * 3.0f) / 4.0f - 20.0f }, { 1.0f, 1.0f }, 10.0f, 200.0f),
	brick({ gfx.ScreenWidth / 2.0f,100.0f}, 50.0f,20.0f,Colors::Green),
	walls(leftBound, rightBound, upBound, downBound)
{
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
	const float dt = ft.Mark();
	pad.KeepInBounds(walls);
	ball.DoWallCollision(walls);
	brick.DoBallCollision(ball);
	pad.DoBallCollision(ball);
	ball.Move(dt);

	int input = 0.0f;
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		input = -1.0f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		input = 1.0f;
	}
	pad.Move(input, dt);

}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	pad.Draw(gfx);
	brick.Draw(gfx);
}
