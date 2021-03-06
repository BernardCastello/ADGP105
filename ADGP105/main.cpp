#include <iostream>
#include <fstream>
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Pits.h"

using namespace std;

int main()
{
	Grid g = Grid(); //Creates an instance of the grid.
	Player pl = Player(); //Creates an instance of the player.
	Bullet b = Bullet(); //Creates an instance of the bullet.
	Enemy e = Enemy(); //Creates an instance of the enemy.
	Pit p = Pit(); //Creates an instance of the pit.

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
	p.SpawnPit();  //Calls in the SpawnPit function.
	pl.PSpawn();   //Calls in the PlayerSpawn function.
	
	cout << endl;
	cout << "CURRENT POSTIION: " << pl.currentPosX << ", " << pl.currentPosY << endl;

	//Checks to see if the player is alive and if yes takes in an input, 
	//And calls the Controller function, if the playerMove is true display new position.
	//If playerAttack is true, spawn the bullet, and ask for direction to shoot.
	//Checks to see if bullet hits an enemy or not, and displays appropriate message.
	//If the player dies or reaches the goal diplays a message and deactivates the controls.
	//Writes GameOver text to Pilots.txt file.
	while (pl.playerAlive)						
	{
		char input;
		cin >> input;
		pl.Controller(input);
		pl.HasGoal();
		e.EnemyAttack(pl);
		pl.Wall();
		p.PlayerFalls(pl);
		p.PitDetection(pl);

		if (pl.playerMove)
		{
			p.PitDetection(pl);
			//pl.UpdateGrid(g);
			cout << "CURRENT POSTIION: " << pl.currentPosX << ", " << pl.currentPosY << endl;
		}

		if (pl.playerAttack)
		{
			cout << "SELECT FIRING DIRECTION: " << endl;
			b.SpawnBullet(pl);
			cin >> input;
			b.MoveBullet(input);
			b.BulletHit(e);

			if (b.enemyHit == true)
			{
				cout << "ENEMY TERMINATED" << endl;
				e.enemyAlive = false;
				pl.playerAttack = false;
			}

			else
			{
				cout << "TARGET MISSED" << endl;
				e.enemyAlive = true;
				pl.playerAttack = false;
			}
		}

		if (e.enemyAttack)
		{
			pl.playerAlive = false;
			//pl.UpdateGrid(g);
			cout << "YOU WERE EATEN BY THE WUMPUS: MISSION FAILED" << endl;
		}

		if (pl.playerWall)
		{
			pl.playerAlive = false;
			//pl.UpdateGrid(g);
			cout << "YOU HIT A WALL AND CAUSED A CAVE IN: MISSION FAILED" << endl;
		}

		if (p.playerFalls)
		{
			pl.playerAlive = false;
			//pl.UpdateGrid(g);
			cout << "YOU HAVE FALLEN INTO A PIT: MISSION FAILED" << endl;
		}
		
		if (pl.playerHasGoal)
		{
			pl.playerAlive = false;
			//pl.UpdateGrid(g);
			cout << "ARTIFACT RECOVERED: MISSION COMPLETE" << endl;
		}
	
		//Checks if the enemy is alive, and if yes moves the enemy of the grid.
		if (e.enemyAlive == false)
		{
			e.enemyPosX = 6;
			e.enemyPosY = 6;
		}

		if (pl.playerAlive == false)
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
	//If no moves the enemy off the grid.
	while (e.enemyAlive)
	{
		e.EnemyAttack(pl);
	}
}