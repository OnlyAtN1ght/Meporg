#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <list>
#include "item.h"
#include "job.h"

class Entity
{
public:
    Entity(std::string name,int life,int attack,int strength, int brain);
    Entity();
    int attack1(Entity entity_attacked);
    virtual void attack2(Entity entity_attacked);
    virtual void attack3(Entity entity_attacked);
    virtual void attack4(Entity entity_attacked);


    //Getters/Setters
    std::string getName();
    void setName(std::string new_name);

    bool getAi();
    void setAi(bool ai);

    bool getSex();

    int getAttackPoint();
    void setAttackPoint(int new_attack_point);

    int getLifePoint();
    void setLifePoint(int new_life_point);

    int getBrainPoint();
    void setBrainPoint(int new_brain_point);

    int getStrengthPoint();
    void setStrengthPoint(int new_strength_point);

    std::vector<Item> getItems();
    void addItem(Item new_item);
    void addItems(std::vector<Item> new_items);

    Job getJob();
    void setJob(Job job);

    QString getType();
    void setType(QString new_name);

    // Function
    bool isDead();

    QString getNameAttack1();
    QString getNameAttack2();
    QString getNameAttack3();
    QString getNameAttack4();

    QString enemyAttack(Entity enemy_attacked);

private:
    std::string name;
    bool ai;
    int attack_point;
    int life_point;
    int brain_point;
    int strength_point;
    bool sex;
    std::vector<Item> backpack;
    Job job;

    QString name_attack_1;
    QString name_attack_2;
    QString name_attack_3;
    QString name_attack_4;

    QString type;

};

#endif // ENTITY_H
