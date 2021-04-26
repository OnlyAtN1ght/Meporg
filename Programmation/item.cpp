#include "item.h"

Item::Item()
{

}


int Item::getAttackPoint(){
    return this->attack_point;
};

void Item::setAttackPoint(int new_attack_point){
    this->attack_point = new_attack_point;
};

int Item::getBrainPoint(){
    return this->brain_point;
};

void Item::setBrainPoint(int new_brain_point){
    this->brain_point = new_brain_point;
};

int Item::getStrengthPoint(){
    return this->strength_point;
};

void Item::setStrengthPoint(int new_strength_point){
   this->strength_point = new_strength_point;
};

int Item::getLifePoint(){
    return this->life_point;
};

void Item::setLifePoint(int new_life_point){
    this->life_point = new_life_point;
};
