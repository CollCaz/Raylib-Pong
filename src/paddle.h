#pragma once
#include <raylib.h>

typedef struct {
  Vector2 Position;
  Vector2 Size;
  float speed;
  Color Color;
} Paddle;

void DrawPaddle(Paddle *paddle);
void ControlPaddle(Paddle *paddle, int player, float *delta);
