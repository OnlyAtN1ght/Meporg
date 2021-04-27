#include "job.h"


Job::Job(){}

Job::Job(std::string name_job){
    qDebug() << qApp->applicationDirPath();
    QString path = qApp->applicationDirPath() + "/ressources/data.json";

    QByteArray data;

    QFile inFile(path);
    if (!inFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug() << "Error reading the file";
    } else {
        qDebug() << "Fichier bien ouvert";
        data = inFile.readAll();
        qDebug() << data;
        inFile.close();
    }

    QJsonParseError errorPtr;
        QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
        if (doc.isNull()) {
            qDebug() << "Parse failed";
        } else {
            qDebug() << "Parse not failed";
        }


    if (name_job == "Teacher"){
        this->bonus_attack_point = doc["job"]["Teacher"]["bonus_attack_point"].toInt();
        this->bonus_brain_point = doc["job"]["Teacher"]["bonus_brain_point"].toInt();
        this->bonus_strength_point = doc["job"]["Teacher"]["bonus_strength_point"].toInt();
        this->bonus_life_point = doc["job"]["Teacher"]["bonus_life_point"].toInt();

    } else if (name_job == "Worker"){
        this->bonus_attack_point = doc["job"]["Worker"]["bonus_attack_point"].toInt();
        this->bonus_brain_point = doc["job"]["Worker"]["bonus_brain_point"].toInt();
        this->bonus_strength_point = doc["job"]["Worker"]["bonus_strength_point"].toInt();
        this->bonus_life_point = doc["job"]["Worker"]["bonus_life_point"].toInt();

    } else if (name_job == "Healer"){
        this->bonus_attack_point = doc["job"]["Healer"]["bonus_attack_point"].toInt();
        this->bonus_brain_point = doc["job"]["Healer"]["bonus_brain_point"].toInt();
        this->bonus_strength_point = doc["job"]["Healer"]["bonus_strength_point"].toInt();
        this->bonus_life_point = doc["job"]["Healer"]["bonus_life_point"].toInt();
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
