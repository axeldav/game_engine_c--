/***
* Detta är i stort sett spelmotorn. här är while loopen för spelet
* som läser in event från spelaren. Alla komponeneter läggs till
*
***/

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


//added vector för att man inte ska addera till comp vektorn under loopen 
void GameEngine::add(Component* comp) {
	added.push_back(comp);
}

void GameEngine::remove(Component* comp) {
	removed.push_back(comp);
}

void GameEngine::setPlayer(Player* player){
	this->player = player;
}


void GameEngine::removeEnemiesAndBulletsFromGame(){
	for (vector<Component*>::iterator i = comps.begin(); i != comps.end();){
		if ((*i)->getTag() == "bullet" || (*i)->getTag() == "enemy"){
			i = comps.erase(i);
		}
		else {
			i++;
		}
	}
}


void GameEngine::setQuitGame(bool boolVal){
	quitGame = boolVal;
}

void GameEngine::setQuitRun(bool boolval){
	quitRun = boolval;
}

void GameEngine::resetGameArena(){
	gameEngine.setQuitRun(false);
	removeEnemiesAndBulletsFromGame();
	player->resetCount();
}

void GameEngine::removeOldComponents(){
	//iteratorn pekar ut en pekare
		//tar bort dom komponenter som behöver bli borttagna 
		for (Component* c : removed)
			for (vector<Component*>::iterator i = comps.begin(); i != comps.end();)
				if (*i == c) {
					//delete c; //så delete behövs alltså inte, tror jag
					i = comps.erase(i); //returnerar iterator till nästa element, erase() destroys the element
					
				}
				else
					i++;
		removed.clear();
}

void GameEngine::addNewComponents(){
	//för varje varv, efter att vi har gått igenom alla komponenter och återgäldat händelser
	//så lägger vi till komponenter i comps från added
	//när vi inte längre itererar över comps
	for (Component* c : added)
		comps.push_back(c);
	added.clear();
}


void GameEngine::run() {  //här är while loopen där programmet körs
	

	Uint32 tickInterval = 1000 / FPS; //hur många millisekunder det ska dröja mellan olika ticks
	while (!quitRun) {

		Uint32 nextTick = SDL_GetTicks() + tickInterval; //32bits heltal, GetTicks, så får man antalet ticks sen start av programmet,  //när nästa tick ska vara
		SDL_Event event;
		while (SDL_PollEvent(&event)) {  // en kö med events som läses in. fortsätter så länge eventen inte  är null
			switch (event.type) {   //kolla vilken typ av event det är
				case SDL_QUIT: 
					setQuitRun(true);
					setQuitGame(true);
				 	break;  //bryter yttre while-loopen ?? inre menar jag??
				case SDL_MOUSEBUTTONDOWN:  //om musen är nedtryckt
					for (Component* c : comps)  // comps är en lista med alla Components
						c->mouseDown(event.button.x, event.button.y); // skickar med eventets x och y kordinat till componenternas mousedown funktioner
					break;
			} //switch
		} //inre while

		

		//varje component får ett tick, ett betende. tex att pistolskottet flyger upppåt
		for (Component* c : comps){			
			c->tick(); // i tick så rör sig bullet och enemy 
			c->collision(); 
		}


		removeOldComponents();
		eGenerator.addEnemyToGame();
		addNewComponents();



		SDL_SetRenderDrawColor(sys.get_ren(), 0, 0, 0, 255);
		SDL_RenderClear(sys.get_ren());
		for (Component* c: comps)
			c->draw(); //ritar alla komponenter på skärmen 
		SDL_RenderPresent(sys.get_ren());
		
		//räkna ut hur stor delay det ska vara, hur mkt tid det är kvar till nästa tick
		//fördröjer hela programmet
		int delay = nextTick - SDL_GetTicks(); //SDL_GetTicks() är sen start av programmet - nextTick är: SDL_GetTicks + tickInterval(som vi har bestämt)
		if (delay > 0)
			SDL_Delay(delay);

		

		counter++;	
	
	} // yttre while

	resetGameArena();
	
}

int GameEngine::getCounter(){
	return counter;
}




void GameEngine::showMenu(){
	
	Label* play = Label::getInstance((sys.get_win_width()/2) - 150, 
									sys.get_win_height() * 1/4,
									 300, 70, "Play");

	ExitButton* exitLbl = ExitButton::getInstance((sys.get_win_width()/2) - 150, 
									sys.get_win_height() * 3/4,
									 300, 70, "Exit Game");


	while (!quitGame){
		SDL_Event event;
		while (SDL_PollEvent(&event)){
			switch (event.type){
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

	} //while loopen

	delete play;
	delete exitLbl;
}
