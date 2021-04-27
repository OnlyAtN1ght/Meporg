#include "enemydemon.h"

EnemyDemon::EnemyDemon(){
}

EnemyDemon::EnemyDemon(int level){

}

EnemyDemon::EnemyDemon(QString type){
    this->setType(type);
}

QString EnemyDemon::getType(){
    return "Demon";
}


