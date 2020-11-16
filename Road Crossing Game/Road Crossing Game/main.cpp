#include "Console.h"

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

 void Subthread() {
 	int x = 90; int y = 10;
 	int* a = new int[10];
 	for (int i = 0; i < 10; i++)
 		a[i] = 90 - i * 8;
 	while (1) {
 		for (int i = 0; i < 10; i++) {
 			Erase(a[i], y);
 			Move(a[i], y);
 			Draw(a[i], y);
 		}
 			DrawBoard(0, 0, 100, 20, 0, 0);
 			Sleep(10);
 	}
 }

 void ExitGame(HANDLE t1) {
 	GotoXY(1, 15);
 	for (int i = 0; i < 10; i++)
 		cout << endl;
 	TerminateThread(t1, 0);
 	exit(1);
 }

int main()
{
	 int temp;
	 ConsoleMain();
	 thread t1(Subthread);
	 temp = toupper(_getch());
	 if (temp == 'Y') {
	 	ExitGame(t1.native_handle());
	 }
	cout << "Hello" << endl;
	return 0;
}