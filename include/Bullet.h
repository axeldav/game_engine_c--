#ifndef BULLET_H
#define BULLET_H

#include "Component.h"
#include <SDL2/SDL.h>
//#include "System.h"

class Player; 

class Bullet : public Component {  //ärver från component
	public:
		static Bullet* getInstance(int x, Player* p);
		~Bullet();
		void draw();
		void tick();
		void collision();
    protected:
        Bullet(int x, Player* p);
	private:
		SDL_Texture* texture;
		int counter; //räkna ticks med counter
		Player *player;        
};

//ska den vara här eller i cpp filen??
//extern GameEngine gameEngine;

#endif 
