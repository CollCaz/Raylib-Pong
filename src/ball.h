#pragma once
#include "paddle.h"
#include <raylib.h>

typedef struct {
  Vector2 position;
  Vector2 speed;
  float radius;
  Color color;
} Ball;

void DrawBall(Ball *ball);
int MoveBall(Ball *ball, float *delta);
void CollideBall(Ball *ball, Paddle *player, Paddle *cpu);
