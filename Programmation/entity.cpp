#include "entity.h"

Entity::Entity(std::string name,int life,int attack,int strength, int brain){
    this->name = name;
    this->life_point = life;
    this->attack_point = attack;
    this->strength_point = strength;
    this->brain_point = brain;
};

Entity::Entity(){};

void Entity::attack1(Entity entity_attacked){
    qDebug() << "Début attack 1";

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
    std::vector<Item>::iterator it = this->backpack.begin();
    int size  = this->backpack.size();
    for (int i = 0;i < size;i++){
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

void Entity::attack3(Entity entity_attacked){
    // We need to keep track of items and job
    int total_dommages = 0;
    total_dommages += this->attack_point;


    // We get the damages from items
    std::vector<Item>::iterator it = this->backpack.begin();
    int size  = this->backpack.size();
    for (int i = 0;i < size;i++){
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

void Entity::attack4(Entity entity_attacked){
    // We need to keep track of items and job
    int total_dommages = 0;
    total_dommages += this->attack_point;


    // We get the damages from items
    std::vector<Item>::iterator it = this->backpack.begin();
    int size = this->backpack.size();
    for (int i = 0;i < size;i++){
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
    std::vector<Item>::iterator it = this->backpack.begin();
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
    int life = 0;
    life += this->life_point;

    // We get the life from items
    std::vector<Item>::iterator it = this->backpack.begin();
    int size = this->backpack.size();
    for (int i = 0;i < size;i++){
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
    // We need to keep track of items and job
    int total_brain = 0;
    total_brain += this->brain_point;


    // We get the brain_points from items
    std::vector<Item>::iterator it = this->backpack.begin();
    int size = this->backpack.size();
    for (int i = 0;i < size;i++){
        // it points the i-th element of this->backpack
        total_brain += it->getBrainPoint();

        // We go to the next item
        std::advance(it, 1);
    }

    // We get the damages from the job
    total_brain += this->job.getBonusBrainPoint();

    return total_brain;
};

void Entity::setBrainPoint(int new_brain_point){
    this->brain_point = new_brain_point;
};

int Entity::getStrengthPoint(){
    // We need to keep track of items and job
    int total_brain = 0;
    total_brain += this->strength_point;


    // We get the strength points from items
    std::vector<Item>::iterator it = this->backpack.begin();
    int size = this->backpack.size();
    for (int i = 0;i < size;i++){
        // it points the i-th element of this->backpack
        total_brain += it->getStrengthPoint();

        // We go to the next item
        std::advance(it, 1);
    }

    // We get the damages from the job
    total_brain += this->job.getBonusStrengthPoint();

    return total_brain;
};

void Entity::setStrengthPoint(int new_strength_point){
    this->strength_point = new_strength_point;
};

std::vector<Item> Entity::getItems(){
    return this->backpack;
};

void Entity::addItem(Item new_item){
    this->backpack.push_back(new_item);
};

void Entity::addItems(std::vector<Item> new_items){
    this->backpack.insert(this->backpack.end(), new_items.begin(), new_items.end());
};

Job Entity::getJob(){
    return this->job;
}

void Entity::setJob(Job job){
    this->job = job;
}

bool Entity::isDead(){
    return this->getLifePoint() <= 0;
}

void Entity::setType(QString type){
    this->type = type;
}

QString Entity::getType(){
    return this->type;
}


QString Entity::getNameAttack1(){
   return this->name_attack_1;
};

QString Entity::getNameAttack2(){
   return this->name_attack_2;
};

QString Entity::getNameAttack3(){
   return this->name_attack_3;
};

QString Entity::getNameAttack4(){
   return this->name_attack_4;
};


QString Entity::enemyAttack(Entity enemy_attacked){
    int attack = std::rand() % 4;

    if (attack == 1){
        this->attack1(enemy_attacked);
        return this->getNameAttack1();

    } else if (attack == 2){
        this->attack2(enemy_attacked);
        return this->getNameAttack2();

    } else if (attack == 3){
        this->attack3(enemy_attacked);
        return this->getNameAttack3();

    } else if (attack == 4){
        this->attack4(enemy_attacked);
        return this->getNameAttack4();

    } else {

    }
};

