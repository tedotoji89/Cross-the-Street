#include "CGAME.h"
#include "CPEOPLE.h"
#include "Menu.h"
#include "console.h"
#include "SettingUp.h"

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
	cn = new CPEOPLE();
}

CGAME::~CGAME() 
{
	delete[] axt;
	delete[] ach;
	//delete[] akl;
	//delete[] ac;
	delete[] cn;
}

void CGAME::drawGame() 
{
	border();

	thread bird(runMultiBird, ac);
	thread dino(runMultiDino);
	thread car(runMultiCar);
	thread truck(runMultiTruck);

	startGame();

	bird.join();
	dino.join();
	car.join();
	truck.join();
}

CPEOPLE CGAME::getPeople() {
	return CPEOPLE();
}

CVEHICLE CGAME::getVehicle() {
	return CVEHICLE();
}

CANIMAL CGAME::getAnimal() {
	return CANIMAL();
}

void CGAME::resetGame() {
	return;
}

void CGAME::exitGame() {
}

void CGAME::startGame() 
{
	while (1)
	{
		int z = _getch();
		switch (z)
		{
		case 97: case 100: case 115: case 119: case 65: case 68: case 83: case 87:
			updatePosPeople(z);
			break;

		case 80: case 112:
			break;

		case 84: case 116:
			resetGame();
			break;

		case 76: case 108:
			saveGame();
			break;

		//default:
		}

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

void CGAME::updatePosPeople(int z)
{
	int minX = 30,
		maxX = 91,
		minY = 6,
		maxY = 26;

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
}

void CGAME::updatePosAnimal() {
}
