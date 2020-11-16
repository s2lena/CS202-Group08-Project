#ifndef _ANIMAL_H_
#define _ANIMAL_H_


class Animal {
	int mx;
	int my;
public:
	virtual void Move() = 0;
	virtual void Draw() = 0;
	virtual void Erase() = 0;
};

#endif // _ANIMAL_H_
