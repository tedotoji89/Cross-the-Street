#include "CANIMAL.h"
#include "CGAME.h"
#include "Console.h"

mutex mu;
vector<string> birdWav;
vector<string> dinoWav;

//---------------

void initBird(vector<string> &birdWav)
{
	std::string birdWav0 = "Harbor-seagulls.wav",
		birdWav1 = "Birds-chirping-sound-effect.wav",
		birdWav2 = "Blackbird-singing-in-the-garden.wav",
		birdWav3 = "House-sparrow-sounds.wav";

	birdWav.push_back(birdWav0);
	birdWav.push_back(birdWav1);
	birdWav.push_back(birdWav2);
	birdWav.push_back(birdWav3);
}

void initDino(vector<string> &dinoWav)
{
	std::string dinoWav0 = "Dinosaur-growl-1.wav",
		dinoWav1 = "Dinosaur-vocalisation-or-growl-1.wav",
		dinoWav2 = "Dinosaur-vocalisation-or-growl-1.wav";

	dinoWav.push_back(dinoWav0);
	dinoWav.push_back(dinoWav1);
	dinoWav.push_back(dinoWav2);
}

//---------------

CANIMAL::CANIMAL(int x, int y, int dr)
{
	TextColor(7);

	mX = x;
	mY = y;
	direction = dr;
}

void CANIMAL::Move()
{
	if (mX < maxBX - 3 && mX > minBX) 
	{
		mu.lock();
		gotoXY(mX, mY - 1);	cout << "   ";
		gotoXY(mX, mY); cout << "   ";
		mu.unlock();
	}
	mX += direction;
	if (mX > 0 && mY > 0) {
		Draw(mX, mY);
	}
}

bool CANIMAL::IsEndOfLane()
{
	if ((direction == -1 && mX == minBX + 1) || (direction == 1 && mX == maxBX - 4)) 
	{
		mu.lock();
		gotoXY(mX, mY - 1);	cout << "   ";
		gotoXY(mX, mY); cout << "   ";
		mu.unlock();

		return true;
	}
	return false;
}

//---------------

CBIRD::CBIRD(int x, int y, int dr) : CANIMAL(x, y, dr) { Draw(x, y); }

void CBIRD::Draw(int x, int y)
{
	if (x <= minBX || x > maxBX - 4) return;

	mu.lock();
	gotoXY(x, y); cout << char(223) << char(254) << char(223);
	mu.unlock();
}

void CBIRD::Tell()
{
	srand(time(NULL));
	random = rand() % 4 + 0;

	sound.setVolume(35.f);

	std::string wavPath = path + birdWav[random];

	if (!buffer.loadFromFile(wavPath))
		return; // error

	sound.setBuffer(buffer);
	sound.setPlayingOffset(sf::seconds(5.f));
	sound.play();
}

//---------------

CDINOSAUR::CDINOSAUR(int x, int y, int dr) : CANIMAL(x, y, dr) { Draw(x, y); }

void CDINOSAUR::Draw(int x, int y)
{
	if (x <= minBX || x > maxBX - 4) return;

	mu.lock();
	if (direction == 1)
	{
		gotoXY(x, y - 1); cout << "  " << char(220);
		gotoXY(x, y); cout << char(220) << char(219) << char(223);
	}
	else
	{
		gotoXY(x, y - 1); cout << char(220) << "  ";
		gotoXY(x, y); cout << char(223) << char(219) << char(220);
	}
	mu.unlock();
}

void CDINOSAUR::Tell()
{
	srand(time(NULL));
	random = rand() % 3 + 0;

	sound.setVolume(50.f);

	std::string wavPath = path + dinoWav[random];

	if (!buffer.loadFromFile(wavPath))
		return; // error

	sound.setBuffer(buffer);
	sound.setPlayingOffset(sf::seconds(5.f));
	sound.play();
}

//---------------