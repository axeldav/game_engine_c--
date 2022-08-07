

#include "Enemy.h"
#include "GameEngine.h"

#include <memory>

#include <iostream>

extern GameEngine gameEngine; 

//"images/dog.png" - img_path till hunden

/**
 * parameters:
 * i - interval
 * s - speed
 * */
/*
Enemy* Enemy::getInstance(std::string img, int i, int s){
	int x = 10 + rand() % (sys.get_win_width() - 20);
	return new Enemy(x, img, i, s);
}
*/

//Enemy is a subclass to Component
Enemy::Enemy(int x, std::string img_path, int intervall, int speed) : Component(x, 0, 30, 30){
	texture = IMG_LoadTexture(sys.get_ren(), (resPath + img_path).c_str() ); // here is sdl_texture 
	tag = "enemy";
	this->img_path = img_path;
	this->intervall = intervall;
	this->speed = speed;
}
Enemy::~Enemy(){
	SDL_DestroyTexture(texture);
}
void Enemy::draw(){
	const SDL_Rect &rect = getRect();
	SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
	//delete rect; //provar att lägga till denna
}
void Enemy::tick(){
    counter++;
	if (rect.y >= sys.get_win_height()){ // om detta händer så ska spelet avslutas, man förlorade
		gameEngine.setQuitRun(true);
	}
        //ses.remove(this); 		 
	else if (counter % 1 == 0) 
		rect.y = rect.y + speed;
}

int Enemy::getIntervall(){
    return intervall;
}

double Enemy::getSpeed(){
    return speed; 
}

std::string Enemy::getImg(){
    return img_path;
}

		
