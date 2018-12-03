#pragma once

class CVEHICLE {
protected:
	int mX, mY;
	int level;
public:
	virtual void render();
	virtual void clr();
	virtual void move();
	//virtual void Tell();
};

class CCAR : public CVEHICLE {
public:
	CCAR();
	void render();
	void move();
	void clr();
};

class CTRUCK : public CVEHICLE {
public:
	CTRUCK();
	void render();
	void move();
	void clr();
};

void runMultiCar();
void runMultiTruck();