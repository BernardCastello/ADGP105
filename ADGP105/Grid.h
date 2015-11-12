//Grid class contains the DrawGrid function, 
//and constructor as public variables,
//and stores the array for size and the number of rows and columns as private variables
#pragma once
#include <iostream>

class Grid
{	
public:
	void DrawGrid();
	Grid();

private:
	int size[25];
	int rows;
	int cols;
};

//Grid constructor sets the number of rows and columns.
Grid::Grid()
{
	cols = 5;
	rows = 5;
}

//DrawGrid function uses a nested for loop to create the rows and columns.
//Uses a pointer to reference the array for the grid size.
void Grid::DrawGrid()
{
	int* gridSize = &size[25];

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			std::cout << "#";
		}
		std::cout << std::endl;
	}
}