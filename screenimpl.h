#ifndef SCREENIMPL_H
#define SCREENIMPL_H
#include "screen.h"
namespace cordite {
  namespace dm {
    class screenImpl: screen
    {

    public:
	screenImpl();
	virtual ~screenImpl();
	SDL_Surface* render();
	window* getWindow(const unsigned int id);
	process* getProcess(const unsigned int id);
	void addProcess(process* newProcess);
	const unsigned int getNewWindowID();
	const dim2di getDimensions() const;
	void setDimensions(const dim2di d);
	void passMouse(dim2di pos);
    };
  };
};

#endif // SCREENIMPL_H
