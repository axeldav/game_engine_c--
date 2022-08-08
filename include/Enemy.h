#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Component.h"


class Enemy : public Component {
	public:
		static Enemy* getInstance(std::string img_path, int intervall, int speed);
		virtual ~Enemy();
		virtual void draw();
		virtual void collision(){};
		virtual void tick();
        int getIntervall();
        std::string getImg();
        double getSpeed();
        virtual Enemy* clone() = 0;
        virtual void addToGame();
    
    protected:
        Enemy(int x, std::string img_path, //x är x-led, där enemy dyker upp på skärmen, den är random. ej use input.
        int intervall, int speed); //intervall som enemy-objekt dyker upp på skärmen med   //speed som enemy-objketet har på skärmen
	private:
		SDL_Texture* texture;
		int counter = 0;
        int intervall;
        double speed;
        std::string img_path;	
};

#endif