#include "mainwindow.h"
#include "game.h"
#include <QDebug>
#include <QThread>
#include <cstdlib>

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

    Entity *hero;
    std::list<Entity*> ennemies;
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

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/demon.png"));
        qDebug() << "Loading demon picture into hero";

    }
    else if (bb != nullptr){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/human.png"));
        qDebug() << "Loading human picture into hero";

    }
    else if (cc != nullptr){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/wolf.png"));
        qDebug() << "Loading wolf picture into hero";

    }
    else if (dd != nullptr){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/werewolf.png"));
        qDebug() << "Loading werewolf picture into hero";

    }

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
