#include "process.h"
#include "screen.h"
namespace cordite {
  namespace dm {
    const unsigned int process::getID() const{
      return id;
    }
    const unsigned int process::getWindowCount() const{
      return windows.size();
    }
    window* process::getWindow(unsigned int id){
      return windows[id];
    }
    void process::attachToScreen(screen* newParent){
      if(!parent){
	parent = newParent;
	newParent->addProcess(this);
	//Note: add process sets stuff like this current application's ID
      }else{
	throw "You need to detach first.";
      }
    }
    process::process(){
      parent = 0;
    }
    process::~process(){
      throw "You need to implement deconstructor!";
    }


  };
};