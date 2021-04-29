#include "mainwindow.h"
#include "game.h"
#include <QDebug>
#include <QPropertyAnimation>

Entity *hero;
std::vector<Entity*> ennemies;
Entity *actual_ennemy;
unsigned long long actual_ennemy_position = -1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi_accueil(this);
    setFixedSize(1024, 768);
    setWindowTitle("MePorg");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::demon_function()
{

    qDebug() << "Demon pressed";
    QString name = get_name();
    qDebug() << "Name : " << name;
    QString job = get_job();
    qDebug() << "Job : " << job;
    play("Demon", name.toStdString(), job.toStdString());

}

void MainWindow::human_function(){

    qDebug() << "Human pressed";
    QString name = get_name();
    qDebug() << "Name : " << name;
    QString job = get_job();
    qDebug() << "Job : " << job;
    play("Human", name.toStdString(), job.toStdString());

}

void MainWindow::werewolf_function(){

    qDebug() << "Werewolf pressed";
    QString name = get_name();
    qDebug() << "Name : " << name;
    QString job = get_job();
    qDebug() << "Job : " << job;
    play("Werewolf", name.toStdString(), job.toStdString());
}

void MainWindow::wolf_function(){

    qDebug() << "Wolf pressed";
    QString name = get_name();
    qDebug() << "Name : " << name;
    QString job = get_job();
    qDebug() << "Job : " << job;
    play("Wolf", name.toStdString(), job.toStdString());

}

void MainWindow::play(std::string type, std::string name, std::string job){

    srand((unsigned int)time(0));
    int nb_ennemies = rand() % 30 + 1;

    qDebug() << "Initializing hero";
    hero = Game::createHero(name, type, job);
    qDebug() << "Hero initialized";
    qDebug() << "Initializing enemies";
    ennemies = Game::createEnemies(nb_ennemies);
    qDebug() << "Ennemies initialized";

    setupUi_Fight(this) ;
    setFixedSize(1024, 768);
    setWindowTitle("MePorg - Fight !");

    HeroDemon *aa = dynamic_cast<HeroDemon*>(hero);
    HeroHuman *bb = dynamic_cast<HeroHuman*>(hero);
    HeroWolf *cc = dynamic_cast<HeroWolf*>(hero);
    HeroWerewolf *dd = dynamic_cast<HeroWerewolf*>(hero);

    if (aa != nullptr){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/fight/demon.png"));
        qDebug() << "Loading demon picture into hero";

    }
    else if (bb != nullptr){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/fight/human.png"));
        qDebug() << "Loading human picture into hero";

    }
    else if (cc != nullptr){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/fight/wolf.png"));
        qDebug() << "Loading wolf picture into hero";

    }
    else if (dd != nullptr){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/fight/werewolf.png"));
        qDebug() << "Loading werewolf picture into hero";

    }

    get_next_ennemy();

    Attack1->setText(hero->getNameAttack1());
    Attack2->setText(hero->getNameAttack2());
    Attack3->setText(hero->getNameAttack3());
    Attack4->setText(hero->getNameAttack4());

    connect(Attack1, &QPushButton::clicked, this, &MainWindow::attack1);
    connect(Attack2, &QPushButton::clicked, this, &MainWindow::attack2);
    connect(Attack3, &QPushButton::clicked, this, &MainWindow::attack3);
    connect(Attack4, &QPushButton::clicked, this, &MainWindow::attack4);

    Hero_life->setMaximum(hero->getLifePoint());
    Enemy_life->setMaximum(actual_ennemy->getLifePoint());
    Hero_life->setTextVisible(true);
    Enemy_life->setTextVisible(true);
    Hero_life->setValue(hero->getLifePoint());
    Enemy_life->setValue(actual_ennemy->getLifePoint());


}

void MainWindow::get_next_ennemy(){

    qDebug() << "Getting next ennemy";
    actual_ennemy_position += 1;
    if (actual_ennemy_position >= ennemies.size()){

        throw std::string("Il n'y a plus d'ennemi à combattre");

    }
    actual_ennemy = ennemies.at(actual_ennemy_position);

    qDebug() << "Checking ennemy type";

    if (actual_ennemy->getType() == "Demon"){

        qDebug() << "Loading demon picture into Enemy";
        Enemy->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/fight/demon.png"));

    }
    else if (actual_ennemy->getType() == "Human"){

        qDebug() << "Loading human picture into Enemy";
        Enemy->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/fight/human.png"));

    }
    else if (actual_ennemy->getType() == "Wolf"){

        qDebug() << "Loading wolf picture into Enemy";
        Enemy->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/fight/wolf.png"));

    }
    else if (actual_ennemy->getType() == "Werewolf"){

        qDebug() << "Loading werewolf picture into Enemy";
        Enemy->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/fight/werewolf.png"));

    }

    Information->append("A " + QString::fromStdString(actual_ennemy->getName()) + " has spawn ! What do you want to do ?");
    Enemy_life->setMaximum(actual_ennemy->getLifePoint());
    Enemy_life->setValue(actual_ennemy->getLifePoint());
}

void MainWindow::attack1(){

    attackEnable(false);
    qDebug() << "Attack 1 pressed";
    Information->append("You choose " + Attack1->text());
    qDebug() << "Ennemy life points before attack : " << actual_ennemy->getLifePoint();
    int new_life_point = hero->attack1(*actual_ennemy);
    actual_ennemy->setLifePoint(new_life_point);
    Enemy_life->setValue(actual_ennemy->getLifePoint());
    qDebug() << "Ennemy life points after attack: " << actual_ennemy->getLifePoint();

    if (actual_ennemy->isDead()){

    }
    else{

        Information->append(QString::fromStdString(actual_ennemy->getName()) + " used " + actual_ennemy->enemyAttack(*hero));
        Hero_life->setValue(hero->getLifePoint());
        if (hero->isDead()){

            defeat();

        }

    }

    attackEnable(true);
}

void MainWindow::attack2(){

    attackEnable(false);
    qDebug() << "Attack 2 pressed";
    Information->append("You choose " + Attack2->text());
    qDebug() << "Ennemy life points before attack : " << actual_ennemy->getLifePoint();
    hero->attack2(*actual_ennemy);
    Enemy_life->setValue(actual_ennemy->getLifePoint());
    qDebug() << "Ennemy life points after attack: " << actual_ennemy->getLifePoint();

    if (actual_ennemy->isDead()){

        qDebug() << "Ennemy is dead";
        Information->append(QString::fromStdString(actual_ennemy->getName()) + " has defited !");
        try{

            get_next_ennemy();

        }
        catch(std::string e){

            qDebug() << QString::fromStdString(e);
            victory();

        }


    }
    else{

        Information->append(QString::fromStdString(actual_ennemy->getName()) + " used " + actual_ennemy->enemyAttack(*hero));
        Hero_life->setValue(hero->getLifePoint());
        if (hero->isDead()){

            defeat();

        }

    }
    attackEnable(true);

}

void MainWindow::attack3(){

    attackEnable(false);
    qDebug() << "Attack 3 pressed";
    Information->append("You choose " + Attack3->text());
    qDebug() << "Ennemy life points before attack : " << actual_ennemy->getLifePoint();
    hero->attack3(*actual_ennemy);
    Enemy_life->setValue(actual_ennemy->getLifePoint());
    qDebug() << "Ennemy life points after attack: " << actual_ennemy->getLifePoint();

    if (actual_ennemy->isDead()){

        qDebug() << "Ennemy is dead";
        Information->append(QString::fromStdString(actual_ennemy->getName()) + " has defited !");
        try{

            get_next_ennemy();

        }
        catch(std::string e){

            qDebug() << QString::fromStdString(e);
            victory();

        }


    }
    else{

        Information->append(QString::fromStdString(actual_ennemy->getName()) + " used " + actual_ennemy->enemyAttack(*hero));
        Hero_life->setValue(hero->getLifePoint());
        if (hero->isDead()){

            defeat();

        }

    }
    attackEnable(true);


}

void MainWindow::attack4(){

    attackEnable(false);
    qDebug() << "Attack 4 pressed";
    Information->append("You choose " + Attack4->text());
    qDebug() << "Ennemy life points before attack : " << actual_ennemy->getLifePoint();
    hero->attack4(*actual_ennemy);
    Enemy_life->setValue(actual_ennemy->getLifePoint());
    qDebug() << "Ennemy life points after attack: " << actual_ennemy->getLifePoint();

    if (actual_ennemy->isDead()){

        qDebug() << "Ennemy is dead";
        Information->append(QString::fromStdString(actual_ennemy->getName()) + " has defited !");
        try{

            get_next_ennemy();

        }
        catch(std::string e){

            qDebug() << QString::fromStdString(e);
            victory();

        }


    }
    else{

        Information->append(QString::fromStdString(actual_ennemy->getName()) + " used " + actual_ennemy->enemyAttack(*hero));
        Hero_life->setValue(hero->getLifePoint());
        if (hero->isDead()){

            defeat();

        }

    }
    attackEnable(true);


}

void MainWindow::attackEnable(bool info){

    if (!info){

        Attack1->setEnabled(false);
        Attack2->setEnabled(false);
        Attack3->setEnabled(false);
        Attack4->setEnabled(false);

    }
    else{

        Attack1->setEnabled(true);
        Attack2->setEnabled(true);
        Attack3->setEnabled(true);
        Attack4->setEnabled(true);

    }

}

void MainWindow::enemyDie(){

    qDebug() << "Ennemy is dead";
    Information->append(QString::fromStdString(actual_ennemy->getName()) + " has defited !");
    try{

        get_next_ennemy();

    }
    catch(std::string e){

        qDebug() << QString::fromStdString(e);
        victory();

    }

}

void MainWindow::about_authors(){

    AboutWindow *w = new AboutWindow(this);
    w->show();

}

void MainWindow::version(){

    QMessageBox msg;
    msg.setWindowTitle("Version");
    msg.setText("a1.0");
    msg.setIcon(QMessageBox::Information);
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();

}

void MainWindow::exit(){

    QApplication::quit();

}

void MainWindow::reset(){

    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    delete this;

}

QString MainWindow::get_name(){

    QString text = QInputDialog::getText(this,"Type your name","Name ?                                                  ");
    if(text == ""){

        QMessageBox::warning(this, "Error", "You have to take a name");
        reset();

    }
    return text;

}

void MainWindow::victory(){

    musique->setMedia(QUrl("file:///" + QApplication::applicationDirPath() + "/ressources/victory_sound.wav"));
    musique->play();
    QMessageBox msg;
    msg.setWindowTitle("Victory !");
    msg.setText("You win ! GG WP ! Feel free to try again, it may be harder next time :)");
    msg.setIcon(QMessageBox::Information);
    msg.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    QPushButton *restart = new QPushButton();
    restart->setObjectName("button_restart");
    restart->setText("Restart");
    QPushButton *exit = new QPushButton();
    exit->setObjectName("button_exit");
    exit->setText("Exit");

    connect(exit, &QPushButton::clicked, this, &MainWindow::exit);
    connect(restart, &QPushButton::clicked, this, &MainWindow::reset);

    msg.addButton(exit, QMessageBox::NoRole);
    msg.addButton(restart, QMessageBox::YesRole);
    msg.exec();

}

void MainWindow::defeat(){

    musique->setMedia(QUrl("file:///" + QApplication::applicationDirPath() + "/ressources/death_sound.wav"));
    musique->play();
    QMessageBox msg;
    msg.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    msg.setWindowTitle("Defeat...");
    msg.setText("You loose... Feel free to try again, next time will be yours !");
    msg.setIcon(QMessageBox::Information);

    QPushButton *restart = new QPushButton();
    restart->setObjectName("button_restart");
    restart->setText("Restart");
    QPushButton *exit = new QPushButton();
    exit->setObjectName("button_exit");
    exit->setText("Exit");

    connect(exit, &QPushButton::clicked, this, &MainWindow::exit);
    connect(restart, &QPushButton::clicked, this, &MainWindow::reset);

    msg.addButton(exit, QMessageBox::NoRole);
    msg.addButton(restart, QMessageBox::YesRole);
    msg.exec();

}

QString MainWindow::get_job(){

    QMessageBox job;
    QString string;
    job.setWindowTitle("Job selection");
    job.setText("Select your job");
    QAbstractButton *Worker = job.addButton(tr("Worker"), QMessageBox::YesRole);
    QAbstractButton *Teacher = job.addButton(tr("Teacher"), QMessageBox::YesRole);
    QAbstractButton *Healer = job.addButton(tr("Healer"), QMessageBox::YesRole);
    job.exec();
    if (job.clickedButton() == Worker){

        string = "Worker";

    }
    else if (job.clickedButton() == Teacher){

        string = "Teacher";

    }
    else if (job.clickedButton() == Healer){

        string = "Healer";

    }
    // Pas utile, la fenetre oblige a cliquer sur un bouton
    else{

        string = "";

    }

    if (string == ""){

        QMessageBox::warning(this, "Error", "You have to take a job");
        reset();

    }

    return string;

}
