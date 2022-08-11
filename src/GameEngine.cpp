#include "GameEngine.h"
#include "EnemyGenerator.h"
#include "Player.h"
#include "ExitButton.h"
#include "PlayButton.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

#define FPS 80

extern EnemyGenerator eGenerator;

void GameEngine::add(Component* comp) 
{
	added.push_back(comp);
}

void GameEngine::remove(Component* comp) 
{
	removed.push_back(comp);
}

void GameEngine::setPlayer(Player* player)
{
	this->player = player;
}


void GameEngine::removeEnemiesAndBulletsFromGame()
{
	for (vector<Component*>::iterator i = comps.begin(); i != comps.end();)
	{
		if ((*i)->getTag() == "bullet" || (*i)->getTag() == "enemy")
		{
			i = comps.erase(i);
		}
		else 
		{
			i++;
		}
	}
}


void GameEngine::setQuitGame(bool boolVal)
{
	quitGame = boolVal;
}

void GameEngine::setQuitRun(bool boolval)
{
	quitRun = boolval;
}

void GameEngine::resetGameArena()
{
	gameEngine.setQuitRun(false);
	removeEnemiesAndBulletsFromGame();
	player->resetCount();
}

void GameEngine::removeOldComponents()
{
	for (Component* c : removed)
		for (vector<Component*>::iterator i = comps.begin(); i != comps.end();)
			if (*i == c) 
			{
				i = comps.erase(i); 				
			}
			else
				i++;
	removed.clear();
}

void GameEngine::addNewComponents()
{
	for (Component* c : added)
		comps.push_back(c);
	added.clear();
}


void GameEngine::run() 
{
	Uint32 tickInterval = 1000 / FPS; 
	while (!quitRun) 
	{
		Uint32 nextTick = SDL_GetTicks() + tickInterval; 
		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{  
			switch (event.type) 
			{ 
				case SDL_QUIT: 
					setQuitRun(true);
					setQuitGame(true);
				 	break;  
				case SDL_MOUSEBUTTONDOWN:  
					for (Component* c : comps)  
						c->mouseDown(event.button.x, event.button.y); 
					break;
			}
		} 

		for (Component* c : comps)
		{			
			c->tick();
			c->collision(); 
		}

		removeOldComponents();
		eGenerator.addEnemyToGame();
		addNewComponents();

		SDL_SetRenderDrawColor(sys.get_ren(), 0, 0, 0, 255);
		SDL_RenderClear(sys.get_ren());
		for (Component* c: comps)
			c->draw(); 
		SDL_RenderPresent(sys.get_ren());
		
		int delay = nextTick - SDL_GetTicks(); 
		if (delay > 0)
			SDL_Delay(delay);

		counter++;	
	
	}

	resetGameArena();
}

int GameEngine::getCounter()
{
	return counter;
}

void GameEngine::showMenu()
{
	Label* play = Label::getInstance((sys.get_win_width()/2) - 150, 
									sys.get_win_height() * 1/4,
									 300, 70, "Play");

	ExitButton* exitLbl = ExitButton::getInstance((sys.get_win_width()/2) - 150, 
									sys.get_win_height() * 3/4,
									 300, 70, "Exit Game");

	while (!quitGame)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT: 
					setQuitGame(true);
					setQuitRun(true);
					break;
				case SDL_MOUSEBUTTONDOWN:
					play->mouseDown(event.button.x, event.button.y);
					exitLbl->mouseDown(event.button.x, event.button.y);		
			}
		}

	SDL_RenderClear(sys.get_ren());
	SDL_SetRenderDrawColor(sys.get_ren(), 0, 0, 0, 255);
	play->draw();
	exitLbl->draw();
	SDL_RenderPresent(sys.get_ren());
	}

	delete play;
	delete exitLbl;
}