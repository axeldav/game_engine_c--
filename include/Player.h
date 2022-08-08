/***
 * 
 * 
 * 
***/
#ifndef PLAYER_H
#define PLAYER_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Component.h"

class Label;


class Player : public Component { //ärver från Component 
	public:
		Player(Label* lbl, std::string img_file);
		~Player();
		void draw();
		void collision();
		void tick();
		void mouseDown(int x, int y);
		void add_kill();
		void setLabel(Label* lbl);
		void resetCount();

	private:
		SDL_Texture* texture;
		Label* label;
		int x, y; 
		int kill_counter;

};

#endif