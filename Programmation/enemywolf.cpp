#include "enemywolf.h"

EnemyWolf::EnemyWolf()
{

}

EnemyWolf::EnemyWolf(QString type){
    this->setType(type);
}

QString EnemyWolf::getType(){
    return "Wolf";
}
