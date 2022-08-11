#include "Bullet.h"
#include "System.h"
#include "GameEngine.h"

extern GameEngine gameEngine; 

Bullet* Bullet::getInstance(int x, Player* p)
{
	return new Bullet(x, p);
}

Bullet::Bullet(int x, Player* p) : Component(x, 500, 5, 20), player(p) 
{
	texture = IMG_LoadTexture(sys.get_ren(), (resPath + "images/dot40x40.bmp").c_str() );
	tag = "bullet";
}

Bullet::~Bullet() 
{
	SDL_DestroyTexture(texture);
}

void Bullet::draw() 
{
	const SDL_Rect &rect = getRect();
	SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
}

void Bullet::tick() 
{
	counter++;
	if (rect.y <= 0) 
		gameEngine.remove(this);  
	else if (counter % 1 == 0)
		rect.y = rect.y - 5; 
}

void Bullet::collision()
{	
	for(auto i = gameEngine.compsBegin(); i != gameEngine.compsEnd(); i++) 
	{
		const SDL_Rect &rect_a = getRect();
		const SDL_Rect &rect_b = (*i)->getRect(); 
		if(SDL_HasIntersection(&rect_a, &rect_b))
		{
			if((*i)->getTag() == "enemy")
			{ 
				player->add_kill();
				gameEngine.remove((*i));
				gameEngine.remove(this);
			}
		}
	}
}