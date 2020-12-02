#ifndef _PEOPLE_H_
#define _PEOPLE_H_

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
	bool isFinish();
	bool isDead();
	void Erase();
	void Draw();
	void Reset();
};

#endif // _PEOPLE_H_
