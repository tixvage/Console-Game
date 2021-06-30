#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;


class Window {
public:
    Window(int x, int y) {
        ShowConsoleCursor(false);
        screenx = x;
        screeny = y;
        this->init();
    }
    void sAddChar(int x, int y, char c) {
        if (x != 0 && x != screenx - 1 && y != 0 && y != screeny - 1) {
            sScreen[x][y] = c;
        }
    }
    void dAddChar(int x, int y, char c) {
        if (x != 0 && x != screenx - 1 && y != 0 && y != screeny - 1) {
            dScreen[x][y] = c;
        }
    }
    void dAddString(int x, int y, std::string s) {
        int tempx = x;
        for (auto c : s) {
            if (c != '\n') {
                dAddChar(x, y, c);
                x++;
            }
            else {
                x = tempx;
                y++;
                dAddChar(x, y, c);
            }
        }
    }
    //çerçeve oluþturma go br
    void init() {
        for (int i = 0; i < screeny; i++) {
            for (int j = 0; j < screenx; j++) {
                if (j == 0 || j == screenx - 1) {
                    sScreen[j][i] = 'I';
                }
                else if (i == 0 || i == screeny - 1) {
                    sScreen[j][i] = '-';
                }
                else {
                    sScreen[j][i] = ' ';
                }
                dScreen[j][i] = ' ';
            }
            cout << endl;
        }
    }
    void clearChar(int x, int y) {
        dScreen[x][y] = ' ';
        sScreen[x][y] = ' '; 
    }
    void moveChar(int x, int y, char c, int r, int l) {
        if (x != 0 && x != screenx - 1 && y != 0 && y != screeny - 1 && x + r != 0 && x + r != screenx - 1 && y + l != 0 && y + l != screeny - 1) {
            dScreen[x][y] = ' ';
            dScreen[r][l] = c;
        }
    }
    bool isEmpty(int x, int y) {
        if (dScreen[x][y] != ' ' && sScreen[x][y] != ' ')
            return false;
        else return true;
    }
    void drawScreen() {
        x = "";
        for (int i = 0; i < screeny; i++) {
            for (int j = 0; j < screenx; j++) {
                if (dScreen[j][i] != ' ') {
                    x += dScreen[j][i];
                    x += " ";
                }
                else {
                    x += sScreen[j][i];
                    x += " ";
                }
            }
            x += "\n";
        }
        ClearScreen();
        cout << x;
    }
    //cursoru gizlemek için Ð
    void ShowConsoleCursor(bool showFlag)
    {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag;
        SetConsoleCursorInfo(out, &cursorInfo);
    }

    //system("cls") veya system("clear") çok yavaþ bu yüzden windows.h daki bazý þeyleri kullandým
    void ClearScreen()
    {
        HANDLE hOut;
        COORD Position;
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        Position.X = 0;
        Position.Y = 0;
        SetConsoleCursorPosition(hOut, Position);
    }

    //hýzlý bir þekilde arraylerimizi sýfýrlayýp çerçeveyi baþtan yapýyo
    void clearArrays() {
        memset(sScreen, ' ', sizeof(sScreen));
        memset(dScreen, ' ', sizeof(dScreen));
        init();
    }
    int screenx;
    int screeny;
    char sScreen[100][100];
    char dScreen[100][100];
private:
    string x;
};