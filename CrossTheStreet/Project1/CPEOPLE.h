#pragma once
#include "CVEHICLE.h"
#include "CANIMAL.h"

class CPEOPLE {
private:
	int mX, mY;
	bool mState;
public:
	CPEOPLE();
	int getX() { return mX; }
	int getY() { return mY; }
	void UP();
	void LEFT();
	void RIGHT();
	void DOWN();
	bool isImpact(CANIMAL);
	bool isImpact(const CVEHICLE*&);
	bool isFinish();
	bool isDead();
	~CPEOPLE();
};