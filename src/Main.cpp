#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Component.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include <string>
#include <stdlib.h>
#include "Label.h"
#include "Player.h"
#include "EnemyGenerator.h"
#include "EnemyBear.h"
#include "EnemyDog.h"


#include <iostream>
#include <stdio.h>

// Paths to resource folders. Change to your own path!
//std::string resPath = "/Users/kjellna/dev/cpp21/f13b_v2/resources/";
//std::string resPath = "../../resources/";
std::string resPath = "/Users/axeldavidsson/Downloads/f13b_slutkod/resources/";
//testkommentar med Sabinas resPath
//std::string resPath = "/Users/sabina/Desktop/CPROG/cprog_project/resources/";

//gameEngine global så att tillgång i klassen Bullet tex
GameEngine gameEngine;

//global för att komma åt samma container i GameEngineKlassen
EnemyGenerator eGenerator;


int main(int argc, char** argv) {

	/*
	* Lägger till de olika fienderna man vill använda
	* param:
	* bildfilen
	* interval - hur ofta fienden ska komma
	* 
	**/
	eGenerator.addEnemy(EnemyBear::getInstance("images/bear.png", 130, 2.0));
	eGenerator.addEnemy(EnemyDog::getInstance("images/dog.png", 1454, 1.5));

	
	//hur många man har skjutit
	Label* killLabel = Label::getInstance(10, 10, 100, 70, "0"); //skapa komponenter
	gameEngine.add(killLabel);
	Player* player = new Player(killLabel, "images/rocket.png");
	gameEngine.setPlayer(player);
	gameEngine.add(player);

	gameEngine.showMenu();

	delete player;
	delete killLabel;
	
	return 0;
}
