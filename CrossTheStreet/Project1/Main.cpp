#include "CGAME.h"
#include "Menu.h"
#include <thread>
#include "SettingUp.h"

char MOVING;
CGAME cg;
/*
void subThread() 
{
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
	}
}
*/
int main() 
{
	ShowConsoleCursor(false);
	FixConsoleWindow();

	//Routes();

	//thread sub(subThread);

	cg.drawGame();


	system("pause");
	return 0;
}