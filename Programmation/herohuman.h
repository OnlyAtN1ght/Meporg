#ifndef HEROHUMAN_H
#define HEROHUMAN_H

#include "human.h"

class HeroHuman:public Human{
public:
    HeroHuman(std::string name,int life,int attack,int strength, int brain);
    HeroHuman(std::string name);
};

#endif // HEROHUMAN_H
