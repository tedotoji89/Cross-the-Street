#include "CGAME.h"
#include "CPEOPLE.h"
#include "Menu.h"
#include "console.h"
#include "SettingUp.h"

void border() {
	gotoXY(29, 4); cout << "Score: 0";
	gotoXY(40, 4); cout << "Level: 1";
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
}

void controlPeople() {
	int minX = 30,
		maxX = 91,
		minY = 6,
		maxY = 26;

	int x, y;
	CPEOPLE man;
	while (1) {
		x = man.getX(), y = man.getY();

		mu.lock();
		gotoXY(x, y); cout << "Y";
		mu.unlock();

		//Kiem tra key nhap vao
		int z = _getch();
		State stat = key(z);
		switch (stat) {
		case UP:
			if (y > minY)
				man.UP();
			break;
		case DOWN:
			if (y < maxY)
				man.DOWN();
			break;
		case RIGHT:
			if (x < maxX)
				man.RIGHT();
			break;
		case LEFT:
			if (x > minX)
				man.LEFT();
			break;
		case ENTER:
			return;
		}
		mu.lock();
		gotoXY(x, y); cout << " ";
		mu.unlock();
	}
}

CGAME::CGAME() {

}

CGAME::~CGAME() {
	delete[] axt;
	delete[] ach;
	delete[] akl;
	//delete[] ac;
	delete[] cn;
}

void CGAME::drawGame() {
	border();
	thread bird(runMultiBird, ac);
	thread dino(runMultiDino);
	thread car(runMultiCar);
	thread truck(runMultiTruck);
	controlPeople();

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
}

void CGAME::exitGame() {
}

void CGAME::startGame() {
}

void CGAME::saveGame() {
}

void CGAME::updatePosPeople(char) {
}

void CGAME::updatePosVehicle() {
}

void CGAME::updatePosAnimal() {
}
