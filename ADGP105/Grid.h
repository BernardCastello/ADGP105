//GRID CLASS CONTAINS THE DRAWGRID, BOUNDARY FUNCTIONS, 
//AND CONSTRUCTOR AS PUBLIC VARIABLES,
//AND THE SIZE ARRAY, ROWS, AND COLUMNS AS PRIVATE VARIABLES
#pragma once
class Grid
{	
public:
	void DrawGrid();
	Grid();

private:
	int size[25];
	int rows;
	int cols;
	int boundPosX;
	int boundPosY;
};

//GRID CONSTRUCTOR SETS THE VALUES FOR THE ROWS AND COLUMNS.
Grid::Grid()
{
	cols = 5;
	rows = 5;
}

//DRAW GRID FUNCTION USES A NESTED FOR LOOP TO CREATE THE ROWS AND COLUMNS.
void Grid::DrawGrid()
{
	int* gridSize = &size[25];

	for (int r = 0; r <= rows; r++)
	{
		for (int c = 0; c <= cols; c++)
		{
			break;
		}
	}
}