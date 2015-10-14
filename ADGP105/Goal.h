//GOAL CLASS CONTAINS VARIABLES FOR THE GOAL'S POSITION,
//AND THE CONSTRUCTOR WHICH SETS THE GOAL'S POSITION AT THE TOP RIGHT OF THE GRID.


class Goal
{
public:
	int goalPosX;
	int goalPosY;

	Goal();
};

Goal::Goal()
{
	goalPosX = 4;
	goalPosY = 4;
}