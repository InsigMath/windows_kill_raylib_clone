/*******************************************************************************************
 *
 *   raylib game template
 *
 *   Windows Kill Clone
 *   Raylib Experiment
 *
 *   This game has been created using raylib (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h
 *for details)
 *
 *   Copyright (c) 2021 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "player.h"
#include "player_fire.h"
#include "raylib.h"
#include <vector>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
constexpr int screenWIDTH{800};
constexpr int screenHeight{600};

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    // Initialization
    //---------------------------------------------------------
    InitWindow(screenWIDTH, screenHeight, "Windows Kill Clone - Experiment");

    Player player = Player(Vector2{400, 300});

#if defined(PLATFORM_WEB)
    // emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT);
    //--------------------------------------------------------------------------------------
    auto mouse = GetMousePosition();
    std::vector<PlayerFire> allFires;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // TODO: This will be in a game struct that will hold all this information
            PlayerFire fire(mouse, player.m_pos, 500, 1, 0, false, false);
            allFires.push_back(fire);
        }

        player.Update();
        for (auto &shot : allFires)
        {
            shot.Update();
        }

        BeginDrawing();
        ClearBackground(BLACK);
        player.Draw();
        for (auto &shot : allFires)
        {
            shot.Draw();
        }
        EndDrawing();
    }
#endif

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
