#include "enemyhuman.h"

EnemyHuman::EnemyHuman(){

}

EnemyHuman::EnemyHuman(QString type){
    this->setType(type);
}

QString EnemyHuman::getType(){
    return "Human";
}
