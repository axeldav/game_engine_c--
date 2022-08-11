#include "System.h"
#include <SDL2/SDL.h>

System::System() 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("CPROG GameEngine", 10, 10, win_width, win_height, 0);
	ren = SDL_CreateRenderer(win, -1, 0);
	Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	musik = Mix_LoadWAV( (resPath + "sounds/bgMusic.wav").c_str() );
	Mix_PlayChannel(-1, musik, -1);
	TTF_Init(); 
	font = TTF_OpenFont( (resPath + "fonts/arial.ttf").c_str(), 15);
}

System::~System() 
{
	TTF_CloseFont(font); 
	TTF_Quit();
	Mix_FreeChunk(musik);
	Mix_CloseAudio();
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
}

TTF_Font* System::get_font() const 
{
	return font;
}

SDL_Renderer* System::get_ren() const 
{
	return ren;
}

int System::get_win_height()
{
	return win_height;
}

int System::get_win_width()
{
	return win_width;
}

System sys;