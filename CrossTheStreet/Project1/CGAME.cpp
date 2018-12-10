#include "CGAME.h"
#include "CPEOPLE.h"
#include "Menu.h"
#include "console.h"
#include "SetUp.h"

void border() 
{
	gotoXY(97, 7); cout << "Score: 0";
	gotoXY(97, 8); cout << "Level: 1";

	TextColor(14);
	gotoXY(97, 10); cout << "Press [P]";
	gotoXY(97, 11); cout << "to pause";

	TextColor(14);
	gotoXY(97, 13); cout << "Press [T]";
	gotoXY(97, 14); cout << "to load";

	TextColor(14);
	gotoXY(97, 16); cout << "Press [L]";
	gotoXY(97, 17); cout << "to save";
	
	//---------------------
	gotoXY(29, 5);
	for (int i = 0; i < 64; i++) {
		TextColor(15);
		cout << char(220);
	}

	gotoXY(29, 27);
	for (int i = 0; i < 64; i++) {
		TextColor(15);
		cout << char(223);
	}

	for (int i = 6; i < 27; i++) {
		gotoXY(29, i); cout << char(219);
	}

	for (int i = 6; i < 27; i++) {
		gotoXY(92, i); cout << char(219);
	}

	//---------------------
	gotoXY(94, 5);
	for (int i = 0; i < 20; i++) {
		TextColor(15);
		cout << char(220);
	}

	gotoXY(94, 27);
	for (int i = 0; i < 20; i++) {
		TextColor(15);
		cout << char(223);
	}

	for (int i = 6; i < 27; i++) {
		gotoXY(94, i); cout << char(219);
	}

	for (int i = 6; i < 27; i++) {
		gotoXY(113, i); cout << char(219);
	}

}

void controlPeople() { }

CGAME::CGAME() 
{
	ac = new CBIRD[maxBird];
	akl = new CDINOSAUR[maxDino];
	ach = new CCAR[maxBird];
	axt = new CTRUCK[maxTruck];
	cn = new CPEOPLE();
}

CGAME::~CGAME() 
{
	delete[] axt;
	delete[] ach;
	delete[] akl;
	delete[] ac;
	delete[] cn;
}

void CGAME::drawGame() 
{
	border();
	for (int i = 0; i < maxBird; i++) {
		ac[i].Draw();
	}
	for (int i = 0; i < maxDino; i++) {
		akl[i].Draw();
	}
	for (int i = 0; i < maxCar; i++) {
		ach[i].render();
	}
	for (int i = 0; i < maxCar; i++) {
		axt[i].render();
	}
}

CPEOPLE CGAME::getPeople() {
	return *cn;
}

CVEHICLE* CGAME::getVehicle() {
	return this->ach;
}

CANIMAL* CGAME::getAnimal() {
	return this->ac;
}

void CGAME::setDead() {
	cn->setState(false);
}

void CGAME::resetGame() {
	return;
}

void CGAME::exitGame(void*) {
	//Routes();
}

void CGAME::startGame() 
{
	for (int i = 0; i < maxBird; i++) {
		ac[i].setX(33 + 10*i);
	}
	for (int i = 0; i < maxDino; i++) {
		akl[i].setX(30 + 10 * i);
	}
	for (int i = 0; i < maxCar; i++) {
		ach[i].setX(32 + 10*i);
	}
	for (int i = 0; i < maxCar; i++) {
		axt[i].setX(34 + 10*i);
	}
}

string savePath;
void CGAME::saveGame() 
{
	system("cls");

	cout << "Enter your saving path:\n";
	getline(cin, savePath);

	return;
}

void CGAME::pauseGame(void*)
{
}

void CGAME::resumeGame(void*)
{
}

void CGAME::clrScr() {
	for (int i = 0; i < maxBird; i++) {
		ac[i].clr();
	}
	for (int i = 0; i < maxDino; i++) {
		akl[i].clr();
	}
	for (int i = 0; i < maxCar; i++) {
		ach[i].clr();
	}
	for (int i = 0; i < maxCar; i++) {
		axt[i].clr();
	}
}

void CGAME::updatePosPeople(int z)
{
	int x, y;

	x = cn->getX(), y = cn->getY();

	mu.lock();
	gotoXY(x, y); cout << " ";
	mu.unlock();

	//Kiem tra key nhap vao
	State stat = key(z);

	switch (stat)
	{
	case UP:
		if (y > minY) cn->UP();
		break;
	case DOWN:
		if (y < maxY) cn->DOWN();
		break;
	case RIGHT:
		if (x < maxX) cn->RIGHT();
		break;
	case LEFT:
		if (x > minX) cn->LEFT();
		break;
	case ENTER:
		return;
	}

	x = cn->getX(), y = cn->getY();

	mu.lock();
	gotoXY(x, y); cout << "Y";
	mu.unlock();
}

void CGAME::updatePosVehicle() {
	for (int i = 0; i < maxCar; i++) {
		ach[i].move();
	}
	for (int i = 0; i < maxCar; i++) {
		axt[i].move();
	}
}

void CGAME::updatePosAnimal() {
	for (int i = 0; i < maxBird; i++) {
		ac[i].move();
	}
	for (int i = 0; i < maxDino; i++) {
		akl[i].move();
	}
}
