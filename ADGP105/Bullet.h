//Bullet class contains a boolean for if the enemy is hit,
//The constructor, spawn, move, and hit functions.
//Contains private variables for position.
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

//SpawnBullet sets the bullets position equal to the player's position.
void Bullet::SpawnBullet(Player p)
{
	currentPosX = p.currentPosX;
	currentPosY = p.currentPosY;
}

//MoveBullet uses a swithc statement to move the bullet based on usert input.
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

//BulletHit checks if the bullet's position is 
//If yes it hits the enemy, and if no it misses the enemy.
void Bullet::BulletHit(Enemy e)
{
	if ((currentPosX == e.enemyPosX) && (currentPosY == e.enemyPosY))
	{
		enemyHit = true;
	}

	else
	{
		enemyHit = false;
	}
}