#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include "Console.h"
class Animal{
public:
	Point a;
	Animal() {}
	virtual void Move() = 0;
	virtual void Draw() = 0;
	virtual void Erase() = 0;
	bool isValid(int x, int y) {
		if (x > (27) && x <= 99) return true;
		return false;
	}
};

#endif // _ANIMAL_H_
