#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>

class Random {
public:
    Random() {
        srand(time(0));
    }
    bool Bool() {
        return Percent(50);
    }
    int Range(int first, int last)
    {
        int uzunluk = last - first;
        return first + (rand() % uzunluk);
    }
    int Rand()
    {
        return rand();
    }
    bool Percent(int per)
    {
        return (rand() % 100) < per ? true : false;
    }
};
