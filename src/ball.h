#include <raylib.h>

typedef struct {
  Vector2 position;
  Vector2 speed;
  float radius;
  Color color;
} Ball;

void DrawBall(Ball *ball);
void MoveBall(Ball *ball, float *delta);
