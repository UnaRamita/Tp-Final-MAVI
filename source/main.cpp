#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"

int main(void)
{ 
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREEN);


    
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

