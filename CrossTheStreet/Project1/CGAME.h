#pragma once
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

const string path = "D:\\Final Project\\Year 2 - Semester 1\\Sound\\";

extern string savePath;
extern mutex mu;
extern int maxBird;
extern int maxDino;
extern int maxCar;
extern int maxTruck;
extern int maxX;
extern int maxY;
extern int minX;
extern int minY;

class CGAME 
{
private:
	CTRUCK* axt;
	CCAR* ach;
	CDINOSAUR* akl;
	CBIRD* ac;
	CPEOPLE* cn;

public:
	CGAME();
	~CGAME();
	void drawGame();

	CPEOPLE getPeople();
	CVEHICLE* getVehicle();
	CANIMAL* getAnimal();
	
	void setDead();
	void resetGame();
	void exitGame(void*);
	void startGame();
	void saveGame();
	void pauseGame(void*);
	void resumeGame(void*);
	void clrScr();
	
	void updatePosPeople(int);
	void updatePosVehicle();
	void updatePosAnimal();
};

void controlPeople();
void border();