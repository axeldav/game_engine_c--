#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Component.h"
#include "Label.h"
#include <vector>
#include "System.h"
#include "Player.h"

class GameEngine
{
public:
	void add(Component* comp);
	void remove(Component* comp);
	void showMenu();
	void run();
	void setQuitGame(bool boolVal);
	void setQuitRun(bool boolVal);
	int getCounter();
	void setPlayer(Player* player);
	std::vector<Component*>::iterator compsBegin()  {return comps.begin();}
	std::vector<Component*>::iterator compsEnd()  {return comps.end();}
private:
	int counter = 1;
	bool quitGame = false;
	bool quitRun = false;
	Player* player;
	std::vector<Component*> comps;
	std::vector<Component*> added, removed;
	std::vector<Component*> enemyList; 
	void removeEnemiesAndBulletsFromGame();
	void resetGameArena();
	void removeOldComponents(); 
	void addNewComponents(); 
};

extern GameEngine gameEngine;

# endif