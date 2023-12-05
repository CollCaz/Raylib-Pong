#include "paddle.h"
#include <raylib.h>

void DrawPaddle(Paddle *paddle) {
  DrawRectangle(paddle->Position.x, paddle->Position.y, paddle->Size.x,
                paddle->Size.y, paddle->Color);
}

void ControlPaddle(Paddle *paddle, int player, float *delta) {
  int up = (player == 1) ? KEY_W : KEY_UP;
  int down = (player == 1) ? KEY_S : KEY_DOWN;

  if (IsKeyDown(up)) {
    if (paddle->Position.y >= 0) {
      paddle->Position.y -= paddle->speed * *delta;
    }
  }

  if (IsKeyDown(down)) {
    if ((paddle->Position.y + paddle->Size.y) <= GetScreenHeight()) {
      paddle->Position.y += paddle->speed * *delta;
    }
  }
}
