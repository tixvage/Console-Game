#include "Console-Game.hpp"
#include "MainMenu.h"

void Game::initWindow()
{
	this->window = new Window(50, 50);
}

void Game::initLevels()
{
	this->levels.push(new MainMenu(this->window, &this->levels));
}

void Game::endGame()
{
}

void Game::update()
{
	if (!this->levels.empty()) {
		this->levels.top()->update();

		if (this->levels.top()->getQuit()) {
			delete this->levels.top();
			this->levels.pop();
		}
	}
}

void Game::render()
{	
	window->drawScreen();
	if (!this->levels.empty())
		this->levels.top()->render(this->window);
}

Game::Game()
{
	this->initWindow();
	this->initLevels();
}

Game::~Game()
{
	delete this->window;

	while (!this->levels.empty()) {
		delete this->levels.top();
		this->levels.pop();
	}
}

void Game::run()
{
	while (true) {
		this->update();
		this->render();
	}
	this->endGame();
}
