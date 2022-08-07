#include "ExitButton.h"
#include "GameEngine.h"


ExitButton* ExitButton::getInstance(int x, int y, int w, int h, std::string txt){
    return new ExitButton(x,y,w,h,txt);
}

ExitButton::ExitButton(int x, int y, int w, int h, std::string txt):
    Label(x,y,w,h,txt){}


void ExitButton::mouseDown(int x, int y){

    const SDL_Rect &rect = getRect();

    if (x > rect.x && x < (rect.x + rect.w)){ //här är det nåt fel
        if (y > rect.y && y < (rect.y + rect.h) ){
		    gameEngine.setQuitGame(true);
        }
    }    
}