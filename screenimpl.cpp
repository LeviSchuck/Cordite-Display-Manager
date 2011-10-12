#include "screenimpl.h"
namespace cordite {
  namespace dm {
    screenImpl::screenImpl(){
      throw "You need to implement constructor!";
      //Init code here.
      
    }

    screenImpl::~screenImpl(){
      throw "You need to implement the deconstructor!";
      //Clean up code here
    }

    SDL_Surface* screenImpl::render(){
      throw "You need to implement render!";
      throw "Make this thread safe!";
      return NULL;
    }
    window* screenImpl::getWindow(const unsigned int id){
      throw "You need to implement getWindow!";
      throw "Make this thread safe!";
    }
    process* screenImpl::getProcess(const unsigned int id){
      throw "You need to implement getProcess!";
      throw "Make this thread safe!";
    }
    void screenImpl::addProcess(process* newProcess){
      throw "You need to implement addProcess!";
    }
    const unsigned int screenImpl::getNewWindowID(){
      throw "You need to implement getNewWindowID!";
      throw "Make this thread safe!";
    }
    const dim2di screenImpl::getDimensions() const{
      throw "You need to implement getDimensions!";
      throw "Make this thread safe!";
    }
    void screenImpl::setDimensions(const dim2di d){
      throw "You need to implement setDimensions!";
      
    }
    void screenImpl::passMouse(dim2di pos){
      throw "You need to implement passMouse!";
    }




  };
};
