#include "factory.h"

namespace cordite {
  namespace dm {
    screen* factory::createScreen(){
      throw "You need to implement the createScreen!";
    }
  };
};