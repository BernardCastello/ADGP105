
class Enemy
{
public:
	bool enemyAlive;
	bool enemyAttack;

	int enemyPosX;
	int enemyPosy;

	Enemy();
	void EnemyAttack(Player p);
	void EnemyDead();
};

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

void Enemy::EnemyDead()
{

}