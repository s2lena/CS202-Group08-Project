#ifndef _DINOSAUR_H_
#define _DINOSAUR_H_

#include "Animal.h"
#include "Console.h"

class Dinosaur : public Animal {
public:
	static const int size = 3;
	Dinosaur() {};
	void Draw() {
		const int tmp = WIDTH - size+1;
		if (isValid(a.x, a.y)) {

			if (a.x == tmp + 1) {
				GotoXY(a.x, a.y);
				cout << (char)223 << endl;
				return;
			}
			else if (a.x == tmp) {
				GotoXY(a.x, a.y);
				cout << (char)223 << (char)223 << endl;
				GotoXY(a.x, a.y - 1);
				cout << " " << (char)220 << endl;
				return;
			}
			else if (a.x == 0) {
				GotoXY(a.x + 1, a.y);
				cout << (char)223 << endl;
				GotoXY(a.x + 1, a.y - 1);
				cout << (char)220 << (char)219 << endl;
				return;
			}
			else if (a.x == -1) {
				GotoXY(a.x + 2, a.y - 1);
				cout << (char)219 << endl;
				return;
			}
			GotoXY(a.x, a.y);
			cout << (char)223 << (char)223 << endl;
			GotoXY(a.x, a.y - 1);
			cout << " " << (char)220 << (char)219 << endl;

		}
	}
	void Move(int x, int y) {
		if (isValid(x, y)) {
			this->a.x = x;
			this->a.y = y;
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
				cout << "  " << endl;
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
				cout << " "<< endl;
				return;
			}
			GotoXY(a.x, a.y);
			cout << "  " << endl;
			GotoXY(a.x, a.y - 1);
			cout << "   " << endl;

		}
	}
};

#endif // _DINOSAUR_H_
