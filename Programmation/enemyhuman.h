#ifndef ENEMYHUMAN_H
#define ENEMYHUMAN_H

#include "human.h"

class EnemyHuman:public Human{
public:
    EnemyHuman();
    EnemyHuman(int level);
    QString getType();
};

#endif // ENEMYHUMAN_H
