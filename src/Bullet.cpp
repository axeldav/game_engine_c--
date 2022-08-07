#include "Bullet.h"
#include "System.h"
#include "GameEngine.h"

extern GameEngine gameEngine; 

Bullet* Bullet::getInstance(int x, Player* p){
	return new Bullet(x, p);
}

Bullet::Bullet(int x, Player* p) : Component(x, 500, 5, 20), player(p) {
	// Path to your own 'images' folder.
	//texture = IMG_LoadTexture(sys.ren, "/Users/kjellna/dev/cpp21/f13b/images/dot40x40.bmp");
	texture = IMG_LoadTexture(sys.get_ren(), (resPath + "images/dot40x40.bmp").c_str() );
	tag = "bullet";
}
Bullet::~Bullet() {
	SDL_DestroyTexture(texture);
}
void Bullet::draw() {
	// Code adjustment to handle the address to temporary object. 
	const SDL_Rect &rect = getRect();
	//SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
	SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
	
}
void Bullet::tick() { //ett tick i varje loop, eller liknande
			counter++;
			if (rect.y <= 0) //om bullet är högst upp på skärmen så ska vi ta bort bullet, annars är den kvar i minnet och skräpar, utanför skärmen
				gameEngine.remove(this);  //tick anropas under iteration I session-comps så på samma sätt som I added, så måste den tas bort efter iterationen
			else if (counter % 1 == 0) //gör att den flyger långsammare genom "counter % 10 == 0" . var tionde tick eller liknane
				rect.y = rect.y - 5; //bullet flyger uppåt
}
void Bullet::collision(){
	
	for(auto i = gameEngine.compsBegin(); i != gameEngine.compsEnd(); i++ ) {
		const SDL_Rect &rect_a = getRect();
		const SDL_Rect &rect_b = (*i)->getRect(); //de-referencing 
		if(SDL_HasIntersection(&rect_a, &rect_b)){
			if((*i)->getTag() == "enemy"){ 
				player->add_kill();
				gameEngine.remove((*i));
				gameEngine.remove(this);
			}
		}
	}
}

		
	