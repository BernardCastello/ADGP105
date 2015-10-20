//PLAYER CLASS CONTAINS A BOOLEAN TO CHECK IF THE ENEMY IS HIT,
//THE CONSTRUCTOR, SPAWN, AND HIT FUNCTIONS.
//CONTAINS PRIVATE VARIABLES FOR POSITION.
#pragma once
class Bullet
{
public:
	bool enemyHit = false;
	Bullet();
	void SpawnBullet(Player);
	void MoveBullet(char);
	void BulletHit(Enemy);

private:
	int currentPosX;
	int currentPosY;
};

Bullet::Bullet() {}

//SPAWN BULLET SETS THE BULLETS POSITION EQUAL TO THE PLAYERS CURRENT POSITION.
void Bullet::SpawnBullet(Player p)
{
	currentPosX = p.currentPosX;
	currentPosY = p.currentPosY;
}

//MOVE BULLET USES A SWITCH STATEMENT TO MOVE THE BULLET BASED ON USER INPUT.
void Bullet::MoveBullet(char i)
{
	switch (i)
	{
	case 'j':
		currentPosY = currentPosY + 1;
		break;

	case 'u':
		currentPosX = currentPosX - 1;
		break;

	case 'i':
		currentPosY = currentPosY - 1;
		break;

	case 'o':
		currentPosX = currentPosX + 1;
		break;
	}
}

//CHECKS IF THE BULLET'S POSITION IS EQUAL TO THE ENEMY'S POSITION
//IF YES IT HITS THE ENEMY, IF NO THE BULLET MISSES.
void Bullet::BulletHit(Enemy e)
{
	if (currentPosX == e.enemyPosX && currentPosY == e.enemyPosY)
	{
		enemyHit = true;
	}

	else
	{
		enemyHit = false;
	}
}