
class Bullet
{
public:
	bool enemyHit = false;
	Bullet(Player);
	void SpawnBullet(char);
	void BulletHit(Enemy);

private:
	int currentPosX;
	int currentPosY;
};

Bullet::Bullet(Player p)
{
	currentPosX = p.currentPosX;
	currentPosY = p.currentPosY;
}

void Bullet::SpawnBullet(char i)
{
	switch (i)
	{
	case 'w':
		currentPosY = currentPosY + 1;
		break;

	case 'a':
		currentPosX = currentPosX - 1;
		break;

	case 's':
		currentPosY = currentPosY - 1;
		break;

	case 'd':
		currentPosX = currentPosX + 1;
		break;
	}
}

void Bullet::BulletHit(Enemy e)
{
	if (currentPosX == e.enemyPosX && currentPosY == e.enemyPosy)
	{
		enemyHit = true;
	}

	else
	{
		enemyHit = false;
	}
}