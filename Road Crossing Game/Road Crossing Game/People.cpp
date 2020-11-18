#include "People.h"
#include "Console.h"


People::People() {

}

void People::Up(int) {
	if (my != 0) my--;
	return my;
}

void People::Left(int) {
	if (mx != 0) mx--;
	return mx;
}

void People::Right(int) {
	if (mx != 90) mx++;
	return mx;
}

void People::Down(int) {
	if (my != 50) my++;
	return my;
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
	return false;
}

bool People::isDead() {
	if (this->isImpact()) {
		this->state = false;
		return true;
	}
}

void People::Erase() {

}

void People::Draw() {

}