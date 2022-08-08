#include "EnemyDog.h"
#include "System.h"


EnemyDog* EnemyDog::getInstance(std::string img, int i, int s)
{
	int x = 10 + rand() % (sys.get_win_width() - 20);
	return new EnemyDog(x, img, i, s);
}

EnemyDog::EnemyDog(int x, std::string img, int i, int s):
    Enemy(x, img, i, s) {}

EnemyDog* EnemyDog::clone(){
    return getInstance(this->getImg(), this->getIntervall(), this->getSpeed());
}
