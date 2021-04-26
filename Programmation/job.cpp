#include "job.h"


Job::Job(){}

Job::Job(std::string name_job){
    qDebug() << "JOB CREATEAUDIJOADKZ";
    if (name_job == "Teacher"){
        this->bonus_attack_point = 5;
        this->bonus_brain_point = 10;
        this->bonus_strength_point = 2;
        this->bonus_life_point = 5;

    } else if (name_job == "Worker"){
        this->bonus_attack_point = 5;
        this->bonus_brain_point = 2;
        this->bonus_strength_point = 2;
        this->bonus_life_point = 5;

    } else if (name_job == "Healer"){
        this->bonus_attack_point = 5;
        this->bonus_brain_point = 20;
        this->bonus_strength_point = 2;
        this->bonus_life_point = 5;
    } else {

    }

};


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
