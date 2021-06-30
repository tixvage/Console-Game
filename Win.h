#pragma once

#include "Level.hpp"

class Win :
    public Level
{
public:
    Win(Window* window, std::stack<Level*>* levels);
    ~Win();

    void endLevel();

    void update();
    void render(Window* window);
};

