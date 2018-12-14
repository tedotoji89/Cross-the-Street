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
			continue;
		}

		MOVING = ' ';

		if (cg->impact()) 
		{	
			
			int tempX = cg->getPeople()->getX();
			int tempY = cg->getPeople()->getY();
			mu.lock();
			gotoXY(tempX - 1, tempY - 2);	cout << " '.\|/.'";
			gotoXY(tempX - 1, tempY - 1);	cout << " (\   /)";
			gotoXY(tempX - 1, tempY);		cout << " - -O- -";
			gotoXY(tempX - 1, tempY + 1);	cout << " (/   \)";
			gotoXY(tempX - 1, tempY + 2);	cout << " ,'/|\'.";
			gotoXY(m_start + 3, 22); cout << "Want to continue? (Y/N)";
			mu.unlock();

			cg->setDead();
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
	int temp;

	switch (Menu(step, 4))
	{
	case 0: {
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
		break;
	}
	case 2: {
		//cg->loadGame();
	}
	default: {

	}
	}
	

	return 0;
}