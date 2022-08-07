#include "Player.h"
#include "Bullet.h"
#include "GameEngine.h"

extern GameEngine gameEngine; 

Player::Player(Label* lbl, std::string img_file) :Component(250, 450, 40, 40), kill_counter(0){
	//texture
	texture = IMG_LoadTexture(sys.get_ren(), (resPath + img_file).c_str() );
	tag = "player";
	label = lbl;
}
Player::~Player(){
	SDL_DestroyTexture(texture);
}

void Player::setLabel(Label* lbl){
	label = lbl;
}

void Player::draw() {
	const SDL_Rect &rect = getRect();
	SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
}
void Player::collision(){}	
void Player::tick(){
    //counter++;
	SDL_GetMouseState(&x, &y);  //vid varje tick så ska den få musens x-cordinat och placera pistolen där
	rect.x = x - 20;
	/*
    if (counter % 80 == 0){
		Enemy* e = Enemy::getInstance(); //create enemy
	    gameEngine.add(e);
	}
    */
}
void Player::mouseDown(int x, int y) { //överskuggad mouse down //pistolen reagerar på när användaren trycker på musknappen
	//skapa en bullet och placera bland komponenterna
	//Bullet* b = Bullet::getInstance(x, this); //tar emot bara x-kord, för att veta var den befinner sig på skärmen, vilken kollumn 
    gameEngine.add(Bullet::getInstance(x,this));//adds to - comps
}
void Player::add_kill(){
	kill_counter++;
	label->setText(std::to_string(kill_counter));
}

void Player::resetCount(){
	kill_counter = 0;
	label->setText(std::to_string(kill_counter));
}


	