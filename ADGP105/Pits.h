#pragma once
//Struct for the pit contains variables for the pit's position, 
//if the player falls, and funcitons for spawning the pit, detecting
//and checking if the player falls.

struct Pit
{
	int posX;
	int posY;
	bool playerFalls;

	void SpawnPit();
	void PitDetection(Player);
	void PlayerFalls(Player);
};

//Sets the pits coordinates.
void Pit::SpawnPit()
{
	posX = 2;
	posY = 2;
}

//Displays a message when the player nears the pit.
void Pit::PitDetection(Player pl)
{
	if (pl.currentPosX == posX - 1 || pl.currentPosY == posY - 1 || pl.currentPosX == posX + 1 || pl.currentPosY == posY + 1)
	{
		std::cout << "YOU FEEL A BREEZE" << std::endl;
	}
}

//Checks if the player's coordinates are equal to the pit's position
//if yes playerFalls is set to true.
void Pit::PlayerFalls(Player pl)
{
	if (pl.currentPosX == posX && pl.currentPosY == posY)
	{
		playerFalls = true;
	}

	else
	{
		playerFalls = false;
	}
}