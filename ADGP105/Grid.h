//GRID CLASS CONTAINS THE DRAWGRID, BOUNDARY FUNCTIONS, 
//AND CONSTRUCTOR AS PUBLIC VARIABLES,
//AND THE SIZE ARRAY, ROWS, AND COLUMNS AS PRIVATE VARIABLES
#pragma once
class Grid
{	
public:
	void DrawGrid();
	void Boundary();
	Grid();

private:
	int size[16];
	int rows;
	int cols;
};

//GRID CONSTRUCTOR SETS THE VALUES FOR THE ROWS AND COLUMNS.
Grid::Grid()
{
	cols = 4;
	rows = 4;
}

//DRAW GRID FUNCTION USES A NESTED FOR LOOP TO CREATE THE ROWS AND COLUMNS.
void Grid::DrawGrid()
{
	for (int r = 0; r <= rows; r++)
	{
		for (int c = 0; c <= cols; c++)
		{
			
		}
	}
}

//DISPLAYS A MESSAGE AND STOPS THE PLAYER
//WHEN THE PLAYER'S POSITION IS EQUAL TO THE BOUNDARY.
void Grid::Boundary()
{

}