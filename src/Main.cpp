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


//int memorycounter = 0; 

/*
//overriding new-operator globally
void* operator new(size_t size)
{
	printf("allocated ");
	//printf("%d", size);
	printf("\n");
	memorycounter++;


	return malloc(size);
}

void operator delete(void* memory) noexcept
{
	printf("free ");
	printf("\n");
	memorycounter--;
	printf("memory counter: ");
	printf("%d", memorycounter);
	printf("\n");
	free(memory);
	
}
*/

int main(int argc, char** argv) {


	/**
	 * parameters
	 * 1. bilden, som ska användas för enemy
	 * 2. intervall - frekvensen den ska dyka upp 
	 * 3. speed - hur snabbt fienden rör sig
	 * */
	/*
	eGenerator.addEnemyTypeToList("images/dog.png", 1466, 1.5);
	eGenerator.addEnemyTypeToList("images/bear.png", 130, 2.0);
	*/

	eGenerator.addEnemy(EnemyBear::getInstance("images/bear.png", 130, 2.0));
	eGenerator.addEnemy(EnemyBear::getInstance("images/dog.png", 1454, 1.5));

	//eGenerator.addEnemy(EnemyBear::getInstance("images/bear.png", 130, 2.0));

	
	Label* lbl = Label::getInstance(10, 10, 100, 70, "0"); //skapa komponenter
	gameEngine.add(lbl);
	Player* player = new Player(lbl, "images/rocket.png");
	gameEngine.setPlayer(player);
	gameEngine.add(player);



	gameEngine.showMenu();
	//gameEngine.game_loop("Klick mouse to play", "You lost :(");


	delete player;
	delete lbl;
	
	return 0;
}
