#ifndef HEROWOLF_H
#define HEROWOLF_H

#include "wolf.h"

class HeroWolf:public Wolf{
public:
    HeroWolf(std::string name,int life,int attack,int strength, int brain);
};

#endif // HEROWOLF_H
