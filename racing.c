#include "stdio.h"
#include "raylib.h"
#include "math.h"
#include "stdlib.h"
#define Background_color (Color){180, 149, 127}
#define car_color BLACK

int main(void)
{
    int width = 1300;
    int height = 900;
    InitWindow(width, height, "Racer");
    SetTargetFPS(60);

    int car_width = 30;
    int car_height = 50;
    float car_x = width / 2 - car_width / 2;
    // float car_y = height / 2 - car_height / 2;
    float car_y = height;
    float car_speed = 0;
    float car_max_speed = 15;
    int car_direction = 0;
    float car_rotation = 0;
    float rotation_speed = 20;
    float car_speedup = 5;
    float car_speeddown = 10;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(Background_color);
        DrawText("Wloiusrhei  jgr xfgnf  he  yhe kb  lr!", 190, 200, 20, LIGHTGRAY);
        if (IsKeyDown(KEY_UP))
        {
            car_direction = 1;
            car_speed += car_speedup * dt;
            if (car_speed > car_max_speed)
            {
                car_speed = car_max_speed;
            }
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            car_direction = -1;
            car_speed -= car_speedup * dt;
            if (car_direction * car_speed > car_max_speed)
            {
                car_speed = car_max_speed;
            }
        }
        else
        {
            car_speed -= car_direction * car_speeddown * dt;
            if (car_direction * car_speed < 0)
            {
                car_speed = 0;
            }
        }
        if (car_speed)
        {
            if (IsKeyDown(KEY_LEFT))
            {
                car_rotation -= rotation_speed * dt * abs(car_speed);
            }
            else if (IsKeyDown(KEY_RIGHT))
            {
                car_rotation += rotation_speed * dt * abs(car_speed);
            }
        }

        // round up circle
        if (car_rotation > 360)
        {
            car_rotation = 0;
        }
        else if (car_rotation < 0)
        {
            car_rotation = 360;
        }

        float rad = PI * car_rotation / 180;
        car_x -= car_speed * cosf(rad);
        car_y -= car_speed * sinf(rad);

        // border
        if (car_y < 0)
        {
            car_y = 0;
            // car_speed = 0;
        }
        else if (car_y > 900)
        {
            // car_speed = 0;
            car_y = 900;
        }
        if (car_x < 0)
        {
            car_x = 0;
            // car_speed = 0;
        }
        else if (car_x > 1300)
        {
            // car_speed = 0;
            car_x = 1300;
        }
        Vector2 car_origin = {car_width / 2, car_height / 2};
        Rectangle car_rec = {car_x, car_y, car_height, car_width};
        DrawRectanglePro(car_rec, car_origin, car_rotation, car_color);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}