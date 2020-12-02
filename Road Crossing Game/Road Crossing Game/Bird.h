#ifndef _BIRD_H_
#define _BIRD_H_

#include "Animal.h"
#include "Console.h"

class Bird : public Animal {
public:
	static const int size = 3;
	Bird() {};
	Bird(int x, int y) {
		a.x = x;
		a.y = y;
	}
	void Draw() {
		const int tmp = WIDTH - size + 1;
		if (isValid(a.x, a.y)) {
			if (a.x == tmp + 1) {
				GotoXY(a.x, a.y-1);
				cout << (char)220 << endl;
				return;
			}
			else if (a.x == tmp) {
				GotoXY(a.x, a.y);
				cout << " " << (char)223 << endl;
				GotoXY(a.x, a.y - 1);
				cout << (char)220 << endl;
				return;
			}
			else if (a.x == 0) {
				GotoXY(a.x + 1, a.y);
				cout << (char)223 << endl;
				GotoXY(a.x + 1, a.y - 1);
				cout << " " << (char)220 << endl;
				return;
			}
			else if (a.x == -1) {
				GotoXY(a.x + 2, a.y - 1);
				cout << (char)220 << endl;
				return;
			}
			GotoXY(a.x, a.y);
			cout << " " << (char)223 << endl;
			GotoXY(a.x, a.y - 1);
			cout << (char)220 << " " << (char)220 << endl;

		}
	}
	void Move() {
		this->a.x--;
		if (isValid(this->a.x, this->a.y)) {
			this->a.x = 100;
		}
	}
	void Erase() {
		const int tmp = WIDTH - size + 1;
		if (isValid(a.x, a.y)) {
			if (a.x == tmp + 1) {
				GotoXY(a.x, a.y);
				cout << " " << endl;
				return;
			}
			else if (a.x == tmp) {
				GotoXY(a.x, a.y);
				cout << "  " << endl;
				GotoXY(a.x, a.y - 1);
				cout << " " << endl;
				return;
			}
			else if (a.x == 0) {
				GotoXY(a.x + 1, a.y);
				cout << " " << endl;
				GotoXY(a.x + 1, a.y - 1);
				cout << "  " << endl;
				return;
			}
			else if (a.x == -1) {
				GotoXY(a.x + 2, a.y - 1);
				cout << " " << endl;
				return;
			}
			GotoXY(a.x, a.y);
			cout << "  " << endl;
			GotoXY(a.x, a.y - 1);
			cout << "   " << endl;
		}
	}
	bool Impact(int x, int y) {
		int check_x[3] = { x , x + 1 , x + 2 };
		int check_y[3] = { y - 1, y, y - 1 };
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
				if (x + i == check_x[j] && y == check_y[j])
					return true;
		return false;
	}
};

#endif // _BIRD_H_
