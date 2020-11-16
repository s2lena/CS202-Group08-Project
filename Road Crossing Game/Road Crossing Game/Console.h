#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <conio.h>
#include <stdio.h>

using namespace std;

void FixConsoleWindow();
void GotoXY(int x, int y);
void DrawBoard(int x, int y, int width, int height, int curPosX, int curPosY);
void clrscr();
void ConsoleMain();

#endif // _CONSOLE_H_
