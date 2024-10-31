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
	pad({ gfx.ScreenWidth / 2.0f,(gfx.ScreenHeight * 3.0f) / 4.0f }, 100.0f, 20.0f, 300.0f),
	ball({ gfx.ScreenWidth / 2.0f,(gfx.ScreenHeight * 3.0f) / 4.0f - 20.0f }, { -300.0f, 300.0f }),
	walls(leftBound, rightBound, upBound, downBound)
{
	Color colours[nRows] = { Colors::Red, Colors::Green, Colors::Cyan, Colors::Magenta };
	Vec2 topLeft = { leftBound, upBound + 2*brickHeight };
	for (int y = 0; y < nRows; y++)
	{
		Color c = colours[y];
		for (int x = 0; x < nCols; x++)
		{
			Vec2 newTopLeft = { topLeft.x + x*brickWidth, topLeft.y + y*brickHeight };
			Vec2 newMid = { newTopLeft.x + brickWidth / 2, newTopLeft.y + brickHeight / 2 };
			bricks[y * nCols + x] = Brick(newMid, brickWidth, brickHeight, c);
		}
	}


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

	ball.Update(dt);
	ball.DoWallCollision(walls);
	for (Brick& b : bricks)
	{
		b.DoBallCollision(ball);
	}

	pad.Update(wnd, dt);
	pad.KeepInBounds(walls);
	pad.DoBallCollision(ball);

}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	pad.Draw(gfx);
	for (const Brick& b : bricks)
	{
		b.Draw(gfx);
	}

}
