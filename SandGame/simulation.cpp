#include <vector>
#include <utility>
#include "simulation.hpp"
#include <iostream>
#include<raylib.h>
void Simulation::Draw()
{
	grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
	grid.setValue(row, column, value);
}

int Simulation::Sand(int row, int column)
{
	if (grid.GetValue(row + 1, column) == 0 || grid.GetValue(row + 1, column) == 2)
	{
		return 0;
	}
	else if (grid.GetValue(row + 1, column + 1) == 0 || grid.GetValue(row + 1, column + 1) == 2)
	{
		return 1;
	}
	else if ( grid.GetValue(row + 1, column - 1) == 0 || grid.GetValue(row + 1, column - 1) == 2)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

int Simulation::Water(int row, int column)
{
	if (grid.GetValue(row + 1, column) == 0)
	{
		return 0;
	}
	else if (grid.GetValue(row + 1, column + 1) == 0)
	{
		return 1;
	}
	else if (grid.GetValue(row + 1, column - 1) == 0)
	{
		return 2;
	}
	else if(grid.GetValue(row, column - 1) == 0)
	{
		return 3;
	}
	else if (grid.GetValue(row, column + 1) == 0)
	{
		return 4;
	}
	else
	{
		return 5;
	}
}

void Simulation::Update()
{
	if (IsRunning())
	{
		for (int row = 0; row < grid.GetRows(); row++)
		{
			for (int column = 0; column < grid.GetColumns(); column++)
			{
				int cellValue = grid.GetValue(row, column);
				if (cellValue == 1)
				{
					//Sand Behaviour
					int sand = (row < grid.GetRows()-1 && column > 0 && column < grid.GetColumns() - 1) ? Sand(row, column) : 3;
					if (sand == 0)
					{
						tempGrid.setValue(row, column, 0);
						tempGrid.setValue(row + 1, column, 1);
					}
					else if (sand == 1)
					{
						tempGrid.setValue(row, column, 0);
						tempGrid.setValue(row + 1, column + 1, 1);
					}
					else if (sand == 2)
					{
						tempGrid.setValue(row, column, 0);
						tempGrid.setValue(row + 1, column - 1, 1);
					}
				}
				if (cellValue == 2)
				{
					//Water Behaviour
					int water = (row < grid.GetRows() - 1 && column > 0 && column < grid.GetColumns() - 1) ? Water(row, column) : 5;
					if (water == 0)
					{
						tempGrid.setValue(row, column, 0);
						tempGrid.setValue(row + 1, column, 2);
					}
					else if (water == 1)
					{
						tempGrid.setValue(row, column, 0);
						tempGrid.setValue(row + 1, column + 1, 2);
					}
					else if (water == 2)
					{
						tempGrid.setValue(row, column, 0);
						tempGrid.setValue(row + 1, column - 1, 2);
					}
					else if (water == 3)
					{
						tempGrid.setValue(row, column - 1, 2);
					}
					else if (water == 4)
					{
						tempGrid.setValue(row, column + 1, 2);
					}
				}
			}
		}
		grid = tempGrid;
	}
}

void Simulation::ClearGrid()
{
	if (!IsRunning())
	{
		grid.Clear();
		tempGrid.Clear();
	}
}

void Simulation::CreateRandomnState()
{
	if (!IsRunning())
	{
		grid.FillRandom();
	}
}

void Simulation::ToggleCell(int row, int column, int value)
{
	grid.ToggleCell(row, column, value);
}
