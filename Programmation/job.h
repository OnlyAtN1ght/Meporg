#ifndef JOB_H
#define JOB_H


class Job
{
public:
    Job();
    Job(int bonus_brain_point,int bonus_strength_point,int bonus_attack_point,int bonus_life_point);
    int getBonusBrainPoint();
    void setBonusBrainPoint(int new_bonus_brain_point);

    int getBonusStrengthPoint();
    void setBonusStrengthPoint(int new_bonus_strength_point);

    int getBonusLifePoint();
    void setBonusLifePoint(int new_bonus_life_point);

    int getBonusAttackPoint();
    void setBonusAttackPoint(int new_bonus_attack_point);

private:
    int bonus_brain_point;
    int bonus_strength_point;
    int bonus_life_point;
    int bonus_attack_point;
};

#endif // JOB_H
