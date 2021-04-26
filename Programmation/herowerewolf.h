#ifndef HEROWEREWOLF_H
#define HEROWEREWOLF_H

#include "werewolf.h"

class HeroWerewolf:public Werewolf{
public:
    HeroWerewolf(std::string name,int life,int attack,int strength, int brain);
};

#endif // HEROWEREWOLF_H
