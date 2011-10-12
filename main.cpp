#include <iostream>
#include <SDL/SDL.h>
#include "factory.h"
#include "screen.h"
cordite::dm::events::E_KEY sdlkeyToDMEvent(SDL_Event& ev){
  if(ev.type == SDL_MOUSEBUTTONDOWN || ev.type == SDL_MOUSEBUTTONUP){
    switch(ev.button.button){
      case SDL_BUTTON_LEFT:
	return cordite::dm::events::KEY_LMOUSE;
      case SDL_BUTTON_RIGHT:
	return cordite::dm::events::KEY_RMOUSE;
      case SDL_BUTTON_MIDDLE:
	return cordite::dm::events::KEY_MMOUSE;
      default:
	break;
    }
  }//It doesn't look like we support Mouse X1/X2
  //Or at least have an enumeration for them...
  if(ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP){
   //Fun! Lucky for us, they made most of theirs following the ascii
   switch(ev.key.keysym.sym){
     case 'a':
       return cordite::dm::events::KEY_KEY_A;
     case 'b':
       return cordite::dm::events::KEY_KEY_B;
     case 'c':
       return cordite::dm::events::KEY_KEY_C;
     case 'd':
       return cordite::dm::events::KEY_KEY_D;
     case 'e':
       return cordite::dm::events::KEY_KEY_E;
     case 'f':
       return cordite::dm::events::KEY_KEY_F;
     case 'g':
       return cordite::dm::events::KEY_KEY_G;
     case 'h':
       return cordite::dm::events::KEY_KEY_H;
     case 'i':
       return cordite::dm::events::KEY_KEY_I;
     case 'j':
       return cordite::dm::events::KEY_KEY_J;
     case 'k':
       return cordite::dm::events::KEY_KEY_K;
     case 'l':
       return cordite::dm::events::KEY_KEY_L;
     case 'm':
       return cordite::dm::events::KEY_KEY_M;
     case 'n':
       return cordite::dm::events::KEY_KEY_N;
     case 'o':
       return cordite::dm::events::KEY_KEY_O;
     case 'p':
       return cordite::dm::events::KEY_KEY_P;
     case 'q':
       return cordite::dm::events::KEY_KEY_Q;
     case 'r':
       return cordite::dm::events::KEY_KEY_R;
     case 's':
       return cordite::dm::events::KEY_KEY_S;
     case 't':
       return cordite::dm::events::KEY_KEY_T;
     case 'u':
       return cordite::dm::events::KEY_KEY_U;
     case 'v':
       return cordite::dm::events::KEY_KEY_V;
     case 'w':
       return cordite::dm::events::KEY_KEY_W;
     case 'x':
       return cordite::dm::events::KEY_KEY_X;
     case 'y':
       return cordite::dm::events::KEY_KEY_Y;
     case 'z':
       return cordite::dm::events::KEY_KEY_Z;
     case '\t':
       return cordite::dm::events::KEY_TAB;
     case '\b':
       return cordite::dm::events::KEY_BACK;
     case '\r':
       return cordite::dm::events::KEY_RETURN;
     case SDLK_ESCAPE:
       return cordite::dm::events::KEY_ESCAPE;
     case ' ':
       return cordite::dm::events::KEY_SPACE;
     case '\'':
       return cordite::dm::events::KEY_QUOTE;
     case SDLK_0:
       return cordite::dm::events::KEY_KEY_0;
     case SDLK_1:
       return cordite::dm::events::KEY_KEY_1;
     case SDLK_2:
       return cordite::dm::events::KEY_KEY_2;
     case SDLK_3:
       return cordite::dm::events::KEY_KEY_3;
     case SDLK_4:
       return cordite::dm::events::KEY_KEY_4;
     case SDLK_5:
       return cordite::dm::events::KEY_KEY_5;
     case SDLK_6:
       return cordite::dm::events::KEY_KEY_6;
     case SDLK_7:
       return cordite::dm::events::KEY_KEY_7;
     case SDLK_8:
       return cordite::dm::events::KEY_KEY_8;
     case SDLK_9:
       return cordite::dm::events::KEY_KEY_9;
     case SDLK_LEFT:
       return cordite::dm::events::KEY_LEFT;
     case SDLK_RIGHT:
       return cordite::dm::events::KEY_RIGHT;
     case SDLK_UP:
       return cordite::dm::events::KEY_UP;
     case SDLK_DOWN:
       return cordite::dm::events::KEY_DOWN;
       //I'm not going to bother to implement more than that.
     default:
       break;
   }
  }
  return cordite::dm::events::KEY_NULL;
}
int main(int argc, char **argv) {
    SDL_Surface* scr = 0;
    SDL_Surface* rendered = 0;
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
    
    scr = SDL_SetVideoMode(800,600,32,SDL_SWSURFACE);
    cordite::dm::screen* vcomp;
    bool quit = false;
    SDL_Event event;
    try {
      vcomp = cordite::dm::factory::createScreen();
      while(!quit){
	if(rendered){
	  SDL_FreeSurface(rendered);
	  rendered = 0;
	}
	//^^ This may not be the most optimal 
	
	//Now, lets gather some of us events
	cordite::dm::events::eventList elist;
	elist.hasEvents = false;
	while(SDL_PollEvent(&event)){
	 if(event.type == SDL_QUIT){
	  quit = true; 
	 } 
	 //Now for the real stuff.
	 
	 if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP
	   || event.type == SDL_MOUSEBUTTONDOWN
	   || event.type == SDL_MOUSEBUTTONUP
	){
	   cordite::dm::events::eventBase e;
	   e.key = sdlkeyToDMEvent(event);
	   switch(event.type){
	    case SDL_KEYDOWN:
	    case SDL_MOUSEBUTTONDOWN:
	      e.kind = cordite::dm::events::PRESS;
	      break;
	    case SDL_KEYUP:
	    case SDL_MOUSEBUTTONUP:
	      e.kind = cordite::dm::events::RELEASE;
	      break;
	    default:
	      break;
	  }
	  elist.hasEvents = true;
	  elist.events.push_back(e);
	 }
	
	 if(event.type == SDL_MOUSEMOTION){
	   dim2di pos;
	   pos.x = event.motion.x;
	   pos.y = event.motion.y;
	   vcomp->passMouse(pos);
	 }
	}
	if(elist.hasEvents){
	  vcomp->passEvents(elist);
	}
	
	//Push to the vcomp;
	
	rendered = vcomp->render();
	if(rendered){
	  SDL_BlitSurface(rendered,NULL,scr,NULL);
	}
	SDL_Flip(scr);
	SDL_Delay(33);//~30hz
      }
    }catch(char const* ex){
      std::cout << "Exception thrown: " << ex << "\n";
    }
    if(rendered){
      SDL_FreeSurface(rendered);
    }
    
    SDL_Quit();
    return 0;
}
