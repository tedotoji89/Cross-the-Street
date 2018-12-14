#include "CPEOPLE.h"
#include "console.h"
#include "CGAME.h"

CPEOPLE::CPEOPLE()
{
	mX = (minBX + maxBX) / 2;
	mY = minBY + 1;

	mState = true; //Alive
}

void CPEOPLE::draw() 
{
	TextColor(14);
	mu.lock();
	gotoXY(mX, mY);
	cout << 'Y';
	mu.unlock();
}

void CPEOPLE::UP() { mY -= 1; }

void CPEOPLE::LEFT() { mX -= 1; }

void CPEOPLE::RIGHT() { mX += 1; }

void CPEOPLE::DOWN() { mY += 1; }

bool CPEOPLE::isImpact(CBIRD* ani[], int n) 
{
	for (int i = 0; i < n; ++i)
	{
		if (ani[i] != NULL)
		{
			int x = ani[i]->getX();
			int y = ani[i]->getY();
			if (mY == ani[i]->getY() && mX >= ani[i]->getX() && mX <= ani[i]->getX() + 2)
				return true;
		}
	}
	return false;
}

bool CPEOPLE::isImpact(CDINOSAUR* ani[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (ani[i] != NULL)
		{
			int x = ani[i]->getX();
			int y = ani[i]->getY();
			if (mY >= y - 1 && mY <= y && mX >= x && mX <= x + 3)
				return true;
		}
	}
	return false;
}

bool CPEOPLE::isImpact(CTRUCK* vehi[], int n) 
{
	for (int i = 0; i < n; ++i)
	{
		if (vehi[i] != NULL)
		{
			int x = vehi[i]->getX();
			int y = vehi[i]->getY();
			if (mY == y && mX >= x && mX <= x + 2)
				return true;
		}
	}
	return false;
}

bool CPEOPLE::isImpact(CCAR* vehi[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (vehi[i] != NULL)
		{
			int x = vehi[i]->getX();
			int y = vehi[i]->getY();
			if (mY == y && mX >= x && mX <= x + 2)
				return true;
		}
	}
	return false;
}

bool CPEOPLE::isFinish()
{
	if (mY == 27)
		return true;
	return false;
}

bool CPEOPLE::isDead() 
{
	return (!mState ? true : false);
}

CPEOPLE::~CPEOPLE()
{
	mX = 0;
	mY = 0;
	mState = true; // Alive
}
