#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
public:
    Item();

    std::string getName();

    int getAttackPoint();
    void setAttackPoint(int new_attack_point);

    int getBrainPoint();
    void setBrainPoint(int new_brain_point);

    int getStrengthPoint();
    void setStrengthPoint(int new_strength_point);

    int getLifePoint();
    void setLifePoint(int new_life_point);

private:
    std::string name;
    int attack_point;
    int brain_point;
    int strength_point;
    int life_point;
};

#endif // ITEM_H
