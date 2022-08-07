
#include "EnemyGenerator.h"
#include "Enemy.h"
#include <stdio.h>

/*
void EnemyGenerator::addEnemyToGame(){
	
	//printf("%d", gameEngine.getCounter());
	//printf("\n");

    for (int i = 0; i < intervalls.size(); i++ )
	{ 	
		if ((gameEngine.getCounter() % intervalls.at(i)) == 0)
		{
			//printf("creating new enemy: ");
			//printf("%s", images.at(i).c_str());
			//printf("\n");
			
			gameEngine.add(EnemyBear::getInstance(images.at(i), intervalls.at(i), speeds.at(i)));
		}		
	}

}
*/

void EnemyGenerator::addEnemyTypeToList(std::string img, int intervall, double speed){
	images.push_back(img);
	intervalls.push_back(intervall);
	speeds.push_back(speed);
}

void EnemyGenerator::addEnemy(Enemy* e){
	enemies.push_back(e);
}

void EnemyGenerator::addEnemyToGame(){
	for (Enemy* e : enemies){
		if ((gameEngine.getCounter() % e->getIntervall()) == 0){
			gameEngine.add(e->clone());
		}
	}
}