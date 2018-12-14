#pragma once
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"
#include "CTRAFFICLIGHT.h"

#include <mutex>
#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//const string path = "D:\\Final Project\\Year 2 - Semester 1\\Sound\\";
const string path = "C:\\Users\\tedot\\Desktop\\Cross-the-Street\\Sound\\";

extern string savePath;
extern string loadPath;
extern mutex mu;

extern vector<string> birdWav;
extern vector<string> dinoWav;
extern vector<string> truckWav;
extern vector<string> carWav;

extern bool p_run;
extern bool g_play;

const int minBX = 35, maxBX = 115, minBY = 5, maxBY = 28;
const int width = maxBX - minBX;
const int height = maxBY - minBY;

const int m_start = 2;
const int maxLevel = 8, maxObj = 10;

class Level
{
private:
	int maxBird, maxDino, maxTruck, maxCar;
	int lane, speed;

public:
	Level(int bird, int dino, int truck, int car, int l, int s)
	{
		maxBird = bird;
		maxDino = dino;
		maxTruck = truck;
		maxCar = car;

		lane = l;
		speed = s;
	}

	int getBird() { return maxBird; }
	int getDino() { return maxDino; }
	int getCar() { return maxCar; }
	int getTruck() { return maxTruck; }
	int getLane() { return lane; }
	int getSpeed() { return speed; }
};

class CGAME
{
private:
	CTRUCK* axt[maxObj];
	CCAR* ach[maxObj];
	CDINOSAUR* akl[maxObj];
	CBIRD* ac[maxObj];

	CPEOPLE* cn;
	CTRAFFICLIGHT* cl;

	Level* level[maxLevel];
	int curLevel;
	int end;

public:
	CGAME();
	~CGAME();

	void drawGame();
	void drawNum();
	void drawLevel();

	CPEOPLE* getPeople();
	CTRAFFICLIGHT* getTLight();

	int currentLevel();
	void setDead();

	void setLevel();
	void updateLevel();

	bool finishGame();

	void startGame();

	void pauseGame(void*);
	void resumeGame(void*);
	void resetGame();
	void exitGame(void*);

	void loadGame(void*);
	void saveGame(void*);

	void updatePosPeople(int);
	void updatePosVehicle();
	void updatePosAnimal();

	bool impact();

	int getSpeed() { return level[curLevel]->getSpeed(); }
	int laneY(int);
};

void borderGame();
void borderMenu();

void gameName();
void backgroundMusic(sf::Sound& sound, sf::SoundBuffer& buffer);
void levelUpMusic();