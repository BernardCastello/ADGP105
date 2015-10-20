#include <iostream>
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
//#include "Goal.h"

//PROBLEM: CREATE A 4X4 GRID AND MOVE A PLAYER ON IT WHILE AVOIDING, 
//OR KILLING, THE ENEMY TO REACH THE GOAL.

using namespace std;

int main()
{
	Player p = Player(); //CREATES AN INSTANCE OF THE PLAYER.
	Grid g = Grid(); //CREATES AN INSTANCE OF THE GRID.
	Bullet b = Bullet(); //CREATES AN INSTANCE OF THE BULLET.
	Enemy e = Enemy(); //CREATES AN INSTANCE OF THE ENEMY.
	//Goal gl = Goal(); //CREATES AN INSTANCE OF THE GOAL.

	g.DrawGrid();  //CALLS IN THE DRAW GRID FUNCTION.
	p.PSpawn();	   //CALLS IN THE PLAYER SPAWN FUNCTION.
	
	cout << "SCANNER IS DAMAGED:" << endl;
	cout << "ENEMY DETECTION: OFFLINE" << endl;
	cout << "ARTIFACT DETECTION: ONLINE" << endl;
	cout << "RESERVE AMMO: FULL" << endl;
	cout << "ENTERING CAVE" << endl;
	cout << "CURRENT POSITION: " << p.currentPosX << ", " << p.currentPosY << endl;

	//CHECKS TO SEE IF PLAYER ALIVE AND IF YES TAKES IN AN INPUT, 
	//AND CALLS THE PLAYER CONTROL AND ATTACK FUNCTIONS,
	//IF THE PLAYER MOVES DISPLAY THE NEW POSITION,
	//IF ATTACK FUNCTION CALLED ASK FOR DIRECTION TO SHOOT.
	//IF THE PLAYER DIES IT DE-ACTIVATES THE CONTROLS AND DISPLAYS GAME OVER MESSAGE.
	//IF THE PLAYER REACHES THE GOAL IT DISPLAYS A MESSAGE AND DEACTIVATES THE CONTROLS.
	while (p.playerAlive)						
	
	{
		char input;
		cin >> input;
		p.Controller(input);
		p.HasGoal();
		e.EnemyAttack(p);
		b.SpawnBullet(p);
		b.MoveBullet(input);

		if (p.playerMove)
		{
			cout<<"CURRENT POSTIION: " << p.currentPosX << ", " << p.currentPosY << endl;
		}

		if (p.playerAttack)
		{
			cout << "SELECT FIRING DIRECTION: " << endl;
			b.SpawnBullet(p);
			b.MoveBullet(input);
		}

		if (e.enemyAttack)
		{
			p.playerAlive = false;
			cout << "GAME OVER" << endl;
		}

		if (p.playerHasGoal)
		{
			p.playerAlive = false;
			cout << "ARTIFACT RECOVERED: MISSION COMPLETE" << endl;
		}
	}

	//CHECKS TO SEE IF THE ENEMY IS ALIVE,
	//IF YES IT CALLS THE EnemyAttack, AND BulletHit FUNCTIONS.
	//IF BulletHit RETURNS TRUE THE ENEMY DIES.

	while (e.enemyAlive)
	{
		e.EnemyAttack(p);
		b.BulletHit(e);
	}

	//CHECKS IF THE ENEMY WAS HIT, IF YES IT KILLS THE ENEMY,
	//IF NO THE ENEMY IS STILL ALIVE.
	if (b.enemyHit == true)
	{
		cout << "ENEMY TERMINATED" << endl;
		e.enemyAlive = false;
	}

	else
	{
		cout << "TARGET MISSED" << endl;
		e.enemyAlive = true;
	}
}