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

HeroWerewolf::HeroWerewolf(std::string name){
    qDebug() << "[CPP] : Creating HeroWerewolf()";

    // Setup attack,life,brain,strength
    QJsonDocument doc = Reader::readDataJson();

    this->setAttackPoint(doc["typeHero"]["Werewolf"]["attack_point"].toInt());
    this->setLifePoint(doc["typeHero"]["Werewolf"]["life_point"].toInt());
    this->setBrainPoint(doc["typeHero"]["Werewolf"]["brain_point"].toInt());
    this->setStrengthPoint(doc["typeHero"]["Werewolf"]["strength_point"].toInt());


    // Setup the name
    this->setName(name);

    // Setup the AI
    this->setAi(false);

    // Setup the type
    this->setType(QString("Werewolf"));
}
