#include "Label.h"
#include <SDL2/SDL_ttf.h>
#include "System.h"
#include <iostream>
#include <string>

using namespace std;


Label* Label::getInstance(int x, int y, int w, // istället för konstruktor används getInstance, returnerar en pekare, alltså hamnar objektet på heapen
	int h, std::string txt) {
	return new Label(x, y, w, h, txt); //hamnar på heapen, new -keyword
}

Label::Label(int x, int y, int w, int h,
	std::string txt): Component(x,y,w,h), text(txt) //initiera basklass-objektet som är Component, text med txt
{
    
	SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), { 0,97,0 }); //kräver c_sträng
	texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf); //nu har vi en texture som vi kan använda när vi ritar
	SDL_FreeSurface(surf); 
}


void Label::draw() {
	const SDL_Rect &rect = getRect();
	SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect); //getRect, hämtar rectangeln från component, destination för texturen
}															  //renderare från sys,

Label::~Label()
{
	SDL_DestroyTexture(texture);
}

string Label::getText() const {
	return text;
}
void Label::setText(std::string newText) { //texturen måste renderas om i denna funktionen
	
    text = newText;
	SDL_DestroyTexture(texture); // det här förstör labels nuvarande texture, som är implementerad i label.h
	SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(),
		text.c_str(), { 0,97,0 }); // skapar en ny surface 
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf); // skapar en texture från surface
	SDL_FreeSurface(surf); //ta bort surface
}	
