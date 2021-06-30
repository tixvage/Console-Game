#pragma once

#include "Level.hpp"
#include "Player.h"

class Level1 :
    public Level
{
public:
    Level1(Window* window, std::stack<Level*>* levels);
    ~Level1();

    void endLevel();

    void update();
    void render(Window* window);
private:
    Player player{ 10, 10, window };
    std::string loadLevel(std::string filepath);
    std::string level;
};

