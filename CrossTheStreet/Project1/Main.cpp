#include "CGAME.h"
#include "Menu.h"
#include "SetUp.h"
#include <curses.h>
#include <thread>

int maxBird = 6, 
	maxDino = 6,
	maxCar = 6, 
	maxTruck = 6;
int minX = 30,
	minY = 6,
	maxX = 91,
	maxY = 26;

void runMultiBird(CANIMAL* bird) {
	while (true)
	{
		for (int i = 0; i < 60; i++) {
			bird->Draw();
			Sleep(100);
			bird->clr();
			bird->move();
		}
		bird++;
	}
}


int main() 
{
	keypad(initscr(), 1);

	curs_set(0);

	ShowConsoleCursor(false);
	FixConsoleWindow();


	//cg.startGame();
	Routes();

	endwin();

	return 0;
}