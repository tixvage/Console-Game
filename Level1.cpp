#include "Level1.h"
#include <fstream>
#include "Win.h"
Level1::Level1(Window* window, std::stack<Level*>* levels)
	: Level(window, levels)
{
	//önceki levellerden kalan þeyleri silmemiz gerek
	window->clearArrays();

	this->level = loadLevel("levels/level1.lvl");
}

Level1::~Level1()
{
}

void Level1::endLevel()
{
}

void Level1::update()
{
	if (!player.isAlive()) {
		player.clear();
		window->dAddString(20, 15, "YOU DIED\nPress SPACE for respawn");
		if (GetAsyncKeyState(VK_SPACE) < 0) {
			player.respawn();	
			window->clearArrays();
		}
	}
	else if (!player.isWin()) {
		this->levels->push(new Win(window, levels));
	}
	else {
		player.update();
	}
}

void Level1::render(Window* window)
{
    window->dAddString(20, 40, level);
	window->dAddString(0, 40, level);
	window->dAddString(38, 45, level);
	player.render();
}

std::string Level1::loadLevel(std::string filepath)
{
	std::ifstream ifs(filepath);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	return content;
}
