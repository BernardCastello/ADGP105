//ENEMY CLASS CONTAINS BOOLEANS FOR ALIVE AND ATTACK,
//INTEGERS FOR THE ENEMY'S POSITION, THE CONSTRUCTOR,
//AND THE ATTACK AND DEAD FUNCTIONS.
#pragma once
class Enemy
{
public:
	bool enemyAlive;
	bool enemyAttack;

	int enemyPosX;
	int enemyPosy;

	Enemy();
	void EnemyAttack(Player);
	void EnemyDead();
};

//ENEMY CONSTRUCTOR SETS THE VALUES FOR THE COORDINATES,
//AND SETS ENEMY ALIVE TO TRUE.
Enemy::Enemy()
{
	enemyPosX = 2;
	enemyPosy = 3;
	enemyAlive = true;
}

//CHECKS IF THE PLAYERS POSITION IS EQUAL TO THE ENEMY'S POSITION,
//IF YES IT KILLS THE PLAYER, IF NOT IT CHECKS AGAIN.
void Enemy::EnemyAttack(Player p)
{
	if (p.currentPosX == enemyPosX && p.currentPosY == enemyPosy)
	{
		enemyAttack = true;
	}

	else
	{
		enemyAttack = false;
	}
}

//CHECKS IF THE ENEMY WAS HIT, IF YES IT KILLS THE ENEMY,
//IF NO THE ENEMY IS STILL ALIVE.
void Enemy::EnemyDead()
{
	if (enemyHit)
	{
		cout << "ENEMY TERMINATED" << endl;
		enemyAlive = false;
	}

	else
	{
		cout << "TARGET MISSED" << endl;
		enemyAlive = true;
	}
}