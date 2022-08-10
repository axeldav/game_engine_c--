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

std::string resPath = "/Users/axeldavidsson/Downloads/f13b_slutkod/resources/";
//std::string resPath = "/Users/sabina/Desktop/CPROG/cprog_project/resources/";

GameEngine gameEngine;

EnemyGenerator eGenerator;


int main(int argc, char** argv) {

	eGenerator.addEnemy(EnemyBear::getInstance("images/bear.png", 130, 2));
	eGenerator.addEnemy(EnemyDog::getInstance("images/dog.png", 1454, 1));

	Label* lbl = Label::getInstance(10, 10, 100, 70, "0"); 
	gameEngine.add(lbl);
	Player* player = new Player(lbl, "images/rocket.png");
	gameEngine.setPlayer(player);
	gameEngine.add(player);

	gameEngine.showMenu();

	delete player;
	delete lbl;
	
	return 0;
}