#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Component.h"
#include <SDL2_image/SDL_image.h>
#include "System.h"
#include <string>
#include <stdlib.h>
#include "Label.h"
#include "Pistol.h"
#include "EnemyGenerator.h"


// Paths to resource folders. Change to your own path!
//std::string resPath = "/Users/kjellna/dev/cpp21/f13b_v2/resources/";
//std::string resPath = "../../resources/";
std::string resPath = "/Users/axeldavidsson/Downloads/f13b_slutkod/resources/";

//gameEngine global så att tillgång i klassen Bullet tex
GameEngine gameEngine;

//global för att komma åt samma container i GameEngineKlassen
EnemyGenerator eGenerator;

int main(int argc, char** argv) {


	/**g
	 * parameters
	 * 1. bilden, som ska användas för enemy
	 * 2. intervall - frekvensen den ska dyka upp 
	 * 3. speed - hur snabbt fienden rör sig
	 * */
	eGenerator.addEnemyTypeToList("images/dog.png", 80, 2);
	eGenerator.addEnemyTypeToList("images/bear.png", 130, 2.5);

	
	Label* lbl = Label::getInstance(10, 10, 100, 70, "0"); //skapa komponenter
	gameEngine.add(lbl);
	Pistol* pistol = new Pistol(lbl, "images/rocket.png");
	gameEngine.add(pistol);

	//kunna bestämma vilken typ av fiender som ska komma


	gameEngine.game_loop("Klick mouse to play", "You lost :(");
	
	return 0;
}
