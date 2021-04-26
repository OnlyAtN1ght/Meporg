#include "mainwindow.h"
#include <QDebug>
#include <QThread>

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
    play("Demon", name, job);

}

void MainWindow::human_function(){

    qDebug() << "Human pressed";
    QString name = get_name();
    qDebug() << "Name : " << name;
    QString job = get_job();
    qDebug() << "Job : " << job;
    play("Human", name, job);

}

void MainWindow::werewolf_function(){

    qDebug() << "Werewolf pressed";
    QString name = get_name();
    qDebug() << "Name : " << name;
    QString job = get_job();
    qDebug() << "Job : " << job;
    play("Werewolf", name, job);
}

void MainWindow::wolf_function(){

    qDebug() << "Wolf pressed";
    QString name = get_name();
    qDebug() << "Name : " << name;
    QString job = get_job();
    qDebug() << "Job : " << job;
    play("Wolf", name, job);
}

void MainWindow::play(QString type, QString name, QString job){

    Game *game = new Game();

    setupUi_Loading(this);
    setFixedSize(1024, 768);
    setWindowTitle("MePorg - Loading...");
    QThread::msleep(1000);

    setupUi_Fight(this) ;
    setFixedSize(1024, 768);
    setWindowTitle("MePorg - Fight !");


    if (type == "Demon"){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/demon.png"));

    }
    else if (type == "Human"){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/human.png"));

    }
    else if (type == "Wolf"){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/wolf.png"));

    }
    else if (type == "Werewolf"){

        Hero->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/werewolf.png"));

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
