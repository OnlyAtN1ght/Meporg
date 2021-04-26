#include "entity.h"

Entity::Entity(std::string name,int life,int attack,int strength, int brain){
    this->name = name;
    this->life_point = life;
    this->attack_point = attack;
    this->strength_point = strength;
    this->brain_point = brain;
};

Entity::Entity(){

};


void Entity::attack1(Entity entity_attacked){
    int total_dommages = this->getAttackPoint();

    // We use the strength to increase the damages
    total_dommages *= this->getStrengthPoint();


    int entity_attacked_life = entity_attacked.getLifePoint();
    entity_attacked.setLifePoint(entity_attacked_life - total_dommages);

};
void Entity::attack2(Entity entity_attacked){
    // We need to keep track of items and job
    int total_dommages = 0;
    total_dommages += this->attack_point;


    // We get the damages from items
    std::list<Item>::iterator it = this->backpack.begin();
    for (int i = 0;i < this->backpack.size();i++){
        // it points the i-th element of this->backpack
        total_dommages += it->getAttackPoint();

        // We go to the next item
        std::advance(it, 1);
    }

    // We get the damages from the job
    total_dommages += this->job.getBonusAttackPoint();


    int entity_attacked_life = entity_attacked.getLifePoint();
    entity_attacked.setLifePoint(entity_attacked_life - total_dommages);
};

//Getters/Setters
std::string Entity::getName(){
    return this->name;
};

void Entity::setName(std::string new_name){
    this->name = new_name;
};

bool Entity::getAi(){
    return this->ai;
};

bool Entity::getSex(){
    return this->sex;
};

int Entity::getAttackPoint(){
    // We need to keep track of items and job
    int total_attack = 0;
    total_attack += this->attack_point;


    // We get the damages from items
    std::list<Item>::iterator it = this->backpack.begin();
    int size = this->backpack.size();
    for (int i = 0;i < size;i++){
        // it points the i-th element of this->backpack
        total_attack += it->getAttackPoint();

        // We go to the next item
        std::advance(it, 1);
    }

    // We get the damages from the job
    total_attack += this->job.getBonusAttackPoint();

    return total_attack;
};

void Entity::setAttackPoint(int new_attack_point){
    this->attack_point = new_attack_point;
};

int Entity::getLifePoint(){
    int life;
    life += this->life_point;

    // We get the life from items
    std::list<Item>::iterator it = this->backpack.begin();
    for (int i = 0;i < this->backpack.size();i++){
        // it points the i-th element of this->backpack
        life += it->getLifePoint();

        // We go to the next item
        std::advance(it, 1);
    }

    life += this->job.getBonusLifePoint();

    return life;
};

void Entity::setLifePoint(int new_life_point){
    this->life_point = new_life_point;
};

int Entity::getBrainPoint(){
    return this->brain_point;
};

void Entity::setBrainPoint(int new_brain_point){
    this->brain_point = new_brain_point;
};

int Entity::getStrengthPoint(){
    return this->strength_point;
};

void Entity::setStrengthPoint(int new_strength_point){
    this->strength_point = new_strength_point;
};

std::list<Item> Entity::getItems(){
    return this->backpack;
};

void Entity::addItem(Item new_item){
    this->backpack.push_back(new_item);
};

//void addItems(std::list<Item> new_items){

//};

Job Entity::getJob(){
    return this->job;
}

void Entity::setJob(Job job){
    this->job = job;
}

bool Entity::isDead(){
    return this->life_point <= 0;
}
