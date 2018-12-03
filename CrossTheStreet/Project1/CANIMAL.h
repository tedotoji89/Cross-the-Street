#pragma once

class CANIMAL {
protected:
	int mX, mY;
	int level;
public:
	int getX() { return mX; }
	int getY() { return mY; }
	virtual void render();
	virtual void clr();
	virtual void move();
	//virtual void Tell();
};

class CBIRD : public CANIMAL {
public:
	CBIRD();
	void render();
	void move();
	void clr();
};

class CDINOSAUR : public CANIMAL {
public:
	CDINOSAUR();
	void render();
	void move();
	void clr();
};

void runMultiBird(CBIRD);
void runMultiDino();