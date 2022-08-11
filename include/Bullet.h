#ifndef BULLET_H
#define BULLET_H

#include "Component.h"
#include <SDL2/SDL.h>

class Player; 

class Bullet : public Component 
{  
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
	int counter; 
	Player *player;        
};

#endif 
