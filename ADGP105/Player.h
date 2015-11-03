//Player class contains booleans for Move, Attack, Hits a wall, and has Goal.
//Integers for the starting position, a public constructor, Spawn, Controller, 
//Attack, Wall, and HasGoal functions.
#pragma once
class Player
{
public:
	bool playerAlive = true;
	bool playerMove;
	bool playerAttack;
	bool playerHasGoal;
	bool playerWall;

	int currentPosY;
	int currentPosX;

	Player();
	void PSpawn();
	void Controller(char);
	void HasGoal();
	void Wall();
};

//Default Player Constructor
Player::Player() {}

//PSpawn function sets the current position to 0, 
//Alive to true, Attack to false, Wall to false, HasGoal to false. 
void Player::PSpawn()
{
	currentPosX = 0;
	currentPosY = 0;
	playerAlive = true;
	playerAttack = false;
	playerHasGoal = false;
	playerWall = false;
}

//Controller moves the player 1 space on the grid, depending on the user input.
//Movement is handled via a switch statement between the WASD keys.
//Pressing the K key sets playerAttack to true.
void Player::Controller(char i)
{
	switch (i)
	{
	case 'w':
		playerMove = true;
		currentPosY = currentPosY + 1;
		break;

	case 'a':
		playerMove = true;
		currentPosX = currentPosX - 1;
		break;

	case 's':
		playerMove = true;
		currentPosY = currentPosY - 1;
		break;

	case 'd':
		playerMove = true;
		currentPosX = currentPosX + 1;
		break;

	case 'k':
		playerAttack = true;
		break;

	default:
		playerMove = false;
		playerAttack = false;
		break;
	}
}

//HasGoal funciton checks if the player's position is equal to 4, 4.
//If yes then the player has the goal and the game ends, if no then the game continues.
void Player::HasGoal()
{
	if (currentPosX == 4 && currentPosY == 4)
	{
		playerHasGoal = true;
	}

	else
	{
		playerHasGoal = false;
	}
}

//Wall checks if the player's position is equal to 5,
//or less than 0. If either condition is true playerWall is set to true.
//If the conditions are false then the game continues.
void Player::Wall()
{
	if (currentPosX == 5 || currentPosY == 5)
	{
		playerWall = true;
	}

	else if (currentPosX < 0 || currentPosY < 0)
	{
		playerWall = true;
	}

	else
	{
		playerWall = false;
	}
}