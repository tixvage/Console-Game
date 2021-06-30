#include "MainMenu.h"
#include <fstream>
#include "Level1.h"

MainMenu::MainMenu(Window* window, std::stack<Level*>* levels)
	: Level(window, levels)
{
	this->level = loadLevel("levels/mainmenu.lvl");
	window->clearArrays();
}

MainMenu::~MainMenu()
{
}

void MainMenu::endLevel()
{
}

std::string MainMenu::loadLevel(std::string filepath)
{
	std::ifstream ifs(filepath);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	return content;
}

void MainMenu::update()
{
	if (GetAsyncKeyState(VK_SPACE) < 0) {
		this->goLevel1();
	}
}

void MainMenu::render(Window* window)
{
	window->dAddString(10, 25, level);
}

void MainMenu::goLevel1() {
	this->levels->push(new Level1(window, levels));
}