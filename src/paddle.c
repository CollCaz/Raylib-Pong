#include "paddle.h"
#include <raylib.h>

void DrawPaddle(Paddle *paddle) {
  DrawRectangle(paddle->Position.x, paddle->Position.y, paddle->Size.x,
                paddle->Size.y, paddle->Color);
}
