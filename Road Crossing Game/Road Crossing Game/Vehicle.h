#ifndef _VEHICLE_H_
#define _VEHICLE_H_

class Vehicle {
public:
	int mx;
	int my;
	virtual void Move() = 0;
	virtual void Draw() = 0;
	virtual void Erase() = 0;
};

#endif // _VEHICLE_H_
