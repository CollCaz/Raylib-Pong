#include "ball.h"
#include "paddle.h"
#include <raylib.h>

int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;
  char *message = "Hello";

  Ball ball = {
      {screenWidth / 2.0, screenHeight / 2.0}, {300, 300}, 15.0, WHITE};

  Paddle player1 = {{10, screenHeight / 2.0 - 50}, {20, 120}, 400, WHITE};
  Paddle player2 = {
      {screenWidth - 35, screenHeight / 2.0 - 50}, {20, 120}, 400, WHITE};

  InitWindow(screenWidth, screenHeight, "Pong");
  // SetTargetFPS(270);

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    BeginDrawing();
    DrawFPS(20, 20);
    ClearBackground(BLACK);
    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
    DrawBall(&ball);
    MoveBall(&ball, &dt);
    // DrawRectangle(10, screenHeight / 2 - 50, 20, 120, WHITE);
    ControlPaddle(&player1, 1, &dt);
    ControlPaddle(&player2, 2, &dt);
    DrawPaddle(&player1);
    DrawPaddle(&player2);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
