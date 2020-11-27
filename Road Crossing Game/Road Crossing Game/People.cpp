#include "People.h"
#include "Console.h"


People::People() {

}

void People::Up(int) {
	if (my != 0) my--;
}

void People::Left(int) {
	if (mx != 0) mx--;
}

void People::Right(int) {
	if (mx != 90) mx++;
}

void People::Down(int) {
	if (my != 50) my++;
}

bool People::isImpact(const Vehicle*& a) {
	if (mx == a->mx && my = a->my) return true;
	return false;
}

bool People::isImpact(const Animal*& a) {
	if (mx == a->mx && my = a->my) return true;
	return false;
}

bool People::isFinish() {
	return state;
}

bool People::isDead() {
	return state;
}

void People::Erase() {

}

void People::Draw() {
	GotoXY(45, 20);
	cout << "Y";
}