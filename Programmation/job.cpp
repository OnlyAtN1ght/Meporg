#include "job.h"

#include "job.h"

Job::Job(){

}


int Job::getBonusBrainPoint(){
    return this->bonus_brain_point;
};

void Job::setBonusBrainPoint(int new_bonus_brain_point){
    this->bonus_brain_point = new_bonus_brain_point;
};

int Job::getBonusStrengthPoint(){
    return this->bonus_strength_point;
};

void Job::setBonusStrengthPoint(int new_bonus_strength_point){
    this->bonus_strength_point = new_bonus_strength_point;
};

int Job::getBonusLifePoint(){
    return this->bonus_life_point;
};

void Job::setBonusLifePoint(int new_bonus_life_point){
    this->bonus_life_point = new_bonus_life_point;
};

int Job::getBonusAttackPoint(){
    return this->bonus_attack_point;
};

void Job::setBonusAttackPoint(int new_bonus_attack_point){
    this->bonus_attack_point = new_bonus_attack_point;
};
