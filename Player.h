#pragma once

#include "Random.h"
#include "Window.h"

//klavye inputlarý
#include <Windows.h>

enum direction {
	RIGHT, UP, DOWN, LEFT
};

struct Vector2 {
	int x;
	int y;
};

class Player
{
public:
	Player(int x, int y, Window* window);
	void update();
	void render();
	void clear();
	bool isAlive();
	bool isWin();
	void respawn();
private:
	int spawnposx, spawnposy;
	Window* window;
	void movement();
	void addForce(direction dir, int force);
	void fizikUpdate();
	void move(Vector2 dir);
	bool isGrounded();
	Vector2 position;
	Vector2 eskiPos;
	char sembol = 'O';
	Vector2 force;
};