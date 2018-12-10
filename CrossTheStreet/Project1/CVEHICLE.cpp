#include "CVEHICLE.h"
#include "CGAME.h"
#include "console.h"

void CVEHICLE::render() {
	TextColor(14);
}

void CVEHICLE::clr() {
	TextColor(7);
}

void CVEHICLE::move() {
	if (mX < 88) {
		mX++;
	}
	else {
		mX = 30;
	}
}

CCAR::CCAR() {
	mX = 30;
	mY = 18;
}

void CCAR::render() {
	mu.lock();
	gotoXY(mX, mY); cout << char(220) << char(219) << char(220);
	mu.unlock();
}

void CCAR::move() {
	CVEHICLE::move();
}

void CCAR::clr() {
	mu.lock();
	gotoXY(mX, mY); cout << "   ";
	mu.unlock();
}

CTRUCK::CTRUCK() {
	mX = 30;
	mY = 22;
}

void CTRUCK::render() {
	mu.lock();
	gotoXY(mX, mY); cout << char(220) << char(219) << char(219);
	mu.unlock();
}

void CTRUCK::move() {
	CVEHICLE::move();
}

void CTRUCK::clr() {
	mu.lock();
	gotoXY(mX, mY); cout << "   ";
	mu.unlock();
}
