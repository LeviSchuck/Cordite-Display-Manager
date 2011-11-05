#ifndef CORDITE_PROCESS
#define CORDITE_PROCESS
#include <vector>

namespace cordite {
  namespace dm {
    class screen;
    class window;
    class factory;
    class process {
      friend class screen;
      friend class factory;
    protected:
      std::vector<window*> windows;
      unsigned int id;
      screen* parent;
      void attachToScreen(screen* newParent);
    public:
      process();
      virtual ~process();
      const unsigned int getID() const;
      window* getWindow(unsigned int id);
      const unsigned int getWindowCount() const;
      virtual void operator() () = 0;
      
    };
  };
};
#endif