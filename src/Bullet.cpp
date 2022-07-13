#include "Bullet.h"
#include "System.h"

Bullet* Bullet::getInstance(int x, Pistol* p){
	return new Bullet(x, p);
}
Bullet::Bullet(int x, Pistol* p) : Component(x, 500, 5, 20), pistol(p) {
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
	for(int i = 0; i < gameEngine.get_comps_size(); i++){
		auto c = gameEngine.get_comp_at_index(i);
		const SDL_Rect &rect_b = getRect();
		const SDL_Rect &rect_e = c->getRect();
		if(SDL_HasIntersection(  &rect_b , &rect_e ) ) {
		    if(tag == "bullet" && c->get_tag() == "enemy" ) {
			    
				//det är endast för denna raden som pistol behövs, Det vore känske bättre om spelmotorn hade en label isåfall. och den uppdaterades. 
				pistol->add_kill();	 

        	    gameEngine.remove(c);
			    gameEngine.remove(this);
		    }
		}
	}
}

		
	