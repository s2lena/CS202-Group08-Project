#include "People.h"
#include "Console.h"


People::People() : mx(64), my(20) { state = true; };

void People::Up(int) {
	if (my == 3 || my == 7 || my == 11 || my == 15 || my == 19)
		DrawCrossWalk();
	if (my != 0) my--;
}

void People::Left(int) {
	if (mx != 0) mx--;
}

void People::Right(int) {
	if (mx != 100) mx++;
}

void People::Down(int) {
	if (my == 3 || my == 7 || my == 11 || my == 15 || my == 19)
		DrawCrossWalk();
	if (my != 30) my++;
}

bool People::isFinish() {
	if (this->my == 0)
		return true;
	return false;
}

bool People::isDead() {
	return !state;
}

void People::Erase() {
	GotoXY(this->mx, this->my);
	cout << " " << " ";
}

void People::Draw() {
	GotoXY(this->mx, this->my);
	TextColor(243);
	cout << (char)223 << (char)223;
	TextColor(7);
}

void People::Reset() {
	mx = 65;
	my = 20;
	state = true;
}