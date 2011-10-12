#ifndef THREADED_SURFACE_H
#define THREADED_SURFACE_H
#include <SDL/SDL.h>
#include <SDL/SDL_mutex.h>
struct threaded_surface {
 SDL_Surface* surf;
 SDL_mutex* mutex;
 bool changed;
};
#endif