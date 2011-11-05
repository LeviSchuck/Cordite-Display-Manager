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
    /*! \brief an individual window which receives events and has a surface
     * \note many parts require implementation.
     *
     * A window is a child of a process, in that the process determines what happens to the window.
     * The window is only a channel for dumping events to for a process to pick up later and update.
     * 
     */
    class window{
      friend class process; 
      friend class screen;
    protected:
      //! \brief id of the window given by the screen
      unsigned int id;
      //! \brief dimensions of the window
      dim2di dim;
      //! \brief a pair where events are logged by time so that a process does not drop events
      typedef std::pair<unsigned long int,events::eventList> eventsWithTime;
      //! \brief a queue where the events are processed in order of receiving
      std::queue<eventsWithTime> eventQueue;
      //! \brief the last known relative mouse position that concerns this window
      dim2di mousePos;
      //! \brief surfaceA will be used while surfaceB is being rendered
      threaded_surface surfaceA;
      //! \brief surfaceB will be used while surfaceA is being rendered
      threaded_surface surfaceB;
      //! \brief So that when surfaceA is being read, surfaceB is not marked as the active buffer
      SDL_mutex* switchingSurfaces;
      //! \brief determines which buffer to use. True: A, False: B
      bool useFirstSurface;
      //! \brief the title of the window for the screen to grab
      std::string title;
      //! \brief a pointer to the parent process
      process* parent;
    public:
	window();
	virtual ~window();
	/*! \brief gets a reference to the current surface.
	 * \note do not free the pointer to the SDL_Surface here. Let it happen on deconstruction.
	 * \returns a threaded_surface which has a mutex. Make sure to use the mutex
	 */
	threaded_surface& getCurrentSurface();
	/*! \brief gets the id which the screen provided on construction
	 * \return the id
	 */
	const unsigned int getID();
	/*! \brief gets the dimensions pair(integers) for the window
	 * \return the dimensions for the window to display with
	 */
	const dim2di getDimensions() const;
	/*! \brief is this window focused?
	 * \return true for if focused
	 */
	const bool isFocused() const;
	/*! \brief have the contents of this window changed?
	 * \return true for if changes have occurred 
	 */
	const bool isChanged() const;
	/*! \brief Does this surface require decoration?
	 * \return true if it needs decoration.
	 * false for when it does not need decoration and it should not be moved around.
	 * Think a task bar
	 */
	virtual const bool isWindowed();
	/*! \brief gets the title for the screen to display
	 * \return a string for the title
	 */
	virtual const std::string getTitle() const;
	/*! \brief attempts to set the dimensions
	 * \note the process can ignore this or say that the dimensions
	 * are something else(think minimum window size or max window size)
	 * This is an attempt, not a force
	 */
	virtual void setDimensions(const dim2di& d);
	/*! \brief sets if focused
	 * \param focus is focused
	 */
	virtual void setFocus(const bool focus);
	/*! \brief sets the known mouse position.
	 * \note This is relative, as in from the top left of the application
	 * \param pos the mouse coordinates relative to the window
	 */
	virtual void mouseHover(dim2di& pos);
	/*! \brief passes the events to the queue
	 * \param time time in miliseconds
	 * \param events a list of events to process
	 */
	virtual void setEvents(const unsigned long int time,const events::eventList& events);
	/*! \brief is this an active process that takes events?
	 * \note this is generally overridden by the children of window
	 * \return can take events
	 */
	virtual const bool isTask() const;
	/*! \brief can take focus
	 * \note generally true, but for things like a background,
	 * it may not be true. You don't want to put the background
	 * on top of everything else.
	 * \return can take focus
	 */
	virtual const bool allowsFocus() const;
    };
  };
};
#endif // WINDOW_H
