#include "herowerewolf.h"


HeroWerewolf::HeroWerewolf(std::string name,int life,int attack,int strength, int brain){
    this->setName(name);
    this->setLifePoint(life);
    this->setAttackPoint(attack);
    this->setStrengthPoint(strength);
    this->setBrainPoint(brain);

    // Set AI
    this->setAi(false);
}
