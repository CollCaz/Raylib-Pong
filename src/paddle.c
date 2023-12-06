#include "paddle.h"
#include <raylib.h>
#include <raymath.h>

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

void AiPaddle(Paddle *paddle, Vector2 *ballPos, float *delta) {
  Vector2 bally = {paddle->Position.x, ballPos->y + GetRandomValue(-20, 20)};
  if (ballPos->x >= (GetScreenWidth() / 2.0)) {
    paddle->Position =
        Vector2MoveTowards(paddle->Position, bally, (paddle->speed * *delta));
  }

  if ((paddle->Position.y + paddle->Size.y) >= GetScreenHeight()) {
    paddle->Position.y = GetScreenHeight() - paddle->Size.y;
  }

  if ((paddle->Position.y + paddle->Size.y) <= 0) {
    paddle->Position.y = 1;
  }
}
