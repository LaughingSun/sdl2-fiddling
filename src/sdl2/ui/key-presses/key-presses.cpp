
/* This source code was inspired by Lazy Foo' Productions */

#include "key-presses.h"

#define RESOURCES_PATH "resources"
#define SURFACES_PATH (RESOURCES_PATH ## "png")

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const struct scancode_surface_map_t
    gScancodeSurfaceMap[KEY_PRESS_SURFACE_TOTAL] = {
  {   SDL_SCANCODE_UNKNOWN, "press.bmp" }
  , { SDL_SCANCODE_UP,      "up.bmp" }
  , { SDL_SCANCODE_DOWN,    "down.bmp" }
  , { SDL_SCANCODE_LEFT,    "left.bmp" }
  , { SDL_SCANCODE_RIGHT,   "right.bmp" }
};

SurfaceLoader surface_cache;

bool setup()
{
	SDL_Surface *surface;
	const struct scancode_surface_map_t *item;
	int i;
	
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
	
	if( (gWindow = SDL_CreateWindow( "SDL Tutorial"
	    , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
	    , SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN )) == NULL )
	{
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
	
	gScreenSurface = SDL_GetWindowSurface( gWindow );
	memset( gScancodeSurfaces, 0, sizeof(gScancodeSurfaces) );
	surface_cache = new SurfaceLoader( SURFACES_PATH );
	
  // Load things, or specifically load "surfaces" that corrospond to key presses
  i = -1;
	while (++i < KEY_PRESS_SURFACE_TOTAL) {
	  if ( item = &gScancodeSurfaceMap[i] ) {
	    if ( surface = surface_cache.load( item->path ) ) {
	      gScancodeSurfaces[item->scancode] = surface;
	      continue;
	    }
	  }
	  
		return false;
		
	}

	return true;
}

void teardown()
{
  
	surface_cache = NULL;

	// teardown SDL
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	SDL_Quit();
	
}

SDL_Surface* loadSurface( std::string path )
{
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}

	return loadedSurface;
}


int main( int argc, char* args[] )
{
	SDL_Surface *surface;
	
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Set default current surface
			gCurrentSurface = gScancodeSurfaces[ SDL_SCANCODE_UNKNOWN ];

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					//User presses a key
					else if( e.type == SDL_KEYDOWN )
					{
						//Select surfaces based on key press
						gCurrentSurface = (surface = gScancodeSurfaces[ e.key.keysym.scancode ])
						    ? surface : gScancodeSurfaces[ SDL_SCANCODE_UNKNOWN ];
					}
				}

				//Apply the current image
				SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );
			
				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
