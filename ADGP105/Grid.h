//GRID CLASS CONTAINS THE DRAWGRID, BOUNDARY FUNCTIONS, AND CONSTRUCTOR AS PUBLIC VARIABLES,
//AND THE SIZE ARRAY, ROWS, AND COLUMNS AS PRIVATE VARIABLES

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

Grid::Grid()  //GRID CONSTRUCTOR SETS THE VALUES FOR THE ROWS AND COLUMNS.
{
	cols = 4;
	rows = 4;
}


void Grid::DrawGrid() //DRAW GRID FUNCTION USES A NESTED FOR LOOP TO CREATE THE ROWS AND COLUMNS.
{
	for (int r = 0; r <= rows; r++)
	{
		for (int c = 0; c <= cols; c++)
		{
			
		}
	}
}

void Grid::Boundary()
{

}