/***
 * 
 * 
 * 
***/
#ifndef PISTOL_H
#define PISTOL_H
//#include "Label.h"
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
		int counter = 0;
		int kill_counter;

        Player(const Player&) = delete;
        const Player& operator = (const Player&) = delete;
};

#endif