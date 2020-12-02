#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include "People.h"

class Vehicle{
public:
	int mx;
	int my;
	virtual void move() = 0;
	virtual void draw() = 0;
	virtual void erase() = 0;

	Vehicle() : mx(0), my(0) {};

	int getX() {
		return mx;
	}

	int getY() {
		return my;
	}

	bool outMap(int x, int y) {
		if (x > 96 || x < 30) {
			return true;
		}
		return false;
	}
};

#endif // _VEHICLE_H_
