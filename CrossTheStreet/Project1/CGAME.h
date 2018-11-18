#pragma once
#ifndef _CGAME_H_
#define _CGAME_H_

class CGAME {
public:
	CGAME ();
	void drawGame();
	~CGAME ();

	//CPEOPLE getPeople();
	//CVEHICLE getVehicle();
	//CANIMAL getAnimal();
	void resetGame();
	void exitGame();
	void startGame();
	void saveGame();

private:
	//CTRUCK* axt;
	//CCAR* ach;
	//CDINAUSOR* akl;
	//CBIRD* ac;
	//CPEOPLE* cn;
};


void controlPeople();
#endif // !_CGAME_H_
