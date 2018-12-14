#include "CGAME.h"
#include "Menu.h"
#include "SetUp.h"
#include "Console.h"
#include <thread>

CGAME* cg;
char MOVING;

bool p_run = true;
bool g_play = true;
bool light_set = false;

void subThread()
{
	while (g_play)
	{
	//	while (p_run) continue;

		if (!(cg->getPeople())->isDead())
			cg->updatePosPeople(MOVING);

		if (cg->finishGame())
		{
			g_play = false;
			break;
		}

		MOVING = ' ';

		if (!cg->getTLight()->getLight())
		{
			if (light_set == false)
			{
				light_set = true;
				cg->getTLight()->eraseLight();
				cg->getTLight()->drawGreenLight();
			}
			cg->updatePosAnimal();
			cg->updatePosVehicle();
		}
		else
		{
			if (light_set == true)
			{
				light_set = false;
				cg->getTLight()->eraseLight();
				cg->getTLight()->drawRedLight();
			}
		}

		if (cg->impact()) 
		{
			cout << "Haha";
			g_play = false;
			break;
		}

		Sleep(100 / cg->getSpeed());
	}
}

int main()
{
	hidecursor();
	FixConsoleWindow();

	sf::Sound sound;
	sf::SoundBuffer buffer;

	backgroundMusic(sound, buffer);

	gameName();
	Sleep(2000);

	cg = new CGAME();

	int selection = Menu(step, 4);

	switch (selection)
	{
	case 0:
	{
		int temp;

		cg->startGame();

		thread t1(subThread);

		while (g_play) 
		{
			temp = toupper(_getch());

			if (cg->getTLight()->getSec() == cg->getTLight()->getTime())
			{
				cg->getTLight()->setSec();
				cg->getTLight()->reserTimer();
				cg->getTLight()->setLight();
			}
			else cg->getTLight()->countUp();

			if (!cg->getPeople()->isDead()) {
				if (temp == 27) {
					cg->exitGame(t1.native_handle());
					g_play = false;
				}
				else if (temp == 'L') {
					cg->saveGame(t1.native_handle());
				}
				else if (temp == 'P') {
					cg->pauseGame(t1.native_handle());
				}
				else if (temp == 'T') {
					cg->loadGame(t1.native_handle());
				}
				else {
					cg->resumeGame((HANDLE)t1.native_handle());
					MOVING = temp;
				}
			}
			else {
				if (temp == 'Y') cg->startGame();
				else {
					cg->exitGame(t1.native_handle());
					g_play = false;
					delete cg;
				}
			}
		}
		t1.join();
	} break;
	case 1:

		break;
	case 2:
		delete cg;
		break;
	default:
		break;
	}

	return 0;
}