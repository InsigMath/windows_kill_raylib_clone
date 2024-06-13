/*******************************************************************************************
 *
 *   raylib game template
 *
 *   Windows Kill Clone Raylib Experiment
 *
 *   This game has been created using raylib (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h
 *for details)
 *
 *   Copyright (c) 2021 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "game.h"
#include "globals.h"
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

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    // Initialization
    //---------------------------------------------------------
    InitWindow(1000, 600, "Windows LOVE YOU!!");

    Game game = Game{.gotPierceDamage = false,
                     .gotSplashDamage = false,
                     .gotMultiFire = false,
                     .increaseWinSz = false,
                     .fireRate = 1500.0f,
                     .fireDamage = 1.0f,
                     .splashDamage = 1.0f,
                     .pierceDamage = 1.0f,
                     .screenWidth = GetScreenWidth(),
                     .screenHeight = GetScreenHeight(),
                     .state = STATE::PLAYING};

    Player player = Player(Vector2{400, 300});

#if defined(PLATFORM_WEB)
    // emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    //--------------------------------------------------------------------------------------
    auto mouse = GetMousePosition();
    std::vector<PlayerFire> allFires;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlayerFire fire(mouse, player.m_pos, game.fireRate, game.fireDamage, game.splashDamage,
                            game.gotSplashDamage, game.gotPierceDamage);
            allFires.push_back(fire);
        }

        player.Update();
        for (auto &shot : allFires)
        {
            if (shot.m_active)
            {
                shot.Update();
                shot.CheckCollisions(game);
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);
        player.Draw();
        for (auto &shot : allFires)
        {
            if (shot.m_active)
            {
                shot.Draw();
            }
        }

        if (game.increaseWinSz)
        {
            SetWindowSize(game.screenWidth, game.screenHeight);
            game.increaseWinSz = false;
        }
        EndDrawing();
    }
#endif

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
