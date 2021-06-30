#pragma once

#include <stack>
#include <iostream>
#include "Window.h"

class Level
{
protected:
	std::stack<Level*>* levels;
	Window* window;

public:
	bool quit;

	Level(Window* window, std::stack<Level*>* levels);
	virtual ~Level();

	const bool& getQuit() const;
	virtual void checkForQuit();

	virtual void endLevel() = 0;

	virtual void update() = 0;
	virtual void render(Window* window = NULL) = 0;
};
