#pragma once

#include "Level.hpp"

class MainMenu :
    public Level
{
public:
    MainMenu(Window* window, std::stack<Level*>* levels);
    ~MainMenu();

    void endLevel();

    void update();
    void render(Window* window);
private:
    std::string loadLevel(std::string filepath);
    std::string level;

    void goLevel1();
};