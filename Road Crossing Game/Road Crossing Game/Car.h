#ifndef _CAR_H_
#define _CAR_H_

#include "Vehicle.h"
#include "Console.h"

class Car : public Vehicle {
public:
	Car() {
		mx = 0;
		my = 0;
	}

	Car(int x, int y) {
		mx = x;
		my = y;
	}

	void draw() {
		drawPoint(mx + 1, my, my);
		drawPoint(mx + 2, my, my);
		drawPoint(mx, my + 1, my);
		drawPoint(mx + 1, my + 1, my);
		drawPoint(mx + 2, my + 1, my);
		drawPoint(mx + 3, my + 1, my);
	}

	void drawPoint(int x, int y, int t) {
		GotoXY(x, y);
		if (y == t)
			cout << (char)220;
		else
			cout << (char)223;
	}

	void erase() {
		erasePoint(mx + 1, my);
		erasePoint(mx + 2, my);
		erasePoint(mx, my + 1);
		/*erasePoint(mx + 1, my + 1);
		erasePoint(mx + 2, my + 1);
		erasePoint(mx + 3, my + 1);*/
	}

	void erasePoint(int x, int y) {
		GotoXY(x, y);
		cout << " ";
	}

	void move() {
		mx++;
		if (outMap(mx, my) ){
			mx = 30;
			DrawCrossWalk();
		}
	}
	bool Impact(int x, int y) {
		int check_x[6] = { this->mx + 1, this->mx + 2, this->mx, this->mx + 1, this->mx + 2, this->mx + 3 };
		int check_y[6] = { this->my, this->my, this->my + 1, this->my + 1, this->my + 1, this->my + 1 };
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 6; j++)
				if (x + i == check_x[j] && y == check_y[j])
					return true;
		}
		return false;
	}
};

#endif // _CAR_H_
