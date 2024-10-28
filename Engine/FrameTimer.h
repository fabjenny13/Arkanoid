#pragma once
#include <chrono>

class FrameTimer
{
private:
	std::chrono::steady_clock::time_point last;
public:
	FrameTimer();
	float Mark();

};

