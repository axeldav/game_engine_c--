#include "EnemyBear.h"
#include "System.h"


EnemyBear* EnemyBear::getInstance(std::string img, int i, int s)
{
	int x = 10 + rand() % (sys.get_win_width() - 20);
	return new EnemyBear(x, img, i, s);
}

EnemyBear::EnemyBear(int x, std::string img, int i, int s):
    Enemy(x, img, i, s) {}

EnemyBear* EnemyBear::clone(){
    return getInstance(this->getImg(), this->getIntervall(), this->getSpeed());
}
