#include "stdio.h"
#include "openvk.h"

// ===========================================================================================
// DRAWING
// ===========================================================================================

void openvk_Draw_Rectangle2D(const Transform2D transform, const Color color)
{
    Rectangle rec = { transform.position.x, transform.position.y, transform.size.x, transform.size.y };
    Vector2 origin = { transform.origin.x, transform.origin.y };
    DrawRectanglePro(rec, origin, transform.rotation, color);;
}

void openvk_Draw_Circle2D(const float position_x, const float position_y, const float radius, const Color color)
{
    DrawCircle(position_x, position_y, radius, color);
}

void openvk_Draw_Ellipse2D(const float position_x, const float position_y, const float radius_x, const float radius_y, const Color color)
{
    DrawEllipse(position_x, position_y, radius_x, radius_y, color);
}

void openvk_Draw_Texture(const Transform2D transform, const Texture2D *texture, const Color color)
{
    Rectangle source = { 0.0f, 0.0f, (float)texture->width, (float)texture->height };
    Rectangle dest = { transform.position.x, transform.position.y, transform.size.x, transform.size.y };
    Vector2 origin = { transform.origin.x, transform.origin.y };
    DrawTexturePro(*texture, source, dest, origin, transform.rotation, color);
    
    
}

// ===========================================================================================
// CONSOLE & DEBUG
// ===========================================================================================

void openvk_ShowFPS_In_Console(const int show)
{
    if (show)
    {
        printf("FPS: \n", GetFPS());
    }
    
}

void openvk_SetFPS(int FPS)
{
    SetTargetFPS(FPS);
}

// ===========================================================================================
// RENDER
// ===========================================================================================

void openvk_Render(void)
{
    BeginDrawing();
    ClearBackground(BLACK);
}

void openvk_EndRender(void)
{
    EndDrawing();
}

// ===========================================================================================
// WINDOW
// ===========================================================================================

void openvk_CreateWindow(const int WINDOW_SIZE_X, const int WINDOW_SIZE_Y, const char WINDOW_TITLE[])
{
    InitWindow(WINDOW_SIZE_X, WINDOW_SIZE_Y, WINDOW_TITLE);
    SetTargetFPS(60);
}

int openvk_WindowIsRunning(void)
{
    return WindowShouldClose();
}

void openvk_CloseWindow(void)
{
    return CloseWindow();
}

int main(void)
{
    openvk_CreateWindow(800, 600, "OpenVK");
    Texture2D tex = LoadTexture("src/poop.png");
    openvk_SetFPS(120);

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
