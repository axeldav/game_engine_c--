#include "PlayButton.h"
#include "GameEngine.h"


PlayButton* PlayButton::getInstance(int x, int y, int w, int h, std::string txt){
    return new PlayButton(x,y,w,h,txt);
}

PlayButton::PlayButton(int x, int y, int w, int h, std::string txt):
    Label(x, y, w, h, txt){}


void PlayButton::mouseDown(int x, int y){
    
    const SDL_Rect &rect = getRect();
    
    if (x > rect.x && x < (rect.x + rect.w)){
        if (y > rect.y && y < (rect.y + rect.h) ){
		    gameEngine.run();
        }
    }    
}