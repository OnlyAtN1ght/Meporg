#include "mainwindow.h"
#include "game.h"
#include <QDebug>
#include <QThread>
#include <cstdlib>

Entity *hero;
std::vector<Entity*> ennemies;
Entity *actual_ennemy;
int actual_ennemy_position = -1;

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

    setupUi_Loading(this);
    setFixedSize(1024, 768);
    setWindowTitle("MePorg - Loading...");

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

    Enemy_life->setText(QString::number(actual_ennemy->getLifePoint()));
    Hero_life->setText(QString::number(hero->getLifePoint()));

    connect(Attack1, &QPushButton::clicked, this, &MainWindow::attack1);
    connect(Attack2, &QPushButton::clicked, this, &MainWindow::attack2);
    connect(Attack3, &QPushButton::clicked, this, &MainWindow::attack3);
    connect(Attack4, &QPushButton::clicked, this, &MainWindow::attack4);

}

void MainWindow::get_next_ennemy(){

    qDebug() << "Getting next ennemy";
    actual_ennemy_position += 1;
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

    Information->setText("A " + QString::fromStdString(actual_ennemy->getName()) + " has spawn ! What do you want to do ?");

}

void MainWindow::attack1(){

    setupUi_Win(this);
    /*
    qDebug() << "Attack 1 pressed";
    Information->append("You choose " + Attack1->text());
    qDebug() << "Ennemy life points before attack : " << actual_ennemy->getLifePoint();
    hero->attack1(*actual_ennemy);

    qDebug() << "Ennemy life points after attack: " << actual_ennemy->getLifePoint();
    Enemy_life->setText(QString::number(actual_ennemy->getLifePoint()));

    if (actual_ennemy->isDead()){

        qDebug() << "Ennemy is dead";
        Information->append(QString::fromStdString(actual_ennemy->getName()) + " has defited !");
        try{

            get_next_ennemy();

        }
        catch(double e){

            setupUi_Win(this) ;
            setFixedSize(1024, 768);
            setWindowTitle("MePorg");

        }


    }
    else{

        Information->append(QString::fromStdString(actual_ennemy->getName()) + " used " + actual_ennemy->enemyAttack(*hero));
        Hero_life->setText(QString::number(hero->getLifePoint()));

        if (hero->isDead()){

            setupUi_Defeat(this) ;
            setFixedSize(1024, 768);
            setWindowTitle("MePorg");

        }

    }

*/
}

void MainWindow::attack2(){

    qDebug() << "Attack 2 pressed";
    Information->append("You choose " + Attack2->text());

}

void MainWindow::attack3(){

    qDebug() << "Attack 3 pressed";
    Information->append("You choose " + Attack3->text());

}

void MainWindow::attack4(){


    qDebug() << "Attack 4 pressed";
    Information->append("You choose " + Attack4->text());

}

void MainWindow::about_authors(){

    AboutWindow *w = new AboutWindow(this);
    w->show();

}

void MainWindow::version(){

    QMessageBox msg;
    msg.setWindowTitle("Version");
    msg.setText("a0.1");
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

    QString text = QInputDialog::getText(this,"Type your name","Name ?");
    if(text == ""){

        QMessageBox::warning(this, "Error", "You have to take a name");
        reset();

    }
    return text;

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
