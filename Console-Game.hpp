#pragma once

#include <stack>
#include <iostream>
#include "Window.h"
#include "Level.hpp"
class Game {
private:
	Window* window;
	
	std::stack <Level*> levels;

	void initWindow();
	void initLevels();

	void endGame();

	void update();
	void render();

public:
	Game();
	virtual ~Game();

	void run();
};