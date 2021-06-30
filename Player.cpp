#include "Player.h"

Player::Player(int x, int y, Window* window)
{
	this->window = window;
	spawnposx = x; spawnposy = y;
	this->position.x = x; this->position.y = y;
	this->force.x = 0;
	this->force.y = 0;
	window->dAddChar(position.x, position.y, sembol);
}

void Player::update()
{
	fizikUpdate();
	movement();
}

void Player::render()
{
	std::cout << position.x << " " << position.y << "\n";
}

void Player::clear()
{
	window->dScreen[position.x][position.y] = ' ';
	window->drawScreen();
}

bool Player::isAlive()
{
	return !(position.y + 3 >= window->screeny);
}

bool Player::isWin()
{
	return !(position.x + 2 >= window->screenx);
}

void Player::respawn()
{
	window->dScreen[position.x][position.y] = ' ';
	position.x = spawnposx; position.y = spawnposy;
}

void Player::movement()
{
	if (GetAsyncKeyState(VK_UP) < 0) {
		if (isGrounded()) {
			this->addForce(DOWN, 10);
		}
	}
	if (GetAsyncKeyState(VK_LEFT) < 0)
		this->addForce(LEFT, 1);
	if (GetAsyncKeyState(VK_RIGHT) < 0)
		this->addForce(RIGHT, 1);

}
void Player::addForce(direction dir, int force)
{
	switch (dir)
	{
	case RIGHT:
		this->force.x += force;
		break;
	case UP:
		this->force.y += force;
		break;
	case DOWN:
		this->force.y -= force;
		break;
	case LEFT:
		this->force.x -= force;
		break;
	default:
		break;
	}
}

void Player::fizikUpdate()
{
	Vector2 temp;
	temp.x = 0; temp.y = 0;
	if (force.x > 0) {
		force.x--;
		temp.x += 1;
	}
	if (force.x < 0) {
		force.x++;
		temp.x -= 1;
	}
	if (force.y > 0) {
		force.y--;

		if (!isGrounded()) {
			if (position.y + 3<= window->screeny) {
				temp.y += 1;
			}
		}
	}
	if (force.y < 0) {
		force.y++;
		temp.y -= 1;
	}
	if (!isGrounded()) {
		if(position.y + 3 <= window->screeny)
			addForce(UP, 1);
	}
	move(temp);
	Sleep(50);
}


void Player::move(Vector2 dir)
{
	eskiPos = position;
	window->dScreen[position.x][position.y] = ' ';
	position.x += dir.x;
	position.y += dir.y;
	window->dScreen[position.x][position.y] = sembol;
	window->drawScreen();
}

bool Player::isGrounded()
{
	if (window->dScreen[position.x][position.y + 1] == ' ') return false;

	return true;
}
