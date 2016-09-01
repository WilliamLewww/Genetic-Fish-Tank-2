#pragma once
#include <SDL_opengl.h>
#include "vector2.h"
#include "global.h"

void DrawLine(Vector2 a, Vector2 b);
void DrawCircle(Vector2 position, float radius);
void DrawTriangle(Vector2 position, int width, int height);
void DrawTriangle(Vector2 position, int width, int height, double angle);