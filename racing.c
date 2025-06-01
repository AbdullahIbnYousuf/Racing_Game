#include "stdio.h"
#include "raylib.h"
#define Background_color (Color){180, 149, 127}
#define car_color BLACK

int main(void)
{
    int width = 1300;
    int height = 900;
    InitWindow(width, height, "Racer");
    SetTargetFPS(60);

    int car_width = 60;
    int car_height = 100;
    float car_x = width / 2 - car_width / 2;
    // float car_y = height / 2 - car_height / 2;
    float car_y = height;
    float car_speed = 0;
    float car_max_speed = 1000;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(Background_color);
        DrawText("Wloiusrhei  jgr xfgnf  he  yhe kb  lr!", 190, 200, 20, LIGHTGRAY);
        if (IsKeyDown(KEY_UP))
        {
            car_speed += 100 * dt;
            if (car_speed > car_max_speed)
            {
                car_speed = car_max_speed;
            }
        }
        else
        {
            car_speed -= 30 * dt;
            if (car_speed < 0)
            {
                car_speed = 0;
            }
        }

        car_y -= car_speed;

        DrawRectangle(car_x, car_y, car_width, car_height, car_color);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}