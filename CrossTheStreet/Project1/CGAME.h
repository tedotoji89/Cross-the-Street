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

class CGAME 
{
private:
	CTRUCK* axt;
	CCAR* ach;
	CDINOSAUR akl;
	CBIRD ac;
	CPEOPLE* cn;

public:
	CGAME();
	~CGAME();
	void drawGame();

	CPEOPLE getPeople();
	CVEHICLE getVehicle();
	CANIMAL getAnimal();
	
	void resetGame();
	void exitGame();
	void startGame();
	void saveGame();
	//void pauseGame(HANDLE);
	//void resumeGame(HANDLE);
	
	void updatePosPeople(int);
	void updatePosVehicle();
	void updatePosAnimal();
};

void controlPeople();
void border();