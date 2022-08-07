#ifndef ENEMYBEAR_H
#define ENEMYBEAR_H

#include "Enemy.h"

class EnemyBear : public Enemy {
    public:
        static EnemyBear* getInstance(std::string img_path, int intervall, int speed);
        ~EnemyBear(){}
        virtual EnemyBear* clone(); 
    protected:
        EnemyBear(int x, std::string img_path, int intervall, int speed);

};

#endif