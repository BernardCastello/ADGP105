//Enemy class contains a constructor and a function for attacking the player,
//the constructor, variables for if the enemy is alive, 
//and attacking as well as the positions, the constructor,
#pragma once
class Enemy
{
public:
	bool enemyAlive;
	bool enemyAttack;

	int enemyPosX;
	int enemyPosY;

	Enemy();
	void EnemyAttack(Player);
};

//Enemy constructor sets the enemy's coordinates,
//and attack to false.
Enemy::Enemy()
{
	enemyPosX = 2;
	enemyPosY = 3;
	enemyAlive = true;
}

//Checks if the player's position is equal to the enemy's position.
//If yes the player dies, and if no the game continues.
void Enemy::EnemyAttack(Player p)
{
	if (p.currentPosX == enemyPosX && p.currentPosY == enemyPosY)
	{
		enemyAttack = true;
	}

	else
	{
		enemyAttack = false;
	}
}