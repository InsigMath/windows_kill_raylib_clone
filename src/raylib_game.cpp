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
#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
constexpr int screenWidth{800};
constexpr int screenHeight{600};

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(int argc, char **argv) {
  // Initialization
  //---------------------------------------------------------
  InitWindow(screenWidth, screenHeight, "Windows Kill Clone - Experiment");

  Player player = Player(Vector2{400, 300});

#if defined(PLATFORM_WEB)
  // emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT);
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {

    player.Update();

    BeginDrawing();
    ClearBackground(BLACK);
    player.Draw();
    EndDrawing();
  }
#endif

  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
