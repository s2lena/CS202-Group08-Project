#ifndef _CONSOLE_H_
#define _CONSOLE_H_
extern const int WIDTH;
extern const int HEIGHT;
extern const int LEFT;
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <vector>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_L 108
#define KEY_T 116
#define KEY_P 112
#define KEY_M 109


using namespace std;
struct Point {
	int x;
	int y;
};
void FixConsoleWindow();
void GotoXY(int x, int y);
void DrawBoard();
void DrawFrame(bool check);
bool ChoiceFrame(string str);
void DrawCrossWalk();
void EndFrame();
void clrscr();
void ShowCur(bool CursorVisibility);
void TextColor(int color);
void SaveFile(string str);
string LoadFile();

#endif // _CONSOLE_H_
