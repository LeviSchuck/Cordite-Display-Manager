#include "screenimpl.h"
namespace cordite {
  namespace dm {
    screenImpl::screenImpl(){
      throw "You need to implement this!";
      //Init code here.
      
    }

    screenImpl::~screenImpl(){
      throw "You need to implement this!";
      //Clean up code here
    }

    SDL_Surface* screenImpl::render(){
      throw "You need to implement this!";
      throw "Make this thread safe!";
      return NULL;
    }
    window* screenImpl::getWindow(const unsigned int id){
      throw "You need to implement this!";
      throw "Make this thread safe!";
    }
    process* screenImpl::getProcess(const unsigned int id){
      throw "You need to implement this!";
      throw "Make this thread safe!";
    }
    void screenImpl::addProcess(process* newProcess){
      throw "You need to implement this!";
    }
    const unsigned int screenImpl::getNewWindowID(){
      throw "You need to implement this!";
      throw "Make this thread safe!";
    }


  };
};
