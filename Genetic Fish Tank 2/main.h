#pragma once
#include <time.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "input.h"
#include "fish.h"

static const int SCREENWIDTH = 800, SCREENHEIGHT = 600;
static SDL_Window* displayWindow;

extern bool isRunning;

float ConvertColor(int rgbValue);