#include "CTRAFFICLIGHT.h"
#include "CGAME.h"
#include "Console.h"

CTRAFFICLIGHT::CTRAFFICLIGHT()
{
	light_stop = false;
	srand(time(NULL));
	sec = 10 + (rand() % 11);
	timer = 0;
}

void CTRAFFICLIGHT::eraseLight()
{
	mu.lock();
	gotoXY(maxBX - 4, 0); cout << "    ";
	gotoXY(maxBX - 4, 1); cout << "    ";
	gotoXY(maxBX - 4, 2); cout << "    ";
	gotoXY(maxBX - 4, 3); cout << "    ";
	gotoXY(maxBX - 4, 4); cout << "    ";
	mu.unlock();
}
void CTRAFFICLIGHT::drawRedLight()
{
	mu.lock();
	TextColor(12);
	gotoXY(maxBX - 3, 1); cout << (char)219 << (char)219;

	TextColor(15);
	gotoXY(maxBX - 4, 0); cout << (char)220 << (char)220 << (char)220 << (char)220;
	gotoXY(maxBX - 4, 1); cout << (char)219;
	gotoXY(maxBX - 1, 1); cout << (char)219;
	gotoXY(maxBX - 4, 2); cout << (char)223 << (char)223 << (char)223 << (char)223;
	mu.unlock();
}
void CTRAFFICLIGHT::drawGreenLight()
{
	mu.lock();
	TextColor(10);
	gotoXY(maxBX - 3, 3); cout << (char)219 << (char)219;

	TextColor(15);
	gotoXY(maxBX - 4, 2); cout << (char)220 << (char)220 << (char)220 << (char)220;
	gotoXY(maxBX - 4, 3); cout << (char)219;
	gotoXY(maxBX - 1, 3); cout << (char)219;
	gotoXY(maxBX - 4, 4); cout << (char)223 << (char)223 << (char)223 << (char)223;
	mu.unlock();
}

bool CTRAFFICLIGHT::getLight() { return light_stop; }
void CTRAFFICLIGHT::setLight()
{
	if (light_stop == true)
		light_stop = false;
	else
		light_stop = true;
}

void CTRAFFICLIGHT::setSec()
{
	srand(time(NULL));
	sec = 10 + (rand() % 11);
}
int CTRAFFICLIGHT::getSec() { return sec; }

int CTRAFFICLIGHT::getTime() { return timer; }
void CTRAFFICLIGHT::countUp()
{
	++timer;
}
void CTRAFFICLIGHT::reserTimer()
{
	timer = 0;
}
