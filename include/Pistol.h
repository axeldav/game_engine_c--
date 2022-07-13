/***
 * 
 * 
 * 
***/
#ifndef PISTOL_H
#define PISTOL_H

#include "Label.h"
#include "SDL2/SDL.h"
#include "SDL_image.h"


class Pistol : public Component { //ärver från Component 
	public:
		Pistol(Label* lbl, std::string img_file);
		~Pistol();
		void draw();
		void collision();
		void tick();
		void mouseDown(int x, int y);
		void add_kill();

	private:
		SDL_Texture* texture;
		Label* label;
		int x, y; 
		int counter = 0;
		int kill_counter;

        Pistol(const Pistol&) = delete;
        const Pistol& operator = (const Pistol&) = delete;
};

#endif