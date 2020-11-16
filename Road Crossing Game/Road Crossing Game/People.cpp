#include "People.h"

People::People() {

}

void People::Up(int) {

}

void People::Left(int) {

}

void People::Right(int) {

}

void People::Down(int) {

}

bool People::isImpact(const Vehicle*&) {

	return false;
}

bool People::isImpact(const Animal*&) {

	return false;
}

bool People::isFinish() {
	return false;
}

bool People::isDead() {
	return true;
}

void People::Erase() {

}

void People::Draw() {

}