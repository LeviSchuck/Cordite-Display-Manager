#include "window.h"
namespace cordite {
  namespace dm {
    window::window(){
      throw "You need to implement constructor!";
    }

    window::~window(){
      throw "You need to implement constructor!";
      
    }
    threaded_surface& window::getCurrentSurface(){
      throw "You need to implement getCurrentSurface!";
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
      throw "You need to implement isChanged!";
      throw "Implement this!";
    }
    const bool window::isFocused() const{
      throw "You need to implement isFocused!";
      throw "Make this thread safe.";
    }
    const bool window::isWindowed(){
      throw "You need to implement isWindowed!";
      throw "Make this thread safe.";
    }
    void window::mouseHover(dim2di& pos){
      throw "You need to implement mouseHover!";
      throw "Make this thread safe.";
    }
    void window::setDimensions(const dim2di& d){
      throw "You need to implement setDimensions!";
      throw "Make this thread safe.";
    }
    void window::setEvents(const long unsigned int time , const cordite::dm::events::eventList& ev){
      throw "You need to implement setEvents!";
      throw "Make this thread safe.";
    }
    void window::setFocus(const bool focus){
      throw "You need to implement setFocus!";
      throw "Make this thread safe.";
    }
    const bool window::isTask() const{
      return true;
    }
    const bool window::allowsFocus() const{
      return true;
    }


  };
};
