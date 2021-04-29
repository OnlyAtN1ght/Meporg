#include "herodemon.h"

HeroDemon::HeroDemon(std::string name,int life,int attack,int strength, int brain){
    qDebug() << "[CPP] : Creating HeroDemon()";
    this->setName(name);
    qDebug() << life;
    this->setLifePoint(life);
    this->setAttackPoint(attack);
    this->setStrengthPoint(strength);
    this->setBrainPoint(brain);

    qDebug() << this->getLifePoint();

    // Set AI
    this->setAi(false);


    // Set the type
    this->setType(QString("Demon"));

}
