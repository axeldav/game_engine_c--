#pragma once

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_ttf.h>

class System
{
	public:
		System();
		~System();
		TTF_Font* get_font() const;
		SDL_Renderer* get_ren() const;
		int get_win_width();
		int get_win_height();

	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		Mix_Chunk* musik;
		TTF_Font* font;
		static const int win_width = 700;
		static const int win_height = 500;	
};

extern std::string resPath;
extern System sys;
