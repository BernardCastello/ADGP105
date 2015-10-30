#include <iostream>
#include <fstream>
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

//PROBLEM: CREATE A 4X4 GRID AND MOVE A PLAYER ON IT WHILE AVOIDING, 
//OR KILLING, THE ENEMY TO REACH THE GOAL.

using namespace std;

int main()
{
	Player p = Player(); //CREATES AN INSTANCE OF THE PLAYER.
	Grid g = Grid(); //CREATES AN INSTANCE OF THE GRID.
	Bullet b = Bullet(); //CREATES AN INSTANCE OF THE BULLET.
	Enemy e = Enemy(); //CREATES AN INSTANCE OF THE ENEMY.

	g.DrawGrid();  //CALLS IN THE DRAW GRID FUNCTION.
	p.PSpawn();	   //CALLS IN THE PLAYER SPAWN FUNCTION.
	
	//READS AND DISPLAYS THE GameStart TEXT FROM THE OpeningText.txt FILE
	ifstream file;
	file.open("OpeningText.txt", ios_base::in);
	char stuff[35];

	if (file.is_open())
	{
		file >> stuff;
	}

	cout << stuff << endl;
	file.close();
	cout << endl;

	cout << "SCANNER IS DAMAGED:" << endl;
	cout << "ENEMY DETECTION: OFFLINE" << endl;
	cout << "ARTIFACT DETECTION: ONLINE" << endl;
	cout << "WARNING: CAVE IS GEOLOGICALLY UNSTABLE" << endl;
	cout << "CAVE SIZE MAPPED TO 5X5 GRID, IMPACTING WALL WILL CAUSE A CAVE IN" << endl;
	cout << "RESERVE AMMO: FULL" << endl;
	cout << "ENTERING CAVE" << endl;
	cout << "CURRENT POSTIION: " << p.currentPosX << ", " << p.currentPosY << endl;

	//CHECKS TO SEE IF PLAYER ALIVE AND IF YES TAKES IN AN INPUT, 
	//AND CALLS THE PLAYER CONTROL AND ATTACK FUNCTIONS,
	//IF THE PLAYER MOVES DISPLAY THE NEW POSITION,
	//IF playerAttack IS TRUE,IT SPAWNS THE BULLET, ASKS FOR DIRECTION TO SHOOT,
	//AND CHECKS IF THE BULLET HITS, IF YES IT KILLS THE ENEMY, AND IF NO THE ENEMY IS STILL ALIVE.
	//IF THE PLAYER DIES IT DEACTIVATES THE CONTROLS AND DISPLAYS GAME OVER MESSAGE.
	//IF THE PLAYER REACHES THE GOAL IT DISPLAYS A MESSAGE AND DEACTIVATES THE CONTROLS.
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
		}

		if (p.playerAttack)
		{
			cout << "SELECT FIRING DIRECTION: " << endl;
			b.SpawnBullet(p);
			cin >> input;
			b.MoveBullet(input);
			b.BulletHit(e);

			//CHECKS IF THE ENEMY WAS HIT, IF YES IT KILLS THE ENEMY,
			//IF NO THE ENEMY IS STILL ALIVE.
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

	//CHECKS TO SEE IF THE ENEMY IS ALIVE,
	//IF YES IT CALLS THE EnemyAttack FUNCTION.
	//IF EnemyAttack FUNCTION RETURNS TRUE IT KILLS THE PLAYER.
	while (e.enemyAlive)
	{
		e.EnemyAttack(p);

		if (e.enemyAlive == false)
		{

		}
	}
}