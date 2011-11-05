#ifndef CORDITE_PROCESS
#define CORDITE_PROCESS
#include <vector>

namespace cordite {
  namespace dm {
    class screen;
    class window;
    class factory;
    /*! \brief The logic component which prepares the windows for drawing
     * 
     * Processes can house multiple windows.
     * Each has an ID and a pointer to the screen parent.
     * The process class is meant to be inherited to be the logic component associated with windows.
     * The correct way of thinking is that screen starts processes, process tells screen about its windows.
     * process updates the windows when ever they should be, it is up to the screen to display them.
     * processes do not receive events, the window class does, and its up to the process to process the events. 
     */
    class process {
      friend class screen;
      friend class factory;
    protected:
      std::vector<window*> windows;
      unsigned int id;
      screen* parent;
      //! \brief processes can start other processes, which need to attach to the screen
      void attachToScreen(screen* newParent);
    public:
      process();
      virtual ~process();
      //! \brief gets the numerical id
      const unsigned int getID() const;
      //! \brief returns a pointer to a window that is associated with the id
      window* getWindow(unsigned int id);
      //! \brief returns the window count
      const unsigned int getWindowCount() const;
      /*! \brief execute one run
       * 
       * This is what should be called by the screen after events have been sent.
       * All processes should be thread safe, but that is up to the creator of the process to handle.
       */
      virtual void operator() () = 0;
      
    };
  };
};
#endif