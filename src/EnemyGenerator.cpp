
#include "EnemyGenerator.h"
#include "Enemy.h"

void EnemyGenerator::addEnemyToGame(){

    for (int i = 0; i < intervalls.size(); i++ )
	{ 
		
		if ((gameEngine.getCounter() % intervalls.at(i)) == 0)
		{
			gameEngine.add(Enemy::getInstance(images.at(i), intervalls.at(i), speeds.at(i)));
		}		
	}

}

void EnemyGenerator::addEnemyTypeToList(std::string img, int intervall, double speed){
	images.push_back(img);
	intervalls.push_back(intervall);
	speeds.push_back(speed);
}
