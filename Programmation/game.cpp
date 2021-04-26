#include "game.h"

Game::Game(){
}

Entity* Game::createHero(std::string name,std::string class_type,std::string job){
    // Le hero qui sera renvoyé
    Entity* h;

    // On crée la classe Hero avec la bonne classe
    if (class_type == "Demon"){
        h = new HeroDemon(name,10,10,10,10);
    } else if (class_type == "Human"){
        h = new HeroHuman(name,10,10,10,10);
    } else if (class_type == "Wolf"){
        h = new HeroWolf(name,10,10,10,10);
    } else if (class_type == "Werewolf"){
        h = new HeroWerewolf(name,10,10,10,10);
    } else {
        qDebug() << "Error  : mauvaise entrée dans la fonction Game.createHero";
        h = NULL;
    }

    // We setup the job
    Job* hero_job;
    if (job == "Teacher"){
        hero_job = new Job("Teacher");

    } else if (job == "Worker"){
        hero_job = new Job();

    } else if (job == "Healer"){
        hero_job = new Job();

    } else {
        hero_job = NULL;
        qDebug() << "Error dans l'argument de Game.createHero()";
    }

    h->setJob(*hero_job);

    return h;

};

std::list<Entity*> Game::createEnemies(int number_enemies){
    std::list<Entity*> enemies;
    Entity* enemy;

    for (int i = 0; i < number_enemies; i++){
        int class_enemy = std::rand() % 4;
        if (class_enemy == 1){
            Entity* enemy = new EnemyDemon();

        } else if (class_enemy == 2) {
            Entity* enemy = new EnemyHuman();

        } else if (class_enemy == 3) {
            Entity* enemy = new EnemyWolf();

        } else if (class_enemy == 4) {
            Entity* enemy = new EnemyWerewolf();

        }

        enemies.push_back(enemy);
    }

    return enemies;

};


