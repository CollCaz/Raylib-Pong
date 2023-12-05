#include "ball.h"
#include <raylib.h>

void DrawBall(Ball *ball) {
  DrawCircle(ball->position.x, ball->position.y, ball->radius, WHITE);
}

void MoveBall(Ball *ball, float *delta) {

  if (ball->position.x + ball->radius >= GetScreenWidth() ||
      ball->position.x <= 0) {
    ball->speed.x *= -1;
  }

  if (ball->position.y + ball->radius >= GetScreenHeight() ||
      ball->position.y <= ball->radius) {
    ball->speed.y *= -1;
  }

  ball->position.x += ball->speed.x * *delta;
  ball->position.y += ball->speed.y * *delta;
}
