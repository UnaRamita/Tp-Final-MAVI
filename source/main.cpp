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

        if (!TpfinalMavi.Run()) {
            EndDrawing();
            break;
        }

        EndDrawing();
    }

    return 0;
}

