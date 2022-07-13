#ifndef ENEMYGENERATOR_H
#define ENEMYGENERATOR_H

#include "GameEngine.h"

class EnemyGenerator {
public:
    void addEnemyToGame();
    void addEnemyTypeToList(std::string img, int intervall, double speed);
private:
    std::vector<std::string> images;
    std::vector<int> intervalls;
    std::vector<double> speeds;
};

#endif