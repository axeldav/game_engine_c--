#include "Enemy.h"
#include "GameEngine.h"
#include <memory>
#include <iostream>

extern GameEngine gameEngine; 

Enemy::Enemy(int x, std::string img_path, int intervall, int speed) : Component(x, 0, 30, 30)
{
	texture = IMG_LoadTexture(sys.get_ren(), (resPath + img_path).c_str() ); 
	tag = "enemy";
	this->img_path = img_path;
	this->intervall = intervall;
	this->speed = speed;
}

Enemy::~Enemy()
{
	SDL_DestroyTexture(texture);
}

void Enemy::draw()
{
	const SDL_Rect &rect = getRect();
	SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
}

void Enemy::tick()
{
    counter++;
	if (rect.y >= sys.get_win_height())
	{
		gameEngine.remove(this);
		gameEngine.setQuitRun(true);
	} 		 
	else if (counter % 1 == 0) 
		rect.y = rect.y + speed;
}

void Enemy::collision(){
	for(auto i = gameEngine.compsBegin(); i != gameEngine.compsEnd(); i++){
		const SDL_Rect &rect_a = getRect();
		const SDL_Rect &rect_b = (*i)->getRect();
		if(SDL_HasIntersection(&rect_a, &rect_b)){
			if((*i)->getTag() == "player"){
				gameEngine.remove(this);
				gameEngine.setQuitRun(true);
			}
		}


	}
}

void Enemy::addToGame(){
	if ((gameEngine.getCounter() % intervall) == 0){
			gameEngine.add(clone());
		}
}

int Enemy::getIntervall(){
    return intervall;
}

double Enemy::getSpeed()
{
    return speed; 
}

std::string Enemy::getImg()
{
    return img_path;
}