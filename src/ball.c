#include "ball.h"
#include "paddle.h"
#include <raylib.h>
#include <raymath.h>

void DrawBall(Ball *ball) {
  DrawCircle(ball->position.x, ball->position.y, ball->radius, WHITE);
}

int MoveBall(Ball *ball, float *delta) {

  if (ball->position.x + ball->radius >= GetScreenWidth() + ball->radius * 2 ||
      ball->position.x <= -ball->radius * 2) {

    ball->position.x = GetScreenWidth() / 2.0;
    ball->position.y = GetScreenHeight() / 2.0;

    ball->speed = Vector2Multiply(ball->speed, Vector2Negate(Vector2One()));
    return 1;
  }

  if (ball->position.y + ball->radius >= GetScreenHeight() ||
      ball->position.y <= ball->radius) {
    ball->speed = Vector2Reflect(ball->speed,
                                 Vector2Normalize((Vector2){0, ball->speed.y}));
  }

  ball->position.x += ball->speed.x * *delta;
  ball->position.y += ball->speed.y * *delta;

  return 0;
}

void CollideBall(Ball *ball, Paddle *player, Paddle *cpu) {
  Rectangle playerRect = {player->Position.x, player->Position.y,
                          player->Size.x, player->Size.y};

  Rectangle cpuRect = {cpu->Position.x, cpu->Position.y, cpu->Size.x,
                       cpu->Size.y};

  if (Vector2Normalize(ball->speed).x < 0) {
    if (CheckCollisionCircleRec(ball->position, ball->radius, playerRect)) {
      ball->speed = Vector2Reflect(
          ball->speed, Vector2Normalize((Vector2){ball->speed.x, 0}));
    }
  }

  if (Vector2Normalize(ball->speed).x > 0) {
    if (CheckCollisionCircleRec(ball->position, ball->radius, cpuRect)) {
      ball->speed = Vector2Reflect(
          ball->speed, Vector2Normalize((Vector2){ball->speed.x, 0}));
    }
  }
}
