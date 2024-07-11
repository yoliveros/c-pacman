#include "include/raylib.h"

int main() {
  const int screen_width = 1200;
  const int screen_height = 800;

  Rectangle touch_area = {20, 20, screen_width - 40, screen_height - 40};

  InitWindow(screen_width, screen_height, "Pacman");

  Vector2 center = {(GetScreenWidth()) / 2.0, (GetScreenHeight() / 2.0)};

  SetTargetFPS(60);

  float end_angle = 300;

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_RIGHT))
      center.x += 2.0f;
    if (IsKeyDown(KEY_LEFT))
      center.x -= 2.0f;
    if (IsKeyDown(KEY_UP))
      center.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN))
      center.y += 2.0f;

    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangleLinesEx(touch_area, 10, Fade(LIGHTGRAY, 0.6f));
    DrawCircleSector(center, 10, 0, end_angle, 20, YELLOW);
    EndDrawing();
  }

  return 0;
}
