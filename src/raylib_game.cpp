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

#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
constexpr int screenWidth{800};
constexpr int screenHeight{450};

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(int argc, char **argv) {
  // Initialization
  //---------------------------------------------------------
  InitWindow(screenWidth, screenHeight, "Windows Kill Clone - Experiment");

#if defined(PLATFORM_WEB)
  // emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // UpdateDrawFrame();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Testing Drawing", 100, 100, 50, BLACK);
    EndDrawing();
  }
#endif

  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
