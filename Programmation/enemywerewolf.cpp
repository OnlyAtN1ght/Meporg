#include "enemywerewolf.h"

EnemyWerewolf::EnemyWerewolf()
{

}

EnemyWerewolf::EnemyWerewolf(QString type){
    qDebug() << "[CPP] : Generating EnemyWerewolf() with argument" << type;

    this->setType(type);
    // Default value

    // Read file
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

    if (doc["DEFAULT"]["default_life"].toInt() >= 100000){
        this->setLifePoint(10);
    } else {
        this->setLifePoint(doc["DEFAULT"]["default_life"].toInt());
    }

    if (doc["DEFAULT"]["default_attack"].toInt() >= 100000){
        this->setAttackPoint(10);
    } else{
        this->setAttackPoint(doc["DEFAULT"]["default_attack"].toInt());
    }

    if (doc["DEFAULT"]["default_brain"].toInt() >= 10000){
        this->setBrainPoint(10);
    } else {
        this->setBrainPoint(doc["DEFAULT"]["default_brain"].toInt());
    }

    if (doc["DEFAULT"]["default_strength"].toInt() >= 100000){
        this->setStrengthPoint(10);
    } else {
        this->setStrengthPoint(doc["DEFAULT"]["default_strength"].toInt());
    }

    qDebug() << this->getLifePoint();
    qDebug() << this->getAttackPoint();
    qDebug() << this->getBrainPoint();
    qDebug() << this->getStrengthPoint();

    // Set AI
    this->setAi(true);
}


