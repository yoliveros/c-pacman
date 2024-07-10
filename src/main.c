#include "include/raylib.h"

int main() {
  const int screen_width = 1200;
  const int screen_height = 800;

  Rectangle touch_area = {20, 20, screen_width - 40, screen_height - 40};

  InitWindow(screen_width, screen_height, "Pacman");

  Vector2 center = {(GetScreenWidth()) / 2.0, (GetScreenHeight() / 2.0)};

  SetTargetFPS(8);

  float end_angle = 300;

  while (!WindowShouldClose()) {
    BeginDrawing();
    DrawRectangleLinesEx(touch_area, 10, Fade(LIGHTGRAY, 0.6f));
    DrawCircleSector(center, 100, 0, end_angle, 20, RED);
    DrawText("Hola world", 300, 200, 20, WHITE);
    EndDrawing();
  }

  return 0;
}
