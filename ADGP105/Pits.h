#pragma once

struct Pit
{
	int posX;
	int posY;
	bool playerFalls;

	void SpawnPit();
	void PlayerFalls(Player);
};

void Pit::SpawnPit()
{
	posX = 3;
	posY = 2;
}

void Pit::PlayerFalls(Player pl)
{
	if (pl.currentPosX && pl.currentPosY == posX && posY)
	{
		playerFalls = true;
	}
}