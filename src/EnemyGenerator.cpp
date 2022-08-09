#include "EnemyGenerator.h"
#include "Enemy.h"
#include <stdio.h>

void EnemyGenerator::addEnemy(Enemy* e)
{
	enemies.push_back(e);
}

void EnemyGenerator::addEnemyToGame()
{
	for (Enemy* e : enemies){
		if ((gameEngine.getCounter() % e->getIntervall()) == 0)
		{
			gameEngine.add(e->clone());
		}
	}
}