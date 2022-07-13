#ifndef BULLET_H
#define BULLET_H

#include "Component.h"
#include "GameEngine.h"
#include "Pistol.h"
#include <SDL2/SDL.h>
//#include "System.h"

class Pistol; 

class Bullet : public Component {  //ärver från component
	public:
		static Bullet* getInstance(int x, Pistol* p);
		~Bullet();
		void draw();
		void tick();
		void collision();
    protected:
        Bullet(int x, Pistol* p);
	private:
		SDL_Texture* texture;
		int counter; //räkna ticks med counter
		Pistol *pistol;

        Bullet(const Bullet&) = delete;
        const Bullet& operator = (const Bullet&) = delete;
        
};

//ska den vara här eller i cpp filen??
extern GameEngine gameEngine;

#endif 
