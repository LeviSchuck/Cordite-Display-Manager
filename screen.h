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
    /*! \brief Receives events, tells its clients and presents a surface to use on render
     *
     * The screen class is the main manager, it presents a
     * surface on render after receiving events.
     * It handles window decoration, window placement,
     * resize, and potentially other events.
     * When events like clicking and moving are not captured
     * by the manager for purposes like moving a window, it
     * should send the events to the client which has focus.
     */
    class screen {
    public:
      /*! \brief renders an SDL_Surface which the user must use and free
       * \note Requires Implementation!
       *
       * Renders an SDL_Surface which holds the RGB(A) values to use
       * \return SDL_Surface pointer to use
       */
      virtual SDL_Surface* render() = 0;
      /*! \brief Gives an event list to the screen to process
       * \note Requires Implementation!
       * \param ev An eventList which holds the button/key events
       * 
       * It is up to the screen implementation to send the events
       * to the windows which should get it.
       */
      virtual void passEvents(const events::eventList& ev) = 0;
      /*! \brief gets the window associated to the id
       * \note Requires Implementation!
       * \param id the window id which is unique to the screen
       * \return a window pointer
       */
      virtual window* getWindow(const unsigned int id) = 0;
      /*! \brief gets the process associated to the id
       * \note Requires Implementation!
       * \param id the process id which is unique to the screen
       * \return a process pointer
       */
      virtual process* getProcess(const unsigned int id) = 0;
      /*! \brief adds an instantiated process to the screen
       * \note Requires implementation!
       * \param newProcess pointer to a process to add
       * 
       */
      virtual void addProcess(process* newProcess) = 0;
      /*! \brief gets a new ID for a window to be added
       * \note Requires Implementation!
       * Also, Don't make this static! Make it per-screen instance
       * \return new id to use
       */
      virtual const unsigned int getNewWindowID() = 0;
      /*! \brief gets what the SDL_Surface should render
       * \note Requires Implementation!
       * \return a pair of integers
       */
      virtual const dim2di getDimensions() const = 0;
      /*! \brief sets the dimensions that the user wishes to render with
       * \note Requires Implementation"
       * Also, this isn't just a think that happens at startup.
       * It would be nice if it could resize live too.
       * \param d the dimensions as a dim2di, which is a pair of integers
       */
      virtual void setDimensions(const dim2di d) = 0;
      /*! \brief passes the mouse position event
       * \note Requires Implementation!
       * \param pos The mouse position to register 
       */
      virtual void passMouse(dim2di pos)=0;
    };
  };
}
#endif