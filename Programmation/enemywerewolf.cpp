#include "enemywerewolf.h"

EnemyWerewolf::EnemyWerewolf()
{

}

EnemyWerewolf::EnemyWerewolf(QString type){
    this->setType(type);
}

QString EnemyWerewolf::getType(){
    return "Werewolf";
}
