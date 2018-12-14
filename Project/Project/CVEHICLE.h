#pragma once
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <time.h>
#include <vector>

using namespace std;

class CVEHICLE 
{
protected:
	int mX, mY;
	int random;
	int direction;

	sf::Sound sound;
	sf::SoundBuffer buffer;

public:
	CVEHICLE(int, int, int);

	int getX() { return mX; }
	int getY() { return mY; }

	virtual void Draw(int, int) = 0;
	virtual void Tell() = 0;
	
	void Move();
	bool IsEndOfLane();

	virtual ~CVEHICLE() { }
};

class CTRUCK : public CVEHICLE
{
public:
	CTRUCK(int, int, int);

	void Draw(int, int);
	void Tell();

	~CTRUCK() { }
};

class CCAR : public CVEHICLE 
{
public:
	CCAR(int, int, int);

	void Draw(int, int);
	void Tell();

	~CCAR() { }
};

void initTruck(std::vector<std::string> &truckWav);
void initCar(std::vector<std::string> &carWav);