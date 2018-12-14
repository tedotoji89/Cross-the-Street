#pragma once
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <time.h>
#include <vector>

using namespace std;

class CANIMAL
{
protected:
	int mX, mY;
	int random;
	int direction;

	sf::Sound sound;
	sf::SoundBuffer buffer;

public:
	CANIMAL(int, int, int);

	int getX() { return mX; }
	int getY() { return mY; }

	virtual void Draw(int, int) = 0;
	virtual void Tell() = 0;

	void Move();
	bool IsEndOfLane();

	virtual ~CANIMAL() { }
};

class CBIRD : public CANIMAL
{
public:
	CBIRD(int, int, int);

	void Draw(int, int);
	void Tell();

	~CBIRD() { }
};

class CDINOSAUR : public CANIMAL
{
public:
	CDINOSAUR(int, int, int);

	void Draw(int, int);
	void Tell();

	~CDINOSAUR() { }
};

void initBird(std::vector<std::string>& birdWav);
void initDino(std::vector<std::string>& dinoWav);
