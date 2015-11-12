#pragma once

struct Pit
{
	int posX;
	int posY;

	void SpawnPit();
};

void Pit::SpawnPit()
{
	posX = 3;
	posY = 2;
}