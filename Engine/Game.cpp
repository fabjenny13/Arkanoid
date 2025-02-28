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
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	pad({ gfx.ScreenWidth / 2.0f,(gfx.ScreenHeight * 5.0f) / 6.0f }, 80, 15.0f, 350.0f),
	ball({ gfx.ScreenWidth / 2.0f,((gfx.ScreenHeight * 3.0f) / 4.0f) - 30.0f }, { 0.0f, 1.0f }),
	walls(leftBound, rightBound, upBound, downBound),
	brickHitSound(L"arkbrick.wav"),
	padHitSound(L"arkpad.wav"),
	readySound(L"ready.wav"),
	gameOverSound(L"fart.wav")

{
	Color colours[nRows] = { Colors::Red, Colors::Green, Colors::Cyan, Colors::Magenta, Colors::Blue };
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
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);

		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{

	if (gameState == GameState::gameStart)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			gameState = GameState::gamePlaying;
		}
	}
	else if(gameState == GameState::gamePlaying)
	{
		if (ball.GetRect().down >= walls.down)
		{
			if (--nLives <= 0)
			{
				gameState = GameState::gameOver;
			}
			else 
			{
				ball.ResetPosition();
				ball.SetDirection(Vec2(0.0f, 1.0f));
				pad.ResetPosition();
				gameState = GameState::getReady;
			}

			
		}
		else
		{
			ball.Update(dt);
			ball.DoWallCollision(walls);

			bool collisionHappened = false;
			float curColDist = -1;
			int curColIndex = -1;


			for (int i = 0; i < nBricks; i++)
			{
				if (bricks[i].CheckCollision(ball))
				{
					const float newColDist = (bricks[i].GetCenter() - ball.GetPosition()).GetLengthSq();
					if (collisionHappened)
					{
						if (newColDist < curColDist)
						{
							curColDist = newColDist;
							curColIndex = i;

						}

					}
					else
					{
						collisionHappened = true;
						curColDist = newColDist;
						curColIndex = i;
					}
				}
			}

			if (collisionHappened)
			{
				bricks[curColIndex].ExecuteBallCollision(ball);
			}

			pad.Update(wnd, dt);
			pad.KeepInBounds(walls);
			pad.DoBallCollision(ball);
		}
	}
	else if (gameState == GameState::getReady)
	{
		if (currWaitedTime > getReadyTime)
		{
			currWaitedTime = 0.0f;
			gameState = GameState::gamePlaying;
		}
		else
		{
			currWaitedTime += dt;
		}
	}
}

void Game::ComposeFrame()
{
	if (gameState == GameState::gameStart)
	{
		SpriteCodex::DrawTitle(gfx.GetCenter(), gfx);
	}
	else
	{
		for (int i = 0; i < nLives - 1; i++)
		{
			SpriteCodex::DrawPoo(Vec2(25.0f + i * 24.0f, 25.0f), gfx);
		}
		pad.Draw(gfx);
		ball.Draw(gfx);
		SpriteCodex::DrawBorders(walls, gfx);

		for (const Brick& b : bricks)
		{
			b.Draw(gfx);
		}



		if (gameState == GameState::gameOver)
		{
			SpriteCodex::DrawGameOver(gfx.GetCenter(), gfx);
		}
		else if (gameState == GameState::getReady)
		{
			SpriteCodex::DrawReady(gfx.GetCenter(), gfx);
		}

	}


}
