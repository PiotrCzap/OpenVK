#ifndef OPENVK_H
#define OPENVK_H

#include "raylib.h"

typedef struct 
{
  Vector2 position;
  Vector2 size;
  Vector2 origin;
  float rotation;
} Transform2D;


// ===========================================================================================
// CAMERA
// ===========================================================================================

void openvk_Draw_Camera2D(Camera2D *camera, const float position_x, const float position_y, const float rotation, const float zoom, const Vector2 target);
void openvk_Start_Camera2D(const Camera2D camera);
void openvk_End_Camera2D(void);


// ===========================================================================================
// DRAWING
// ===========================================================================================

void openvk_Draw_Rectangle2D(const Transform2D transform, const Color color);
void openvk_Draw_Circle2D(const float position_x, const float position_y, const float radius, const Color color);
void openvk_Draw_Ellipse2D(const float position_x, const float position_y, const float radius_x, const float radius_y, const Color color);
void openvk_Draw_Texture(const Transform2D transform, const Texture2D *texture, const Color color);


// ===========================================================================================
// CONSOLE & DEBUG
// ===========================================================================================

void openvk_ShowFPS_In_Console(const int show);
void openvk_SetFPS(int FPS);

// ===========================================================================================
// RENDER
// ===========================================================================================

void openvk_Render(void);
void openvk_EndRender(void);

// ===========================================================================================
// WINDOW
// ===========================================================================================

void openvk_CreateWindow(const int WINDOW_SIZE_X, const int WINDOW_SIZE_Y, const char WINDOW_TITLE[]);
int openvk_WindowIsRunning(void);
void openvk_CloseWindow(void);

#endif