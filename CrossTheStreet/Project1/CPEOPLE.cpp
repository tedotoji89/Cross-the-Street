#include "CPEOPLE.h"
#include "console.h"
#include "CGAME.h"

CPEOPLE::CPEOPLE() 
{
	mX = 60;
	mY = 7;
	mState = true; //Alive
}

void CPEOPLE::draw() {
	gotoXY(mX, mY); 
	cout << 'Y';
}

void CPEOPLE::UP() { mY -= 1; }

void CPEOPLE::LEFT() { mX -= 1; }

void CPEOPLE::RIGHT() { mX += 1; }

void CPEOPLE::DOWN() { mY += 1; }

bool CPEOPLE::isImpactAni(CANIMAL *obt) { 
	for (int i = 0; i < maxBird; i++) {
		if (mX == obt->getX() && mY == obt->getY()) {
			return true;
		}
		obt++;
	}
	return false; 
}

bool CPEOPLE::isImpactVehi(CVEHICLE *obt) { 
	for (int i = 0; i < maxBird; i++) {
		if (mX == obt->getX() && mY == obt->getY()) {
			return true;
		}
		obt++;
	}
	return false;
}

bool CPEOPLE::isFinish() 
{ 
	if (mY >= 24)
		return true;
	return false;
}

bool CPEOPLE::isDead() { 
	return (!mState ? true : false); 
}

CPEOPLE::~CPEOPLE() 
{
	mX = 0;
	mY = 0;
	mState = true; // Alive
}
