#pragma once
//Struct for the pit contains variables for the pit's position, 
//if the player falls, and funcitons for spawning the pit,
//and checking if the player falls.

struct Pit
{
	int posX;
	int posY;
	bool playerFalls;

	void SpawnPit();
	void PlayerFalls(Player);
};

//Sets the pits coordinates.
void Pit::SpawnPit()
{
	posX = 2;
	posY = 2;
}

//Checks if the player's coordinates are equal to the pit's position
//if yes playerFalls is set to true.
void Pit::PlayerFalls(Player pl)
{
	if (pl.currentPosX && pl.currentPosY == posX && posY)
	{
		playerFalls = true;
	}

	else
	{
		playerFalls = false;
	}
}