#pragma once
#ifndef _SETTINGUP_H_
#define _SETTINGUP_H_

#define _WIN32_WINNT 0x0500
#include <windows.h>

void FixConsoleWindow();
void ShowConsoleCursor(bool showFlag);
void GetConsoleSize(int & columns, int & rows);

#endif // !_SETTINGUP_H_
