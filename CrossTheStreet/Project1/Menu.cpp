#include "Menu.h"
#include "CGAME.h"
#include "console.h"

#define BACKGROUND_COLOR 176
#define FONT_COLOR 15

//Kiem tra key nhap vao
State key(int z) {
	switch (z) {
	case 119:
		return UP;
	case 97: 
		return LEFT;
	case 115:
		return DOWN;
	case 100:
		return RIGHT;
	case 13:
		return ENTER;
	default:
		break;
	}
}

int Menu(str step[], int n) {
	int st = 0; //Chi ra step hien tai. Mac dinh la step 1
	int *color = new int[n];

	//Chinh mau cho cac selection
	for (int i = 0; i < n; i++) {
		color[i] = FONT_COLOR;
	}
	color[0] = BACKGROUND_COLOR;

	//Su dung 1 vong lap vo han cho toi khi tra ve mot gia tri
	while (1) {
		clrscr();
		
		TextColor(7);
		cout << "Welcome, Friend!!" << endl << endl;

		//In cac selection ra man hinh
		for (int i = 0; i < n; i++) {
			TextColor(color[i]);
			cout << i + 1 << "> " << step[i] << endl;
		}

		//Kiem tra key nhap vao
		int z = _getch();
		State stat = key(z);
		switch (stat) {
		case UP:
			if (st == 0) {
				st = n - 1;
			} else st--;
			break;
		case DOWN:
			if (st == n - 1) {
				st = 0;
			} else st++;
			break;
		case ENTER:
			delete[] color;
			return st;
		}
		//In mau phu hop voi step hien tai
		for (int i = 0; i < n; i++) {
			color[i] = FONT_COLOR;
		}
		color[st] = BACKGROUND_COLOR;
	}
}

void Routes() {
	//Dieu huong sau khi chon
	int selection = Menu(step, 4);
	switch (selection) {
	case 0:
		controlPeople();
		break;
	case 1:
		cout << "You selected option 2" << endl;
		break;
	case 2:
		cout << endl << "Feature is in development!" << endl;
		break;
	default:
		break;
	}
}