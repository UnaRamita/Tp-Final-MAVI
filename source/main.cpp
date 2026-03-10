#include "raylib.h"
#include "Game.h"

int main()
{ 
    game TpfinalMavi;

    TpfinalMavi.Inits();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        TpfinalMavi.Run();
        EndDrawing();
    }

    return 0;
}

