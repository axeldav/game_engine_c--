#include "Player.h"
#include "Bullet.h"
#include "GameEngine.h"

extern GameEngine gameEngine; 

Player::Player(Label* lbl, std::string img_file) :Component(250, 450, 40, 40), kill_counter(0)
{
	texture = IMG_LoadTexture(sys.get_ren(), (resPath + img_file).c_str() );
	tag = "player";
	label = lbl;
}

Player::~Player()
{
	SDL_DestroyTexture(texture);
}

void Player::setLabel(Label* lbl)
{
	label = lbl;
}

void Player::draw() 
{
	const SDL_Rect &rect = getRect();
	SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
}

void Player::collision(){}

void Player::tick()
{
	SDL_GetMouseState(&x, &y);
	rect.x = x - 20;
}
void Player::mouseDown(int x, int y) 
{ 
	gameEngine.add(Bullet::getInstance(x,this));
}
void Player::add_kill()
{
	kill_counter++;
	label->setText(std::to_string(kill_counter));
}

void Player::resetCount()
{
	kill_counter = 0;
	label->setText(std::to_string(kill_counter));
}	