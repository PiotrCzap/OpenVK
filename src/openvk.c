#include "stdio.h"
#include "openvk.h"

// ===========================================================================================
// CAMERA
// ===========================================================================================

void openvk_Draw_Camera2D(const float position_x, const float position_y, const float rotation, const float zoom, const Vector2 target)
{
    Camera2D camera;
    Vector2 offset = {position_x, position_y};
    camera.offset = offset;
    camera.rotation = rotation;
    camera.target = target;
    camera.zoom = zoom;
}

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
        printf("FPS: %d\n", GetFPS());
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


