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

std::string resPath = "../../resources/";

GameEngine gameEngine;

EnemyGenerator eGenerator;

int main(int argc, char** argv) {

	eGenerator.addEnemy(EnemyBear::getInstance("images/bear.png", 130, 2));
	eGenerator.addEnemy(EnemyDog::getInstance("images/dog.png", 1454, 1));

	Label* killCountLbl = Label::getInstance(10, 10, 100, 70, "0"); 
	gameEngine.add(killCountLbl);
	Player* player = new Player(killCountLbl, "images/rocket.png");
	gameEngine.setPlayer(player);
	gameEngine.add(player);

	gameEngine.showMenu();

	delete player;
	delete killCountLbl;
	
	return 0;
}