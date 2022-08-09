#ifndef ENEMYDOG_H
#define ENEMYDOG_H

#include "Enemy.h"

class EnemyDog : public Enemy 
{
public:
    static EnemyDog* getInstance(std::string img_path, int intervall, int speed);
    ~EnemyDog(){}
    virtual EnemyDog* clone(); 
protected:
    EnemyDog(int x, std::string img_path, int intervall, int speed);
};

#endif