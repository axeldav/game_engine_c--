#ifndef ENEMYGENERATOR_H
#define ENEMYGENERATOR_H

#include "GameEngine.h"
class Enemy; 

class EnemyGenerator {
public:
    void addEnemyToGame();
    void addEnemyTypeToList(std::string img, int intervall, double speed);
    void addEnemy(Enemy* e);
private:
    std::vector<Enemy *> enemies;
};

#endif