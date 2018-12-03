#include "CANIMAL.h"
#include "CGAME.h"
#include "console.h"

mutex mu;

void run1Bird(int speed, CBIRD bird) {
	for (int i = 0; i < 60; i++) {
		bird.render();
		Sleep(speed);
		bird.clr();
		bird.move();
	}
}

void runMultiBird(CBIRD bird) {
	while (true) {
		thread run(run1Bird, 100, bird);
		Sleep(1000);
		run.detach();
	}
}

void run1Dino(int speed) {
	CDINOSAUR dino;
	for (int i = 0; i < 60; i++) {
		dino.render();
		Sleep(speed);
		dino.clr();
		dino.move();
	}
}

void runMultiDino() {
	while (true) {
		thread run(run1Dino, 200);
		Sleep(3000);
		run.detach();
	}
}

void CANIMAL::render() {
	TextColor(14);
}

void CANIMAL::clr() {
	TextColor(7);
}

void CANIMAL::move() {
	mX++;
}

CBIRD::CBIRD() {
	mX = 30;
	mY = 10;
}

void CBIRD::render() {
	mu.lock();
	gotoXY(mX, mY);	cout << char(223) << char(254) << char(223);
	mu.unlock();
}

void CBIRD::move() {
	CANIMAL::move();
}

void CBIRD::clr() {
	mu.lock();
	gotoXY(mX, mY); cout << "   ";
	mu.unlock();
}

CDINOSAUR::CDINOSAUR() {
	mX = 30;
	mY = 13;
}

void CDINOSAUR::render() {
	mu.lock();
	gotoXY(mX, mY);		cout << "  " << char(220);
	gotoXY(mX, mY + 1); cout << char(220) << char(219) << char(223);
	mu.unlock();
}

void CDINOSAUR::move() {
	CANIMAL::move();
}

void CDINOSAUR::clr() {
	mu.lock();
	gotoXY(mX, mY);		cout << "   ";
	gotoXY(mX, mY + 1); cout << "   ";
	mu.unlock();
}
