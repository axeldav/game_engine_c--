/***
* Detta är i stort sett spelmotorn. här är while loopen för spelet
* som läser in event från spelaren. Alla komponeneter läggs till
*
***/

#include "GameEngine.h"
#include "EnemyGenerator.h"
#include <SDL2/SDL.h>
#include <SDL_image.h>

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

Component* GameEngine::get_comp_at_index(int i){
	return comps[i];
}
int GameEngine::get_comps_size(){
	return comps.size();
}

bool GameEngine::wait_for_click_window(std::string start_message){

	Label* lbl = Label::getInstance((sys.get_win_width()/2) - 300, 
									sys.get_win_height()/2,
									 300, 70, start_message);

	SDL_RenderClear(sys.get_ren());
	SDL_SetRenderDrawColor(sys.get_ren(), 0, 0, 0, 255);
	lbl->draw();
	SDL_RenderPresent(sys.get_ren());

	bool quit = false;
	while (!quit){
		SDL_Event event;
		while (SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_QUIT: return false; break;
				case SDL_MOUSEBUTTONDOWN:
					return true; 
					//spelet ska startas ; 
					break;
			}
		}
	}
	return false;
}


void GameEngine::quit_run_loop(){
	quit_run = true;
}


void GameEngine::run() {  //här är while loopen där programmet körs
	quit_run = false;
	Uint32 tickInterval = 1000 / FPS; //hur många millisekunder det ska dröja mellan olika ticks
	while (!quit_run) {

		Uint32 nextTick = SDL_GetTicks() + tickInterval; //32bits heltal, GetTicks, så får man antalet ticks sen start av programmet,  //när nästa tick ska vara
		SDL_Event event;
		while (SDL_PollEvent(&event)) {  // en kö med events som läses in. fortsätter så länge eventen inte  är null
			switch (event.type) {   //kolla vilken typ av event det är
				case SDL_QUIT: quit_run = true; break;  //bryter yttre while-loopen
				case SDL_MOUSEBUTTONDOWN:  //om musen är nedtryckt
					for (Component* c : comps)  // comps är en lista med alla Components
						c->mouseDown(event.button.x, event.button.y); // skickar med eventets x och y kordinat till componenternas mousedown funktioner
					break;
			} //switch
		} //inre while

		

		//varje component får ett tick, ett betende. tex att pistolskottet flyger upppåt
		for (Component* c : comps){			
			c->collision(); 
			c->tick(); // i tick så rör sig bullet och enemy 
		}


		eGenerator.addEnemyToGame();

		//för varje varv, efter att vi har gått igenom alla komponenter och återgäldat händelser
		//så lägger vi till komponenter i comps från added
		//när vi inte längre itererar över comps
		for (Component* c : added)
			comps.push_back(c);
		added.clear();

	
		//iteratorn pekar ut en pekare
		//tar bort dom komponenter som behöver bli borttagna 
		for (Component* c : removed)
			for (vector<Component*>::iterator i = comps.begin(); i != comps.end();)
				if (*i == c) {
					i = comps.erase(i); //returnerar iterator till nästa element, erase() destroys the element
				}
				else
					i++;
		removed.clear();

		SDL_SetRenderDrawColor(sys.get_ren(), 0, 0, 0, 255);
		SDL_RenderClear(sys.get_ren());
		for (Component* c : comps)
			c->draw(); //ritar alla komponenter på skärmen 
		SDL_RenderPresent(sys.get_ren());
		
		//räkna ut hur stor delay det ska vara, hur mkt tid det är kvar till nästa tick
		//fördröjer hela programmet
		int delay = nextTick - SDL_GetTicks(); //SDL_GetTicks() är sen start av programmet - nextTick är: SDL_GetTicks + tickInterval(som vi har bestämt)
		if (delay > 0)
			SDL_Delay(delay);

		

		counter++;	
	
	} // yttre while
}

int GameEngine::getCounter(){
	return counter;
}

//Loopen där hela allt körs
void GameEngine::game_loop(std::string before_game_text, std::string after_game_text){ 
	
	if (wait_for_click_window(before_game_text)){
			run();
			wait_for_click_window(after_game_text);	
	}
}
