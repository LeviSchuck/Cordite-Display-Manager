#include "window.h"
namespace cordite {
  namespace dm {
    window::window(){
      throw "You need to implement this!";
    }

    window::~window(){
      throw "You need to implement this!";
      
    }
    threaded_surface& window::getCurrentSurface(){
      throw "You need to implement this!";
      throw "Make this thread safe.";
    }
    const dim2di window::getDimensions() const{
      throw "Make this thread safe.";
      return dim;
    }
    const unsigned int window::getID(){
      return id;//Never going to change.
    }
    const std::string window::getTitle() const{
      throw "Make this thread safe.";
      return title;
    }
    const bool window::isChanged() const{
      throw "You need to implement this!";
      throw "Implement this!";
    }
    const bool window::isFocused() const{
      throw "You need to implement this!";
      throw "Make this thread safe.";
    }
    const bool window::isWindowed(){
      throw "You need to implement this!";
      throw "Make this thread safe.";
    }
    void window::mouseHover(dim2di& pos){
      throw "You need to implement this!";
      throw "Make this thread safe.";
    }
    void window::setDimensions(const dim2di& d){
      throw "You need to implement this!";
      throw "Make this thread safe.";
    }
    void window::setEvents(const long unsigned int time , const cordite::dm::events::eventList& ev){
      throw "You need to implement this!";
      throw "Make this thread safe.";
    }
    void window::setFocus(const bool focus){
      throw "You need to implement this!";
      throw "Make this thread safe.";
    }

  };
};
