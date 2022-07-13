#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Component.h"
#include "Label.h"
#include <vector>
#include "System.h"
#include "Pistol.h"


class GameEngine
{
public:
	void add(Component* comp);
	void remove(Component* comp);
	bool wait_for_click_window(std::string start_message);
	void run();
	void game_loop(std::string before_game_text, std::string after_game_text);
	void quit_run_loop();
	int get_comps_size();
	Component* get_comp_at_index(int i);
	int getCounter();
private:
	int counter = 1;
	std::vector<Component*> comps;
	std::vector<Component*> added, removed;
	std::vector<Component*> enemyList; 
	bool quit_run;
};

extern GameEngine gameEngine;


# endif