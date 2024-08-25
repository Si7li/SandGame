#include "raylib.h"
#include <random>
#include <iostream>
#include "simulation.hpp"

const int screenWidth = 1200;
const int screenHeight = 800;
const int cellSize = 10;
int FPS = 120;

int main()
{
    InitWindow(screenWidth, screenHeight, "Game Of Life");
    SetTargetFPS(FPS);
    Simulation simulation{ screenWidth, screenHeight, cellSize };
    int value = 1;
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ONE))
        {
            std::cout << "Sand" << std::endl;
            value = 1;
        }
        else if (IsKeyPressed(KEY_TWO))
        {
            std::cout << "Water" << std::endl;
            value = 2;
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePos = GetMousePosition();
            int row = mousePos.y / cellSize;
            int column = mousePos.x / cellSize;
            simulation.ToggleCell(row, column, value);
        }
        if (IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Game Of Life is running...");
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Game Of Life stopped...");
        }
        else if (IsKeyDown(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyDown(KEY_S))
        {
            if (FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }
        else if (IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomnState();
        }
        else if (IsKeyPressed(KEY_C))
        {
            simulation.ClearGrid();
        }
        simulation.Update();
        BeginDrawing();
        ClearBackground(BLACK);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}