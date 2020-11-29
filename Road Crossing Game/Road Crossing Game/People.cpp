#include "People.h"
#include "Console.h"


People::People() : mx(45), my(20), state(true) {};

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
	if (mx == a->mx && my == a->my) return true;
	return false;
}

bool People::isImpact(const Animal*& a) {
	if (mx == a->a.x && my == a->a.y) return true;
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
<<<<<<< Updated upstream

=======
	GotoXY(45, 20);
	cout << "Y";
}

void People::Reset() {
	mx = 45;
	my = 20;
	state = true;
>>>>>>> Stashed changes
}