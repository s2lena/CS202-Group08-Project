#ifndef _PEOPLE_H_
#define _PEOPLE_H_

#include "Animal.h"
#include "Vehicle.h"

class People {
public:
	int mx;
	int my;
	bool state;
	People();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const Vehicle*&);
	bool isImpact(const Animal*&);
	bool isFinish();
	bool isDead();
	void Erase();
	void Draw();
	void Reset();
};

#endif // _PEOPLE_H_
