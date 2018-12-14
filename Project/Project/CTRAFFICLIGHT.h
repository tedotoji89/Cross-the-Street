#pragma once

class CTRAFFICLIGHT
{
private:
	int sec;
	int timer;
	bool light_stop;

public:
	CTRAFFICLIGHT();

	void eraseLight();
	void drawRedLight();
	void drawGreenLight();

	bool getLight();
	void setLight();

	void setSec();
	int getSec();

	int getTime();
	void countUp();
	void resetTimer();

	~CTRAFFICLIGHT() { };
};
