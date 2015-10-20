//PLAYER CLASS CONTAINS BOOLEANS FOR MOVE, ALIVE, ATTACK, AND HAS GOLD.
//INTEGERS FOR THE STARTING POSITION, A PUBLIC CONSTRUCTOR, SPAWN, CONTROLLER, 
//AND ATTACK FUNCTIONS, AS WELL AS A PRIVATE GOAL FUNCTION.
#pragma once
class Player
{
public:
	bool playerAlive = true;
	bool playerMove;
	bool playerAttack;
	bool playerHasGoal;

	int currentPosY;
	int currentPosX;

	Player();
	void PSpawn();
	void Controller(char);
	void HasGoal();
};

//PLAYER CONSTRUCTOR SETS PLAYER ALIVE TO TRUE, PLAYER ATTACK TO FALSE,
//AND SETS THE PLAYERS COORDINATES TO ZERO.
Player::Player()
{
	playerAlive = true;
	playerAttack = false;
	currentPosX = 0;
	currentPosY = 0;
}

//SPAWN FUNCTION SETS THE STARTING POSITION EQUAL TO ZERO, HasGoal TO FALSE, 
//AND Attack TO FALSE.
void Player::PSpawn()
{
	if (playerAlive)
	{
		playerHasGoal = false;
		playerAttack = false;
	}
}

//MOVES THE PLAYER VIA A SWITCH STATEMENT BETWEEN THE WASD keys.
//CALLS IN THE ATTACK FUNCTION WHEN K key IS PRESSED.
//DEPENDING ON WHICH KEY IS INPUT THE PLAYER IS MOVED 1 SPACE ON THE GRID.
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

//CHECKS IF THE PLAYER'S POSITION IS EQUAL TO 4, 4.
//IF YES THEN THE PLAYER HAS THE GOAL, IF NO THEN THE GAME CONTINUES.
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