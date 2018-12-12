#pragma once
#include <conio.h>

typedef const char str[31];
str step[4] = { "New game", "Load game", "Setting", "Quit game" };

enum State { UP, DOWN, LEFT, RIGHT, ENTER, BACK, ESE };

State key(int z);
int Menu(str step[], int n);
void Routes();
