/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Pad.h"
#include "Ball.h"
#include "Brick.h"
#include "FrameTimer.h"
#include "Sound.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	enum GameState
	{
		gameStart = 0,
		gamePlaying = 1,
		gameOver = 2,
		getReady = 3
	};


	FrameTimer ft;
	static constexpr float leftBound = 150.0f;
	static constexpr float rightBound = (float)Graphics::ScreenWidth - leftBound;
	static constexpr float upBound = 50.0f;
	static constexpr float downBound = (float)Graphics::ScreenHeight - upBound;
	Pad pad;
	Ball ball;
	static constexpr float brickWidth = 50.0f;
	static constexpr float brickHeight = 20.0f;
	static constexpr int nRows = 5;
	static constexpr int nCols = (int)((rightBound - leftBound) / brickWidth);
	static constexpr int nBricks = nRows * nCols;
	Brick bricks[nBricks];
	Rect walls;
	int nLives = 3;
	float getReadyTime = 2.0f;
	float currWaitedTime = 0.0f;

	bool gameStarted = false;
	bool gameEnded = false;

	GameState gameState = GameState::gameStart;

	Sound brickHitSound;
	Sound padHitSound;
	Sound gameOverSound;
	Sound readySound;
	/********************************/
};