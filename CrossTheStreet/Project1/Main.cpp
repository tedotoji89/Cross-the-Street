#include<iostream>
#include "Menu.h"
#include "SettingUp.h"
using namespace std;

int main() {
	ShowConsoleCursor(false);
	FixConsoleWindow();
	Routes();

	cout << "Hello";
	
	system("pause");
	return 0;
}