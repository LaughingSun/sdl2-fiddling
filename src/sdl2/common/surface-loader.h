
#ifndef _SURFACE_LOADER_H_
#define _SURFACE_LOADER_H_

#include <cstdlib>
#include <climits>
#include <string>
#include <unordered_map>
#include <SDL2/SDL.h>

class SurfaceLoader {

  SurfaceLoader ( const char *basepath );
  ~SurfaceLoader () {
  
  SDL_Surface* get ( const char *path );
  SDL_Surface* load ( const char *path );
  SDL_Surface* drop ( const char *path );
}

#endif
