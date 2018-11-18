#include "CGAME.h"
#include "Menu.h"
#include "console.h"
#include "SettingUp.h"
#include <iostream>
using namespace std;

void controlPeople() {
	char people = 'Y';
	int columns, rows;

	GetConsoleSize(columns, rows);

	int x = 0, y = 0;
	while (1) {
		clrscr();
		gotoXY(x, y);
		cout << people;

		//Kiem tra key nhap vao
		int z = _getch();
		State stat = key(z);
		switch (stat) {
		case UP:
			if (y == 0)
				y = 0;
			else
				y -= 1;
			break;
		case DOWN:
			if (y == rows)
				y = rows;
			else
				y += 1;
			break;
		case RIGHT:
			if (x == columns)
				x = columns;
			else
				x += 1;
			break;
		case LEFT:
			if (x == 0)
				x = 0;
			else
				x -= 1;
			break;
		case ENTER:
			return;
		}
	}
}