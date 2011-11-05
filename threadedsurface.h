#ifndef THREADED_SURFACE_H
#define THREADED_SURFACE_H
#include <SDL/SDL.h>
#include <SDL/SDL_mutex.h>
//! Has a surface and a mutex for whether its being drawn on or not
struct threaded_surface {
  //! \brief the surface which holds the color array
  SDL_Surface* surf;
  //! \brief mutex for the surface. it should be locked on read and writing
  SDL_mutex* mutex;
  //! \brief If the surface has changed or not. it should be set to false on read and true on write
  bool changed;
};
#endif