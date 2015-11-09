#include <iostream>
#include <fstream>
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

using namespace std;

int main()
{
	Player p = Player(); //Creates an instance of the player.
	Grid g = Grid(); //Creates an instance of the grid.
	Bullet b = Bullet(); //Creates an intance of the bullet.
	Enemy e = Enemy(); //Creates an instance of the enemy.
	
	//Reads and displays the GameStart text from OpeningText.txt file.
	ifstream file;
	file.open("OpeningText.txt", ios_base::in);
	char stuff[35];

	if (file.is_open())
	{
		file >> stuff;
	}

	cout << stuff << endl;
	file.close();
	
	cout << "SCANNER IS DAMAGED:" << endl;
	cout << "ENEMY DETECTION: OFFLINE" << endl;
	cout << "ARTIFACT DETECTION: ONLINE" << endl;
	cout << "WARNING: CAVE IS GEOLOGICALLY UNSTABLE" << endl;
	cout << "CAVE SIZE MAPPED TO 5X5 GRID, IMPACTING WALL WILL CAUSE A CAVE IN" << endl;
	cout << "RESERVE AMMO: FULL" << endl;
	cout << "ENTERING CAVE" << endl;
	
	g.DrawGrid();  //Calls in the DrawGrid function.
	p.PSpawn();   //Calls in the player spawn function.
	cout << endl;
	
	cout << "CURRENT POSTIION: " << p.currentPosX << ", " << p.currentPosY << endl;

	//Checks to see if the player is alive and if yes takes in an input, 
	//And calls the Controller function, if the playerMove is true display new position.
	//If playerAttack is true, spawn the bullet, and ask for direction to shoot.
	//Checks to see if bullet hits an enemy or not, and displays appropriate message.
	//If the player dies or reaches the goal diplays a message and deactivates the controls.
	//Writes GameOver text to Pilots.txt file.
	while (p.playerAlive)						
	{
		char input;
		cin >> input;
		p.Controller(input);
		p.HasGoal();
		e.EnemyAttack(p);
		p.Wall();

		if (p.playerMove)
		{
			cout << "CURRENT POSTIION: " << p.currentPosX << ", " << p.currentPosY << endl;
			g.UpdateGrid();
		}

		if (p.playerAttack)
		{
			cout << "SELECT FIRING DIRECTION: " << endl;
			b.SpawnBullet(p);
			cin >> input;
			b.MoveBullet(input);
			b.BulletHit(e);

			if (b.enemyHit == true)
			{
				cout << "ENEMY TERMINATED" << endl;
				e.enemyAlive = false;
				p.playerAttack = false;
			}

			else
			{
				cout << "TARGET MISSED" << endl;
				e.enemyAlive = true;
				p.playerAttack = false;
			}
		}

		if (e.enemyAttack)
		{
			p.playerAlive = false;
			cout << "GAME OVER" << endl;
		}

		if (p.playerWall)
		{
			p.playerAlive = false;
			cout << "YOU HIT A WALL AND CAUSED A CAVE IN, MISSION FAILED" << endl;
		}

		if (p.playerHasGoal)
		{
			p.playerAlive = false;
			cout << "ARTIFACT RECOVERED: MISSION COMPLETE" << endl;
		}

		if (p.playerAlive == false)
		{
			ofstream file;
			file.open("Pilots.txt", ios_base::out);

			if (file.is_open())
			{
				file << "GameOver" << endl;
			}
		}
	}

	//Checks if the enemy is alive, if yes calls EnemyAttack function.
	//If no deletes the enemy.
	while (e.enemyAlive)
	{
		e.EnemyAttack(p);
	}
}