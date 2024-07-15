#include "include/raylib.h"

const int screen_width = 1200;
const int screen_height = 800;

void movement(Vector2 *center) {
  if (IsKeyDown(KEY_RIGHT) && center->x < (screen_width - 45)) {
    center->x += 4.0f;
  }
  if (IsKeyDown(KEY_LEFT) && center->x > 45) {
    center->x -= 4.0f;
  }
  if (IsKeyDown(KEY_UP) && center->y > 45) {
    center->y -= 4.0f;
  }
  if (IsKeyDown(KEY_DOWN) && center->y < (screen_height - 45)) {
    center->y += 4.0f;
  }
}

int main() {

  Rectangle touch_area = {20, 20, screen_width - 40, screen_height - 40};

  InitWindow(screen_width, screen_height, "Pacman");

  Vector2 center = {(GetScreenWidth()) / 2.0, (GetScreenHeight() / 2.0)};

  SetTargetFPS(60);

  float end_angle = 300;

  while (!WindowShouldClose()) {
    movement(&center);

    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangleLinesEx(touch_area, 10, Fade(BLUE, 0.6f));

    Rectangle rec = {200, 590, 100, 100};

    DrawRectangleRoundedLines(rec, .25, 5, 5, BLUE);

    DrawCircleSector(center, 10, 0, end_angle, 20, YELLOW);
    EndDrawing();
  }

  return 0;
}
