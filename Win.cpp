#include "Win.h"
#include "MainMenu.h"
#include <fstream>
#include "Level1.h"

Win::Win(Window* window, std::stack<Level*>* levels)
	: Level(window, levels)
{
	window->clearArrays();
}

Win::~Win()
{
}

void Win::endLevel()
{
}

void Win::update()
{
	if (GetAsyncKeyState(VK_ESCAPE) < 0) {
		exit(0);
	}
}

void Win::render(Window* window)
{
	window->dAddString(20, 15, "YOU WON!!\nPRESS ESCAPE FOR EXIT");
}