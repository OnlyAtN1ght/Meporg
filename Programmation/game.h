#ifndef GAME_H
#define GAME_H

#include <string>
#include <list>
#include <vector>
#include <qDebug>

#include "entity.h"


#include "herodemon.h"
#include "herohuman.h"
#include "herowolf.h"
#include "herowerewolf.h"

#include "enemydemon.h"
#include "enemyhuman.h"
#include "enemywolf.h"
#include "enemywerewolf.h"

class Game
{
public:
    Game();
    static Entity* createHero(std::string name,std::string class_type,std::string job);
    static std::vector<Entity*> createEnemies(int number_enemies);

    static QJsonDocument readDataJson();

};

#endif // GAME_H
