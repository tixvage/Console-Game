#include "Level.hpp"

Level::Level(Window* window, std::stack<Level*>* levels)
{
	this->window = window;
	this->levels = levels;
	this->quit = false;
}

Level::~Level()
{
}

const bool& Level::getQuit() const
{
	return this->quit;
}

void Level::checkForQuit()
{
}
