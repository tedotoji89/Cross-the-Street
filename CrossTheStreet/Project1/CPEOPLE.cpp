#include "CPEOPLE.h"

CPEOPLE::CPEOPLE() {
	mX = 60;
	mY = 7;
	mState = true; //Alive
}

void CPEOPLE::UP() {
	mY -= 1;
}

void CPEOPLE::LEFT() {
	mX -= 1;
}

void CPEOPLE::RIGHT() {
	mX += 1;
}

void CPEOPLE::DOWN() {
	mY += 1;
}

bool CPEOPLE::isImpact(CANIMAL a) {
	if (a.getX() == mX && a.getY() == mY)
		return true;
	return false;
}

bool CPEOPLE::isImpact(const CVEHICLE *& c) {
	return false;
}

bool CPEOPLE::isFinish() {
	return false;
}

bool CPEOPLE::isDead() {
	return (!mState ? true : false);
}

CPEOPLE::~CPEOPLE() {
	mX = 0;
	mY = 0;
	mState = true; // Alive
}
