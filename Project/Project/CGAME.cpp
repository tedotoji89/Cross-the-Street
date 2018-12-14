#include "CGAME.h"
#include "CPEOPLE.h"
#include "Menu.h"
#include "console.h"
#include "SetUp.h"

void backgroundMusic(sf::Sound& sound, sf::SoundBuffer& buffer)
{
	sound.setVolume(100.f);

	std::string wavPath = path + "Funky-Gameplay_Looping.wav";

	if (!buffer.loadFromFile(wavPath))
		return; // error

	sound.setLoop(true);
	sound.setBuffer(buffer);
	sound.play();
}

void levelUpMusic()
{
	sf::Sound sound;
	sf::SoundBuffer buffer;

	sound.setVolume(100.f);

	std::string wavPath = path + "pass-level.wav";

	if (!buffer.loadFromFile(wavPath))
		return; // error

	sound.setBuffer(buffer);
	sound.play();

	Sleep(1000);
}

//-------------------

void borderGame()
{
	mu.lock();

	gotoXY(minBX, minBY);
	for (int i = 0; i < width; i++) {
		TextColor(15);
		cout << char(220);
	}

	gotoXY(minBX, maxBY);
	for (int i = 0; i < width; i++) {
		TextColor(15);
		cout << char(223);
	}

	for (int i = minBY + 1; i < maxBY; i++) {
		gotoXY(minBX, i); cout << char(219);
	}

	for (int i = minBY + 1; i < maxBY; i++) {
		gotoXY(maxBX - 1, i); cout << char(219);
	}

	mu.unlock();
}

void borderMenu()
{
	mu.lock();

	TextColor(14);
	gotoXY(m_start + 3, 15); cout << "Press [P] to pause";

	TextColor(14);
	gotoXY(m_start + 3, 16); cout << "Press [L] to save";

	TextColor(14);
	gotoXY(m_start + 3, 17); cout << "Press [T] to load";

	//---------------------

	gotoXY(m_start, minBY);
	for (int i = 0; i < minBX - m_start - 1; i++) {
		TextColor(15);
		cout << char(220);
	}

	gotoXY(m_start, maxBY);
	for (int i = 0; i < minBX - m_start - 1; i++) {
		TextColor(15);
		cout << char(223);
	}

	for (int i = minBY + 1; i < maxBY; i++) {
		gotoXY(m_start, i); cout << char(219);
	}

	for (int i = minBY + 1; i < maxBY; i++) {
		gotoXY(minBX - m_start, i); cout << char(219);
	}

	mu.unlock();
}

void gameName()
{
	TextColor(13);
	gotoXY(15, 5); cout << "  " << (char)219 << (char)223 << (char)223 << (char)223
		<< " " << (char)219 << (char)223 << (char)223 << (char)220
		<< "   " << (char)220 << (char)219 << (char)223 << (char)219 << (char)220
		<< "    " << (char)220 << (char)219 << (char)223
		<< "   " << (char)220 << (char)219 << (char)223

		<< "                      "

		<< "     " << (char)219 << (char)223 << (char)223 << (char)220
		<< "   " << (char)220 << (char)219 << (char)223 << (char)219 << (char)220
		<< "   " << (char)219 << (char)223 << (char)223 << (char)219
		<< "  " << (char)219 << (char)223 << (char)223 << (char)219;

	TextColor(12);
	gotoXY(15, 6); cout << " " << (char)219 << (char)223
		<< "    " << (char)219 << "   " << (char)219
		<< " " << (char)220 << (char)219 << "   " << (char)219 << (char)220
		<< " " << (char)220 << (char)219 << (char)223
		<< "   " << (char)220 << (char)219 << (char)223

		<< "                      "

		<< "       " << (char)219 << "   " << (char)219
		<< " " << (char)220 << (char)219 << "   " << (char)219 << (char)220
		<< " " << (char)219 << (char)223 << "  " << (char)223 << (char)219
		<< " " << (char)219 << "   " << (char)219;

	TextColor(14);
	gotoXY(15, 7); cout << (char)219 << (char)219
		<< "     " << (char)219 << (char)220 << (char)220 << (char)223
		<< "  " << (char)219 << "     " << (char)219
		<< "  " << (char)223 << (char)219 << (char)220
		<< "   " << (char)223 << (char)219 << (char)220

		<< "      " << (char)223 << (char)223 << (char)219 << (char)223 << (char)223
		<< " " << (char)219 << "   " << (char)219
		<< " " << (char)219 << (char)223 << (char)223 << (char)223 << (char)223

		<< "     " << (char)219 << (char)220 << (char)220 << (char)223
		<< "  " << (char)219 << "     " << (char)219
		<< " " << (char)219 << (char)254 << (char)254 << (char)254 << (char)254 << (char)219
		<< " " << (char)219 << "    " << (char)219;

	TextColor(10);
	gotoXY(15, 8); cout << " " << (char)219 << (char)220
		<< "    " << (char)219 << "  " << (char)223 << (char)220
		<< " " << (char)223 << (char)219 << "   " << (char)219 << (char)223
		<< "   " << (char)220 << (char)219 << (char)223
		<< "   " << (char)220 << (char)219 << (char)223

		<< "     " << "  " << (char)219 << "  "
		<< " " << (char)219 << (char)254 << (char)254 << (char)254 << (char)219
		<< " " << (char)219 << (char)254 << (char)254 << (char)254 << (char)254

		<< "     " << (char)219 << "  " << (char)223 << (char)220
		<< " " << (char)223 << (char)219 << "   " << (char)219 << (char)223
		<< " " << (char)219 << "    " << (char)219
		<< " " << (char)219 << "   " << (char)219;

	TextColor(11);
	gotoXY(15, 9); cout << "  " << (char)219 << (char)220 << (char)220 << (char)220
		<< " " << (char)219 << "   " << (char)219
		<< "  " << (char)223 << (char)219 << (char)220 << (char)219 << (char)223
		<< "  " << (char)220 << (char)219 << (char)223
		<< "   " << (char)220 << (char)219 << (char)223

		<< "       " << "  " << (char)219 << "  "
		<< " " << (char)219 << "   " << (char)219
		<< " " << (char)219 << (char)220 << (char)220 << (char)220 << (char)220

		<< "     " << (char)219 << "   " << (char)219
		<< "  " << (char)223 << (char)219 << (char)220 << (char)219 << (char)223
		<< "  " << (char)219 << "    " << (char)219
		<< " " << (char)219 << (char)220 << (char)220 << (char)219;
}

//-------------------

CGAME::CGAME()
{
	level[1] = new Level(2, 2, 2, 2, 4, 1);
	level[2] = new Level(3, 3, 3, 3, 5, 2);
	level[3] = new Level(4, 4, 4, 4, 5, 3);
	level[4] = new Level(5, 5, 5, 5, 5, 4);
	level[5] = new Level(6, 6, 6, 6, 6, 5);
	level[6] = new Level(7, 7, 7, 7, 7, 6);
	level[7] = new Level(8, 8, 8, 8, 7, 7);
	level[8] = new Level(9, 9, 9, 9, 7, 8);

	curLevel = 1;

	initBird(birdWav);
	initDino(dinoWav);
	initTruck(truckWav);
	initCar(carWav);
}

CGAME::~CGAME()
{
	for(int i = 0; i < level[curLevel]->getBird() ; ++i)
		if (ac[i] != NULL) delete ac[i];

	for (int i = 0; i < level[curLevel]->getDino(); ++i)
		if (akl[i] != NULL) delete akl[i];

	for (int i = 0; i < level[curLevel]->getTruck(); ++i)
		if (axt[i] != NULL) delete axt[i];

	for (int i = 0; i < level[curLevel]->getCar(); ++i)
		if (ach[i] != NULL) delete ach[i];

	for (int i = 0; i < maxLevel; ++i)
		if (level[i] != NULL) delete level[i];

	delete cn;
	delete cl;

	birdWav.clear();
	dinoWav.clear();
	truckWav.clear();
	carWav.clear();
}

//-------------------

void CGAME::drawGame()
{
	clrscr();

	cn = new CPEOPLE();
	cl = new CTRAFFICLIGHT();

	inGameMenu(step, 4);

	borderGame();
	borderMenu();

	setLevel();

	drawLevel();

	cl->drawGreenLight();
}

void CGAME::drawNum()
{
	switch (curLevel)
	{
	case 1:
		gotoXY(minBX + 30, 1); cout << " " << (char)220 << (char)219;
		gotoXY(minBX + 30, 2); cout << (char)223 << " " << (char)219;
		gotoXY(minBX + 30, 3); cout << (char)220 << (char)220 << (char)219 << (char)220;
		break;
	case 2:
		gotoXY(minBX + 30, 1); cout << (char)220 << (char)223 << (char)223 << (char)220;
		gotoXY(minBX + 30, 2); cout << " " << (char)220 << (char)223;
		gotoXY(minBX + 30, 3); cout << (char)219 << (char)220 << (char)220 << (char)220;
		break;
	case 3:
		gotoXY(minBX + 30, 1); cout << (char)220 << (char)223 << (char)223 << (char)220;
		gotoXY(minBX + 30, 2); cout << "  " << (char)223 << (char)220;
		gotoXY(minBX + 30, 3); cout << (char)223 << (char)220 << (char)220 << (char)223;
		break;
	case 4:
		gotoXY(minBX + 30, 1); cout << " " << (char)220 << (char)223 << " ";
		gotoXY(minBX + 30, 2); cout << (char)219 << (char)220 << (char)220 << (char)219;
		gotoXY(minBX + 30, 3); cout << "   " << (char)219;
		break;
	case 5:
		gotoXY(minBX + 30, 1); cout << (char)219 << (char)223 << (char)223 << (char)223;
		gotoXY(minBX + 30, 2); cout << (char)223 << (char)223 << (char)223 << (char)220;
		gotoXY(minBX + 30, 3); cout << (char)220 << (char)220 << (char)220 << (char)223;
		break;
	case 6:
		gotoXY(minBX + 30, 1); cout << (char)220 << (char)223 << (char)223 << (char)223;
		gotoXY(minBX + 30, 2); cout << (char)219 << (char)223 << (char)223 << (char)220;
		gotoXY(minBX + 30, 3); cout << (char)223 << (char)220 << (char)220 << (char)223;
		break;
	case 7:
		gotoXY(minBX + 30, 1); cout << (char)223 << (char)223 << (char)223 << (char)219;
		gotoXY(minBX + 30, 2); cout << " " << (char)220 << (char)223 << " ";
		gotoXY(minBX + 30, 3); cout << " " << (char)219 << "  ";
		break;
	case 8:
		gotoXY(minBX + 30, 1); cout << (char)220 << (char)223 << (char)223 << (char)220;
		gotoXY(minBX + 30, 2); cout << (char)220 << (char)223 << (char)223 << (char)220;
		gotoXY(minBX + 30, 3); cout << (char)223 << (char)220 << (char)220 << (char)223;
		break;
	default:
		break;
	}
}

void CGAME::drawLevel()
{
	mu.lock();

	gotoXY(minBX, 1); cout << (char)219 << "   "
		<< " " << (char)219 << (char)223 << (char)223 << (char)223
		<< " " << (char)219 << "   " << (char)219
		<< " " << (char)219 << (char)223 << (char)223 << (char)223
		<< " " << (char)219 << "   ";

	gotoXY(minBX, 2); cout << (char)219 << "   "
		<< " " << (char)219 << (char)254 << (char)254 << (char)254
		<< " " << (char)219 << (char)220 << " " << (char)220 << (char)219
		<< " " << (char)219 << (char)254 << (char)254 << (char)254
		<< " " << (char)219 << "   ";

	gotoXY(minBX, 3); cout << (char)219 << (char)220 << (char)220 << (char)220
		<< " " << (char)219 << (char)220 << (char)220 << (char)220
		<< "  " << (char)223 << (char)219 << (char)223 << " "
		<< " " << (char)219 << (char)220 << (char)220 << (char)220
		<< " " << (char)219 << (char)220 << (char)220 << (char)220;

	drawNum();

	mu.unlock();
}

//-------------------

CPEOPLE* CGAME::getPeople()
{
	return cn;
}

CTRAFFICLIGHT* CGAME::getTLight()
{
	return cl;
}

//-------------------

void CGAME::setLevel()
{
	for (int i = 0; i < level[curLevel]->getBird(); i++)
		ac[i] = NULL;

	for (int i = 0; i < level[curLevel]->getDino(); i++)
		akl[i] = NULL;

	for (int i = 0; i < level[curLevel]->getTruck(); i++)
		axt[i] = NULL;

	for (int i = 0; i < level[curLevel]->getCar(); i++)
		ach[i] = NULL;
}

int CGAME::currentLevel()
{
	return curLevel;
}

void CGAME::updateLevel()
{
	for (int i = 0; i < level[curLevel]->getBird(); ++i)
		if (ac[i] != NULL) delete ac[i];

	for (int i = 0; i < level[curLevel]->getDino(); ++i)
		if (akl[i] != NULL) delete akl[i];

	for (int i = 0; i < level[curLevel]->getTruck(); ++i)
		if (axt[i] != NULL) delete axt[i];

	for (int i = 0; i < level[curLevel]->getCar(); ++i)
		if (ach[i] != NULL) delete ach[i];

	delete cn;
	delete cl;

	++curLevel;

	levelUpMusic();

	if (curLevel != maxLevel) 
		drawGame();
}

bool CGAME::finishGame()
{
	if (curLevel == maxLevel) return true;
	return false;
}

//-------------------

void CGAME::startGame()
{
	drawGame();
}

void CGAME::pauseGame(void*)
{
	mu.lock();
	_getch();
	mu.unlock();
}

void CGAME::resumeGame(void*) { }

void CGAME::setDead() {
	cn->setState(false);
}

void CGAME::resetGame(void*) {
	return;
}

void CGAME::exitGame(void*) {
	//
}

//-------------------

string savePath;
void CGAME::saveGame(void*)
{
	TextColor(7);

	mu.lock();
	gotoXY(m_start + 3, 19);
	cout << "Enter your saving path:\n";
	gotoXY(m_start + 3, 20);
	getline(cin, savePath);

	ofstream fout;
	fout.open(savePath);
	fout.close();

	fstream save;

	mu.unlock();
}

string loadPath;
void CGAME::loadGame(void*)
{
	mu.lock();
	gotoXY(m_start + 3, 19);
	cout << "Enter your saving path:\n";
	gotoXY(m_start + 3, 20);
	getline(cin, loadPath);
	mu.unlock();

	ofstream fout;
	fout.open(loadPath);

	fstream save;

}

//-------------------

int CGAME::laneY(int y)
{
	switch (curLevel)
	{
	case 1: 
		return (minBY + y * 5);
	case 2: case 3:
		return (minBY + y * 4);
	case 4: case 5:
		return (minBY + 2 + y * 3);
	case 6: case 7: case 8:
		return (minBY + y * 3);
	default:
		break;
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
		if (y > minBY + 1) cn->UP();
		break;
	case DOWN:
		if (y < maxBY - 1) cn->DOWN();
		break;
	case RIGHT:
		if (x < maxBX + 1) cn->RIGHT();
		break;
	case LEFT:
		if (x > minBX - 1) cn->LEFT();
		break;
	case ENTER:
		return;
	}

	x = cn->getX(), y = cn->getY();

	mu.lock();
	gotoXY(x, y); cout << "Y";
	mu.unlock();

	if (cn->isFinish()) 
	{
		gotoXY(x, y); cout << " ";
		updateLevel();
	}
}

void CGAME::updatePosVehicle() 
{
	for (int i = 0; i < level[curLevel]->getTruck(); ++i)
	{
		if (axt[i] == NULL || axt[i]->IsEndOfLane())
		{
			if (axt[i] != NULL) delete axt[i];

			int x = 5 + (rand() % 4) * 7;
			int y = 1 + rand() % (level[curLevel]->getLane());

			if (y % 2 == 0)
			{
				axt[i] = new CTRUCK(maxBX + x, laneY(y), -1);
//				axt[i]->Tell();
			}
			else
			{
				axt[i] = new CTRUCK(minBX - x, laneY(y), 1);
//				axt[i]->Tell();
			}
		}
		else axt[i]->Move();
	}

	for (int i = 0; i < level[curLevel]->getCar(); ++i)
	{
		if (ach[i] == NULL || ach[i]->IsEndOfLane())
		{
			if (ach[i] != NULL) delete ach[i];

			int x = 5 + (rand() % 4) * 7;
			int y = 1 + rand() % (level[curLevel]->getLane());

			if (y % 2 == 0)
			{
				ach[i] = new CCAR(maxBX + x, laneY(y), -1);
//				ach[i]->Tell();
			}
			else
			{
				ach[i] = new CCAR(minBX - x, laneY(y), 1);
//				ach[i]->Tell();
			}
		}
		else ach[i]->Move();
	}
}

void CGAME::updatePosAnimal()
{
	for (int i = 0; i < level[curLevel]->getBird(); ++i)
	{
		if (ac[i] == NULL || ac[i]->IsEndOfLane())
		{
			if (ac[i] != NULL) delete ac[i];

			int x = 5 + (rand() % 4) * 7;
			int y = 1 + rand() % (level[curLevel]->getLane());

			if (y % 2 == 0)
			{
				ac[i] = new CBIRD(maxBX + x, laneY(y), -1);
//				ac[i]->Tell();
			}
			else
			{
				ac[i] = new CBIRD(minBX - x, laneY(y), 1);
//				ac[i]->Tell();
			}
		}
		else ac[i]->Move();
	}

	for (int i = 0; i < level[curLevel]->getDino(); ++i)
	{
		if (akl[i] == NULL || akl[i]->IsEndOfLane())
		{
			if (akl[i] != NULL) delete akl[i];

			int x = 5 + (rand() % 4) * 7;
			int y = 1 + rand() % (level[curLevel]->getLane());

			if (y % 2 == 0)
			{
				akl[i] = new CDINOSAUR(maxBX + x, laneY(y), -1);
//				akl[i]->Tell();
			}
			else
			{
				akl[i] = new CDINOSAUR(minBX - x, laneY(y), 1);
//				akl[i]->Tell();
			}
		}
		else akl[i]->Move();
	}
}

bool CGAME::impact()
{
	for (int i = 1; i <= level[curLevel]->getLane(); ++i)
	{
		int y = laneY(i);
		if (cn->getY() == y || cn->getY() == y + 1)
		{
			if (cn->isImpact(ac, level[curLevel]->getBird())) return true;
			if (cn->isImpact(akl, level[curLevel]->getDino())) return true;
			if (cn->isImpact(axt, level[curLevel]->getTruck())) return true;
			if (cn->isImpact(ach, level[curLevel]->getCar())) return true;
		}
	}
	return false;
}
