#include "openvk.h"

int main(void)
{
    openvk_CreateWindow(800, 600, "OpenVK");
    Texture2D tex = LoadTexture("src/poop.png");
    openvk_SetFPS(60);

    while (!openvk_WindowIsRunning())
    {
        openvk_ShowFPS_In_Console(1);

        openvk_Render();
        
        Transform2D rect = {
            .position = {100.0f, 100.0f},
            .origin = {0.0f, 0.0f},
            .rotation = {0.0f, 0.0f},
            .size = {50.0f, 300.0f}
        };

        openvk_Draw_Rectangle2D(rect, WHITE);
        openvk_Draw_Circle2D(300.0f, 300.0f, 50.0f, RED);
        openvk_Draw_Ellipse2D(500.0f, 500.0f, 40.0f, 70.0f, BLUE);
        openvk_Draw_Texture(rect, &tex, WHITE);

        openvk_EndRender();
    }
    UnloadTexture(tex);
    openvk_CloseWindow();

    return 0;
}