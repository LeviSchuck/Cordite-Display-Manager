#ifndef CORDITE_SCREEN_H
#define CORDITE_SCREEN_H
#include <map>
#include "events.h"
#include "dim2d.h"
struct SDL_Surface;
namespace cordite {
  namespace dm {
    class process;
    class window;
    class screen {
    public:
      virtual SDL_Surface* render() = 0;
      virtual void passEvents(const events::eventList& ev) = 0;
      virtual window* getWindow(const unsigned int id) = 0;
      virtual process* getProcess(const unsigned int id) = 0;
      virtual void addProcess(process* newProcess) = 0;
      virtual const unsigned int getNewWindowID() = 0;
      virtual const dim2di getDimensions() const = 0;
      virtual void setDimensions(const dim2di d) = 0;
    };
  };
}
#endif