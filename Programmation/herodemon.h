#ifndef HERODEMON_H
#define HERODEMON_H

#include "demon.h"

class HeroDemon:public Demon{
public:
    HeroDemon(std::string name,int life,int attack,int strength, int brain);
};

#endif // HERODEMON_H
