#include "herohuman.h"

HeroHuman::HeroHuman(std::string name,int life,int attack,int strength, int brain){
    this->setName(name);
    this->setLifePoint(life);
    this->setAttackPoint(attack);
    this->setStrengthPoint(strength);
    this->setBrainPoint(brain);

    // Set AI
    this->setAi(false);
}


HeroHuman::HeroHuman(std::string name){
    qDebug() << "[CPP] : Creating HeroHuman()";

    // Setup attack,life,brain,strength
    QJsonDocument doc = Reader::readDataJson();

    this->setAttackPoint(doc["typeHero"]["Human"]["attack_point"].toInt());
    this->setLifePoint(doc["typeHero"]["Human"]["life_point"].toInt());
    this->setBrainPoint(doc["typeHero"]["Human"]["brain_point"].toInt());
    this->setStrengthPoint(doc["typeHero"]["Human"]["strength_point"].toInt());


    // Setup the name
    this->setName(name);

    // Setup the AI
    this->setAi(false);

    // Setup the type
    this->setType(QString("Human"));
}
