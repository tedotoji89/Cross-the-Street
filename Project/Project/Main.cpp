#include "CGAME.h"
#include "Menu.h"
#include "SetUp.h"
#include "Console.h"
#include <thread>

extern CGAME* cg;
char MOVING;

bool p_run = true;
bool g_play = true;
extern bool light_set;

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

//	gameName();
//	Sleep(2000);

	cg = new CGAME();
	int temp;

	cg->startGame();


	thread t1(subThread);

	while (g_play)
	{
		temp = toupper(_getch());

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

	return 0;
}