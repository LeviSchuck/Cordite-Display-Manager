#ifndef WINDOW_H
#define WINDOW_H
#include <queue>
#include <string>
#include "threadedsurface.h"
#include "dim2d.h"
#include "events.h"
namespace cordite {
  namespace dm {
    class process;
    class screen;
    class window{
      friend class process; 
      friend class screen;
    private:
      unsigned int id;
      dim2di dim;
      typedef std::pair<unsigned long int,events::eventList> eventsWithTime;
      std::queue<eventsWithTime> eventQueue;
      dim2di mousePos;
      threaded_surface surfaceA;
      threaded_surface surfaceB;
      SDL_mutex* switchingSurfaces;
      bool useFirstSurface;
      std::string title;
      process* parent;
    public:
	window();
	virtual ~window();
	threaded_surface& getCurrentSurface(); 
	const unsigned int getID();
	const dim2di getDimensions() const;
	const bool isFocused() const;
	const bool isChanged() const;
	virtual const bool isWindowed();
	virtual const std::string getTitle() const;
	virtual void setDimensions(const dim2di& d);
	virtual void setFocus(const bool);
	virtual void mouseHover(dim2di& pos);
	virtual void setEvents(const unsigned long int,const events::eventList&);
	virtual const bool isTask() const;
    };
  };
};
#endif // WINDOW_H
