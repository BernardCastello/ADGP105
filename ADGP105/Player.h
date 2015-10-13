//PLAYER CLASS CONTAINS BOOLEANS FOR MOVE, ALIVE, ATTACK, AND HAS GOLD.
//INTEGERS FOR THE STARTING POSITION, A PUBLIC CONSTRUCTOR, SPAWN, CONTROLLER, 
//AND ATTACK FUNCTIONS, AS WELL AS A PRIVATE GOAL FUNCTION.

class Player
{
public:
	bool playerAlive = true;
	bool playerMove;
	bool playerAttack;
	bool playerHasGold;

	int currentPosY;
	int currentPosX;

	Player();
	void PSpawn();
	void Controller(char);
	void PAttack(char);

private:		
	
	void Goal();
};

//CONSTRUCTOR SET THE STARTING POSITION EQUAL TO ZERO, HASGOLD TO FALSE, 
//AND ATTACK TO FALSE.
void Player::PSpawn()
{
	if (playerAlive)
	{
		currentPosX = 0;
		currentPosY = 0;
		playerHasGold = false;
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
		currentPosX = currentPosX- 1;
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
		PAttack(i);
		break;

	default:
		playerMove = false;
		playerAttack = false;
		break;
	}
}

void Player::PAttack(char i)
{
	/*switch (i)
	{
	case 'w':
		playerAttack = true;
		break;

	case 'a':
		playerAttack = true;
		break;

	case 's':
		playerAttack = true;
		break;

	case 'd':
		playerAttack = true;
		break;

	default:
		playerAttack = false;
		break;
	}*/
}

void Player::Goal()
{

}


//PLAYER CONSTRUCTOR SETS PLAYER ALIVE TO TRUE, PLAYER ATTACK TO FALSE,
//AND SETS THE PLAYERS COORDINATES TO ZERO.

Player::Player()
{
	playerAlive = true;
	playerAttack = false;
	currentPosX = 0;
	currentPosY = 0;
}