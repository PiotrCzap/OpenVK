#include "openvk.h"
#include <stdio.h>

int main(void)
{
    openvk_CreateWindow(800, 600, "OpenVK");
    openvk_SetFPS(60);

    Transform2D rect = {
        .position = {100.0f, 100.0f},
        .origin = {0.0f, 0.0f},
        .rotation = {0.0f, 0.0f},
        .size = {50.0f, 50.0f}
    };

    Camera2D camera;
    camera.target = rect.position; 
    camera.offset = (Vector2){ 400.0f, 300.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    const int speed = 5.0f;

    while (openvk_WindowIsRunning())
    {
        openvk_ShowFPS_In_Console(1);

        if (IsKeyDown(KEY_W))
        {
            rect.position.y -= speed;
        }
        if (IsKeyDown(KEY_S))
        {
            rect.position.y += speed;
        }
        if (IsKeyDown(KEY_A))
        {
            rect.position.x -= speed;
        }
        if (IsKeyDown(KEY_D))
        {
            rect.position.x += speed;
        }

        camera.target.x += (rect.position.x - camera.target.x) * 0.1f;
        camera.target.y += (rect.position.y - camera.target.y) * 0.1f;

        openvk_Draw_Camera2D(&camera, 400.0f, 300.0f, 0.0f, 1.0f, rect.position);

        openvk_Render();

        openvk_Start_Camera2D(camera);
        {
            openvk_Draw_Rectangle2D(rect, WHITE);
            openvk_Draw_Circle2D(300.0f, 300.0f, 50.0f, RED);
            openvk_Draw_Ellipse2D(500.0f, 500.0f, 40.0f, 70.0f, BLUE);
        }
        openvk_End_Camera2D();

        openvk_EndRender();
    }

    openvk_CloseWindow();
    return 0;
}