
#ifndef _KEY_PRESSES_H_
#define _KEY_PRESSES_H_

#include <SDL2/SDL.h>
#include <cstdio>
#include <string>

#include "common/surface-loader.h"

const struct scancode_surface_map_t {
  const SDL_Scancode scancode;
  const char *path;
};


// initialize SDL, load surface and audio
bool setup();

// Frees media and shuts down SDL
void teardown();

// The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* gScancodeSurfaces[ SDL_NUM_SCANCODES ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

#endif

