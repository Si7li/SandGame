#include "grid.hpp"
#include <raylib.h>

void Grid::Draw()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			Color color = Color{ 55,55,55,255 };
			if (cells[row][column]) { color = Color{ 203,189,147,255 }; }
			else { Color{ 55,55,55,255 }; }
			if(cells[row][column]==2) { color = Color{ 5,94,156,255 }; }
			else { Color{ 55,55,55,255 }; }
			DrawRectangle(column*cellSize, row * cellSize, cellSize-1, cellSize-1, color);
		}
	}
}

void Grid::setValue(int row, int column, int value)
{
	if (IsWithinBound(row,column))
	{
		cells[row][column] = value;
	}
}

int Grid::GetValue(int row, int column)
{
	if (IsWithinBound(row, column))
	{
		return cells[row][column];
	}
	return 0;
}

bool Grid::IsWithinBound(int row, int column)
{
	if (row >= 0 && row < rows && column >= 0 && column < columns)
	{
		return true;
	}
	return false;
}

void Grid::FillRandom()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			int randomnValue = GetRandomValue(0, 15);
			cells[row][column] = (randomnValue==0)?1:0;
		}
	}
}

void Grid::Clear()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			cells[row][column] = 0;
		}
	}
}

void Grid::ToggleCell(int row, int column, int value)
{
	if (IsWithinBound(row,column))
	{
		cells[row][column] = value;
	}
}
