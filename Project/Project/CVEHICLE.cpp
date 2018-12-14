#include "CVEHICLE.h"
#include "CGAME.h"
#include "Console.h"

vector<string> truckWav;
vector<string> carWav;

//---------------

void initTruck(vector<string> &truckWav)
{
	string truckWav0 = "Semi-Truck-Horn-Honk-1.wav",
		truckWav1 = "Transport-truck-passing-europe.wav",
		truckWav2 = "Transport-truck-rigid-body-pass.wav";

	truckWav.push_back(truckWav0);
	truckWav.push_back(truckWav1);
	truckWav.push_back(truckWav2);
}

void initCar(vector<string> &carWav)
{
	string carWav0 = "Auto-Honda-1.wav",
		carWav1 = "Car-hyundai-trajet-2006-pass-fast-road-beep-horn.wav",
		carWav2 = "Car-hyundai-trajet-2006-pass-slow-road-wind.wav";

	carWav.push_back(carWav0);
	carWav.push_back(carWav1);
	carWav.push_back(carWav2);
}

//---------------

CVEHICLE::CVEHICLE(int x, int y, int dr)
{
	TextColor(7);

	mX = x;
	mY = y;
	direction = dr;
}

void CVEHICLE::Move()
{
	if (mX < maxBX - 3 && mX > minBX)
	{
		mu.lock();
		gotoXY(mX, mY); cout << "   ";
		mu.unlock();
	}
	mX += direction;
	if (mX > 0 && mY > 0) {
		Draw(mX, mY);
	}
}

bool CVEHICLE::IsEndOfLane()
{
	if ((direction == -1 && mX == minBX + 1) || (direction == 1 && mX == maxBX - 4))
	{
		mu.lock();
		gotoXY(mX, mY); cout << "   ";
		mu.unlock();
		
		return true;
	}
	return false;
}

//---------------

CTRUCK::CTRUCK(int x, int y, int dr) : CVEHICLE(x, y, dr) { Draw(x, y);  }

void CTRUCK::Draw(int x, int y) 
{
	if (x <= minBX || x > maxBX - 4) return;

	mu.lock();
	if (direction == 1)
	{
		gotoXY(x, y); cout << char(219) << char(219) << char(220);
	}
	else
	{
		gotoXY(x, y); cout << char(220) << char(219) << char(219);
	}
	mu.unlock();
}

void CTRUCK::Tell()
{
	srand(time(NULL));
	random = rand() % 3 + 0;

	sound.setVolume(60.f);

	string wavPath = path + truckWav[random];

	if (!buffer.loadFromFile(wavPath))
		return; // error

	sound.setBuffer(buffer);
	sound.setPlayingOffset(sf::seconds(5.f));
	sound.play();
}

//---------------

CCAR::CCAR(int x, int y, int dr) : CVEHICLE(x, y, dr) { Draw(x, y); }

void CCAR::Draw(int x, int y)
{
	if (x <= minBX || x > maxBX - 4) return;

	mu.lock();
	gotoXY(x, y); cout << char(220) << char(219) << char(220);
	mu.unlock();
}

void CCAR::Tell()
{
	srand(time(NULL));
	random = rand() % 3 + 0;

	sound.setVolume(60.f);

	string wavPath = path + carWav[random];

	if (!buffer.loadFromFile(wavPath))
		return; // error

	sound.setBuffer(buffer);
	sound.setPlayingOffset(sf::seconds(5.f));
	sound.play();
}