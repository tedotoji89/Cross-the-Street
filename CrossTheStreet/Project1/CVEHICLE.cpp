#include "CVEHICLE.h"
#include "CGAME.h"
#include "console.h"

void run1Car(int speed) {
	CCAR car;
	for (int i = 0; i < 60; i++) {
		car.render();
		Sleep(speed);
		car.clr();
		car.move();
	}
}

void runMultiCar() {
	while (true) {
		thread run(run1Car, 80);
		Sleep(1000);
		run.detach();
	}
}
void run1Truck(int speed) {
	CTRUCK truck;
	for (int i = 0; i < 60; i++) {
		truck.render();
		Sleep(speed);
		truck.clr();
		truck.move();
	}
}

void runMultiTruck() {
	while (true) {
		thread run(run1Truck, 100);
		Sleep(1000);
		run.detach();
	}
}


void CVEHICLE::render() {
	TextColor(14);
}

void CVEHICLE::clr() {
	TextColor(7);
}

void CVEHICLE::move() {
	mX++;
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
