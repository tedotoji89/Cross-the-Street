#pragma once
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <time.h>
#include <vector>

class Point
{
private:
	int X;
	int Y;
	friend class CANIMAL;
};

class CANIMAL
{
protected:
	int mX, mY;
	int level;
	int random;
	//vector <CANIMAL*> a;

	Point topLeft, bottomRight;

	sf::Sound sound;
	sf::SoundBuffer buffer;

public:
	CANIMAL() = default;

	int getX() { return mX; }
	int getY() { return mY; }
	void setX(int x) { mX = x; }
	void setY(int y) { mY = y; }

	virtual void Draw();
	virtual void Tell(std::vector<std::string>&);
	virtual void move();
	virtual void clr();
};

class CBIRD : public CANIMAL
{
public:
	CBIRD();

	void Draw();
	void Tell(std::vector<std::string>& birdWav);
	void move();
	void clr();
};

class CDINOSAUR : public CANIMAL
{
public:
	CDINOSAUR();

	void Draw();
	void Tell(std::vector<std::string>& dinoWav);
	void move();
	void clr();
};

void initBird(std::vector<std::string>& birdWav);
void initDino(std::vector<std::string>& dinoWav);

void runMultiBird(CBIRD *);
void runMultiDino();