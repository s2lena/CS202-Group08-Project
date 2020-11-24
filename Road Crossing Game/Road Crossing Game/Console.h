#ifndef _CONSOLE_H_
#define _CONSOLE_H_
extern const int WIDTH;
extern const int HEIGHT;
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <conio.h>
#include <stdio.h>

using namespace std;
struct Point {
	int x;
	int y;
};
void FixConsoleWindow();
void GotoXY(int x, int y);
void DrawBoard(int x, int y, int width, int height, int curPosX, int curPosY);
void clrscr();
void ConsoleMain();

#endif // _CONSOLE_H_
