#include "ball.h"
#include "paddle.h"
#include <raylib.h>
#include <raymath.h>

void DrawBall(Ball *ball) {
  DrawCircle(ball->position.x, ball->position.y, ball->radius, WHITE);
}

int MoveBall(Ball *ball, float *delta) {

  if (ball->position.x + ball->radius >= GetScreenWidth() ||
      ball->position.x <= 0) {

    ball->position.x = GetScreenWidth() / 2.0;
    ball->position.y = GetScreenHeight() / 2.0;
    return 1;
  }

  if (ball->position.y + ball->radius >= GetScreenHeight() ||
      ball->position.y <= ball->radius) {
    ball->speed.y *= -1;
    // ball->speed = Vector2Reflect(ball->speed, Vector2Normalize(ball->speed));
  }

  ball->position.x += ball->speed.x * *delta;
  ball->position.y += ball->speed.y * *delta;

  return 0;
}

void CollideBall(Ball *ball, Paddle *player, Paddle *cpu) {
  Rectangle playerRect = {player->Position.x - 10, player->Position.y - 10,
                          player->Size.x + 10, player->Size.y + 10};

  Rectangle cpuRect = {cpu->Position.x - 10, cpu->Position.y - 10,
                       cpu->Size.x + 10, cpu->Size.y + 10};
  if (CheckCollisionCircleRec(ball->position, ball->radius, playerRect)) {
    ball->speed = Vector2Rotate(ball->speed, 180.0);
  }

  if (CheckCollisionCircleRec(ball->position, ball->radius, cpuRect)) {
    ball->speed = Vector2Rotate(ball->speed, 180.0);
  }
}
