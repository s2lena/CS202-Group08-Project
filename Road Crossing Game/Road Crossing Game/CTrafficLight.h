#ifndef _CTRAFFIC_H_
#define _CTRAFFIC_H_

#include "Console.h"

class CTrafficLight
{
private:
	int y;
public:
	CTrafficLight() {
		y = -1;
	};
	void Draw() {
		GotoXY(31, y);
		TextColor(4);
		cout << (char)220;
		GotoXY(31, y+1);
		TextColor(2);
		cout << (char)223;
	}
	void Clear() {
		GotoXY(31, y);
		cout << " ";
		GotoXY(31, y + 1);
		cout << " ";
	}
	void setY(int y) {
		this->y = y;
	};
	int getY() { 
		return y;
	};
};

#endif //_CTRAFFIC_H_
