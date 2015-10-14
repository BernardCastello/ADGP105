#include <iostream>
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

//PROBLEM: CREATE A 4X4 GRID AND MOVE A PLAYER ON IT WHILE AVOIDING, 
//OR KILLING, THE ENEMY TO REACH THE GOAL.


using namespace std;

int main()
{
	Grid g = Grid(); // CREATES AN INSTANCE OF THE GRID.
	Player p = Player(); // CREATES AN INSTANCE OF THE PLAYER.
	Enemy e = Enemy(); // CREATES AN INSTANCE OF THE ENEMY.


	g.DrawGrid();  // CALLS IN THE DRAW GRID FUNCTION.
	p.PSpawn();	   // CALLS IN THE PLAYER SPAWN FUNCTION.

	cout << "SCANNER IS DAMAGED:" << endl;
	cout << "ENEMY DETECTION: OFFLINE" << endl;
	cout << "GOLD DETECTION: ONLINE" << endl;
	cout << "RESERVE AMMO: FULL" << endl;
	cout << "ENTERING CAVE" << endl;
	cout << "CURRENT POSITION: " << p.currentPosX << ", " << p.currentPosY << endl;

	// CHECKS TO SEE IF PLAYER ALIVE AND IF YES TAKES IN AN INPUT, 
	// AND CALLS THE PLAYER CONTROL AND ATTACK FUNCTIONS,
	// IF THE PLAYER MOVES DISPLAY THE NEW POSITION,
	// IF ATTACK FUNCTION CALLED ASK FOR DIRECTION TO SHOOT.
	// IF THE PLAYER DIES IT DE-ACTIVATES THE CONTROLS AND DISPLAYS GAME OVER MESSAGE.
	while (p.playerAlive)						
	
	{
		char input;
		cin >> input;
		p.Controller(input); 
		p.PAttack();
		e.EnemyAttack(p);

		if (p.playerMove)
		{
			cout<<"CURRENT POSTIION: " << p.currentPosX << ", " << p.currentPosY << endl;
		}

		if (p.playerAttack)
		{
			p.PAttack();
		}

		if (e.enemyAttack)
		{
			p.playerAlive = false;
			cout << "GAME OVER" << endl;
		}
	}

	//CHECKS TO SEE IF THE ENEMY IS ALIVE,
	//IF YES THEN IT CALLS THE ATTACK FUNCTION,
	//IF NO THEN IT KILLS THE ENEMY.
	while (e.enemyAlive)
	{
		e.EnemyAttack(p);
		e.EnemyDead();
	}
}