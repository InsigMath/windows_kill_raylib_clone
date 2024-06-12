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
#include "player.h"
#include "player_fire.h"
#include "raylib.h"
#include <iostream>
#include <shared_mutex>
#include <stdio.h>
#include <vector>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
constexpr int screenWidth{1000};
constexpr int screenHeight{600};

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    // Initialization
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Windows LOVE YOU!!");

    STATE state = STATE::PLAYING;
    Game game = Game{.gotPierceDamage = false,
                     .gotSplashDamage = false,
                     .gotMultiFire = false,
                     .fireRate = 1500.0f,
                     .fireDamage = 1.0f,
                     .splashDamage = 1.0f,
                     .pierceDamage = 1.0f};

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
                if (shot.m_pos.x == screenWidth || shot.m_pos.x < 0 || shot.m_pos.y < 0 || shot.m_pos.y == screenHeight)
                {
                    std::cout << "I get here right??" << std::endl;
                    shot.m_active = false;
                }
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
        EndDrawing();
    }
#endif

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
