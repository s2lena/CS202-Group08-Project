#include "Console.h"
#include "Dinosaur.h"
#include "Car.h"
#include "Bird.h"

const int WIDTH=90;
const int HEIGHT=20;
Point aArray[10];
void Move(int& x, int& y) {
	if (x - 3 == 0) {
		x = 98;
		system("cls");
	}
	else {
		x = x - 1;
	}
}
void Erase(int x, int y) {
	GotoXY(x, y); printf(" ");
	GotoXY(x, y - 1); printf(" ");
}
void Draw(int x, int y) {
	GotoXY(x, y); cout << (char)254u;
	GotoXY(x - 1, y); cout << (char)254u;
	GotoXY(x - 2, y); cout << (char)254u;
	GotoXY(x - 1, y - 1); cout << (char)254u;
	GotoXY(x, y - 1); cout << (char)254u;
}
void ClearScreen() {
	COORD Position;
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}
void Subthread() {
	/*int x = 90; int y = 10;
	int* a = new int[10];
	for (int i = 0; i < 10; i++)
		a[i] = 90 - i * 8;
	while (1) {
		for (int i = 0; i < 10; i++) {
			Erase(a[i], y);
			Move(a[i], y);
			Draw(a[i], y);
		}
			Sleep(10);
			ClearScreen();
		 DrawBoard(0, 0, WIDTH, HEIGHT, 0, 0);
	}*/
	while (1) {
		/*DrawBoard(0, 0, WIDTH, HEIGHT, 0, 0);
		for (int i = 0; i < 10; i++) {
			Dinosaur a;
			a.Erase();
			a.Move(89, 2);
			a.Draw();
			Sleep(10);
		}*/
		DrawBoard(0, 0, WIDTH, HEIGHT, 0, 0);
		Bird a;
		a.Erase();
		a.Move(0, 3);
		a.Draw();
		ClearScreen();
	}
}
void ExitGame(HANDLE t1) {
	//GotoXY(1, 15);
	/*for (int i = 0; i < 10; i++)
		cout << endl;*/
	TerminateThread(t1, 0);
}

int main()
{
	int temp;
	ConsoleMain();
	thread t1(Subthread);
	while (1) {
		temp = toupper(_getch());
		if (temp == 'Q') {
			ExitGame(t1.native_handle());
			break;
		}
	}
	t1.join();


	return 0;
}