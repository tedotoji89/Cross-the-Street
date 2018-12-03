#pragma once
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"

#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

extern mutex mu;

class CGAME {
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
	void updatePosPeople(char);
	void updatePosVehicle();
	void updatePosAnimal();
private:
	CTRUCK* axt;
	CCAR* ach;
	CDINOSAUR* akl;
	CBIRD ac;
	CPEOPLE* cn;
};


void controlPeople();
void border();