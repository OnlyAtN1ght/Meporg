#include "herodemon.h"

HeroDemon::HeroDemon(std::string name,int life,int attack,int strength, int brain){
    qDebug() << "[CPP] : Creating HeroDemon()";
    this->setName(name);
    this->setLifePoint(life);
    this->setAttackPoint(attack);
    this->setStrengthPoint(strength);
    this->setBrainPoint(brain);

    // Set AI
    this->setAi(false);


    // Set the type
    this->setType(QString("Demon"));

}



HeroDemon::HeroDemon(std::string name){
    qDebug() << "[CPP] : Creating HeroDemon()";

    // Setup attack,life,brain,strength
    QJsonDocument doc = Reader::readDataJson();

    this->setAttackPoint(doc["typeHero"]["Demon"]["attack_point"].toInt());
    this->setLifePoint(doc["typeHero"]["Demon"]["life_point"].toInt());
    this->setBrainPoint(doc["typeHero"]["Demon"]["brain_point"].toInt());
    this->setStrengthPoint(doc["typeHero"]["Demon"]["strength_point"].toInt());


    // Setup the name
    this->setName(name);

    // Setup the AI
    this->setAi(false);

    // Setup the type
    this->setType(QString("Demon"));
}

