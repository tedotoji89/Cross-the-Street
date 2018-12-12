#include "CGAME.h"
#include "CPEOPLE.h"
#include "Menu.h"
#include "console.h"
#include "SetUp.h"

extern CGAME cg;
char MOVING;

void border() 
{
	mu.lock();
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
	mu.unlock();
}

void subThread()
{
	//	thread bird(runMultiBird, cg.getAnimal());
	//	bird.detach();

	while (true)
	{
		if (!cg.getPeople().isDead())
		{
			cg.updatePosPeople(MOVING);
		}
		MOVING = ' ';

		cg.updatePosAnimal();
		cg.updatePosVehicle();

		cg.drawGame();
		Sleep(30);
		cg.clrScr();

		if (cg.getPeople().isImpactVehi(cg.getVehicle()) || cg.getPeople().isImpactAni(cg.getAnimal())) {
			//cg.setDead();
			cout << "Haha";
			return;
		}
		if (cg.getPeople().isFinish()) {
			cout << "Finish.";
			return;
		}

	}
}

//--------------------------

CGAME::CGAME() 
{
	ac = new CBIRD[maxBird];
	akl = new CDINOSAUR[maxDino];
	ach = new CCAR[maxCar];
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
		akl[i].Draw();
		ach[i].render();
		axt[i].render();
	}
}


CPEOPLE CGAME::getPeople() {
	return *cn;
}

CVEHICLE* CGAME::getVehicle() {
	//return this->ach;
	if (cn->getY() > 17)
		return this->ach;
	return this->axt;
}

CANIMAL* CGAME::getAnimal() {
	//return this->ac;
	if (cn->getY() < 11)
		return this->ac;
	return this->akl;
}

void CGAME::setDead() {
	cn->setState(false);
}

void CGAME::resetGame() {
	return;
}

void CGAME::exitGame(void*) {
	clrscr();
	Routes();
}

void CGAME::startGame() 
{
	drawGame();

	for (int i = 0; i < maxBird; i++) {
		ac[i].setX(33 + 10*i);
		akl[i].setX(30 + 10 * i);
		ach[i].setX(32 + 10*i);
		axt[i].setX(34 + 10*i);
	}

	int temp;

	thread t1(subThread);

	//	thread bird(runMultiBird, cg.getAnimal());
//	cg.startGame();

	while (1) {
		temp = toupper(_getch());
		if (!cg.getPeople().isDead()) {
			if (temp == 27) {
				cg.exitGame(t1.native_handle());
				return;
			}
			else if (temp == 'P') {
				cg.pauseGame(t1.native_handle());
			}
			else {
				cg.resumeGame((HANDLE)t1.native_handle());
				MOVING = temp;
			}
		}
		else {
			if (temp == 'Y') cg.startGame();
			else {
				cg.exitGame(t1.native_handle());
				return;
			}
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

void CGAME::pauseGame(void*)
{
}

void CGAME::resumeGame(void*)
{
}

void CGAME::clrScr() {
	for (int i = 0; i < maxBird; i++) {
		ac[i].clr();
		akl[i].clr();
		ach[i].clr();
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
		axt[i].move();
	}
}

void CGAME::updatePosAnimal() {
	for (int i = 0; i < maxBird; i++) {
		ac[i].move();
		akl[i].move();
	}
}


