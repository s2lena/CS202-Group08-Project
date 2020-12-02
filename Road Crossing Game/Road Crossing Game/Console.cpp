#include "Console.h"

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DrawBoard() {

	for (int i = 0; i < 30; i++) {
		GotoXY(i, 12);
		cout << (char)223;
	}

	for (int i = 0; i < 20; i++) {
		GotoXY(29, i);
		cout << (char)219;
	}

	for (int i = 0; i < 20; i++) {
		GotoXY(101, i);
		cout << (char)219;
	}

	GotoXY(0, 0);
	cout << "          CONTROL" << endl;
	cout << "   Use Arrows key to move ";
	GotoXY(0, 4);
	cout << "       INSTRUCTION:" << endl;
	cout << "   Save Game    :   L" << endl;
	cout << "   Load Game    :   T" << endl;
	cout << "   Pause/Resume :   P" << endl;
	cout << "   Menu         :   M" << endl;

	GotoXY(0, 13);
	cout << "Nguyen Minh Thu  - 19125123" << endl;
	cout << "Pham Thi Ngoc Ha - 19125089" << endl;
	cout << "Nguyen Thanh Dat - 19125021" << endl;
	cout << "Nguyen Hoang Son - 19125118" << endl;
}

void DrawFrame(bool check) {
	int k = 0;
	if (check == true)
		k = 8;
	TextColor(7);
	int x = 50; int y = 8 - k / 2;
	for (int j = y; j <= 13 + k / 2; j++) {
		for (int i = x; i <= x + 30 + k / 2; i++) {
			GotoXY(i, j);
			if (j == 8 - k / 2 || j == 13 + k / 2)
				cout << "*";
			else if (i == x || i == x + 30 + k / 2)
				cout << "*";
			else
				cout << " ";
		}
	}
}

void clrscr()
{
	const int x = 30;
	const int y = 0;
	for (int i = y; i <= 20; i++)
		for (int j = x; j <= 100; j++) {
			GotoXY(j, i);
			cout << " ";
		}
}

void ShowCur(bool CursorVisibility) 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SaveFile(string str) {
	ofstream ofs;
	ofs.open("Data.txt", ios::app);
	ofs << str << endl;
	ofs.close();
}

string LoadFile() {
	vector<string> list;
	ifstream ifs;
	string tmp;
	ifs.open("Data.txt");
	while (!ifs.eof()) {
		getline(ifs, tmp);
		if (tmp != "")
			list.push_back(tmp);
		else
			break;
		tmp.erase(tmp.begin(), tmp.end());
	}
	list.push_back("Exit");
	int x = 53; int y = 5;
	int k = list.size();
	int pos = 0;
	int c = 0;
	bool check = true;
	ShowCur(false);
	DrawFrame(true);
	while (check)
	{
		c = 0;
		GotoXY(x + 6, 5);
		cout << "LIST TO LOAD GAME" << endl;
		for (int i = 0; i < k; i++) {
			if (pos == i)
				TextColor(227);
			else
				TextColor(7);
			GotoXY(x, y + i + 1);
			cout << i << "  " << list[i];
		}
		switch ((c = _getch())) {
		case KEY_UP:
			pos = pos - 1;
			break;
		case KEY_DOWN:
			pos = pos + 1;
			break;
		case KEY_ENTER:
			check = false;
			break;
		default:
			break;
		}
		if (pos < 0)
			pos = pos + k;
		if (pos >= k)
			pos = pos - k;
	}
	return list[pos];
}

bool ChoiceFrame(string str) {
	DrawFrame(false);
	bool check = true;
	int c = 0; int x = 55; int y = 9;
	int pos = 0;
	vector<string> list = { " YES ", " NO " };
	while (check)
	{
		c = 0;
		TextColor(7);
		GotoXY(x, y);
		cout << str << " ";
		for (int i = 0; i < 2; i++) {
			if (pos == i)
				TextColor(227);
			else
				TextColor(7);
			GotoXY(x + 5 + 10 * i, y + 2);
			cout << list[i];
		}
		switch ((c = _getch())) {
		case KEY_RIGHT:
			pos = pos - 1;
			break;
		case KEY_LEFT:
			pos = pos + 1;
			break;
		case KEY_ENTER:
			check = false;
			break;
		default:
			break;
		}
		if (pos < 0)
			pos = pos + 2;
		if (pos >= 2)
			pos = pos - 2;
	}
	TextColor(7);
	return pos;
}

void DrawCrossWalk() {
	TextColor(7);
	bool check = false;
	int count = 0;
	int y = 3;
	for (int i = 30; i <= 100; i++) {
		if (check) {
			cout << " ";
			count++;
		}
		else {
			GotoXY(i, y); cout << (char)223;
			GotoXY(i, y + 4); cout << (char)223;
			GotoXY(i, y + 8); cout << (char)223;
			GotoXY(i, y + 12); cout << (char)223;
			GotoXY(i, y + 16); cout << (char)223;

			count++;
		}
		if (count == 2) {
			count = 0;
			if (check)
				check = false;
			else
				check = true;
		}
	}
}