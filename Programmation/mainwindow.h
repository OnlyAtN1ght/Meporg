#ifndef MAINWINDOWVYWGET_H
#define MAINWINDOWVYWGET_H

#include <QtCore/QVariant>
#include <QAction>
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "aboutwindow.h"
#include <QMessageBox>
#include <QProcess>
#include <QFontDatabase>
#include <QInputDialog>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
} // namespace Ui

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
public:
    QAction *actionReset;
    QAction *actionExit;
    QAction *actionAuthors;
    QAction *actionVersion;
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *WelcomeLabel;
    QLabel *label;
    QLabel *human;
    QLabel *wolf;
    QLabel *werewolf;
    QLabel *demon;
    QWidget *horizontalLayoutButtonWidget;
    QWidget *horizontalLayoutPictureWidget;
    QHBoxLayout *horizontalLayoutPicture;
    QHBoxLayout *horizontalLayoutButton;
    QPushButton *button_human;
    QPushButton *button_werewolf;
    QPushButton *button_wolf;
    QPushButton *button_demon;
    QMenuBar *menubar;
    QMenu *menu_principal;
    QMenu *menu_about;

    QPushButton *Attack1;
    QPushButton *Attack2;
    QPushButton *Attack3;
    QPushButton *Attack4;
    QTextBrowser *Information;
    QLabel *Enemy;
    QLabel *Hero;
    QLabel *Enemy_life;
    QLabel *Hero_life;

    QMediaPlayer *musique = new QMediaPlayer;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupUi_accueil(QMainWindow *MainWindow)
    {

        int id = QFontDatabase::addApplicationFont(QApplication::applicationDirPath() + "/ressources/font.ttf");
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont font1(family);
        QFont font2(family);

        musique->setMedia(QUrl("file:///" + QApplication::applicationDirPath() + "/ressources/accueil/start_sound.wav"));
        musique->setVolume(10);
        musique->play();


        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName("actionReset");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAuthors = new QAction(MainWindow);
        actionAuthors->setObjectName("actionAuthors");
        actionVersion = new QAction(MainWindow);
        actionVersion->setObjectName("actionVersion");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 1024, 768));
        label_2->setMouseTracking(false);
        label_2->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/accueil/main_background.png"));
        WelcomeLabel = new QLabel(centralwidget);
        WelcomeLabel->setObjectName("WelcomeLabel");
        WelcomeLabel->setGeometry(QRect(30, 10, 821, 201));
        font1.setPointSize(72);
        WelcomeLabel->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 350, 691, 91));
        font2.setPointSize(38);
        label->setFont(font2);


        horizontalLayoutButtonWidget = new QWidget(centralwidget);
        horizontalLayoutButtonWidget->setObjectName("horizontalLayoutButtonWidget");
        horizontalLayoutButtonWidget->setGeometry(QRect(0, 620, 1031, 80));
        horizontalLayoutButton = new QHBoxLayout(horizontalLayoutButtonWidget);
        horizontalLayoutButton->setSpacing(100);
        horizontalLayoutButton->setObjectName("horizontalLayoutButton");
        horizontalLayoutButton->setContentsMargins(20, 0, 20, 0);

        horizontalLayoutPictureWidget = new QWidget(centralwidget);
        horizontalLayoutPictureWidget->setObjectName("horizontalLayoutPictureWidget");
        horizontalLayoutPictureWidget->setGeometry(QRect(40, 520, 1031, 110));
        horizontalLayoutPicture = new QHBoxLayout(horizontalLayoutPictureWidget);
        horizontalLayoutPicture->setSpacing(100);
        horizontalLayoutPicture->setObjectName("horizontalLayourPicture");
        horizontalLayoutPicture->setContentsMargins(20, 0, 20, 0);

        human = new QLabel(centralwidget);
        human->setObjectName("human_picture");
        human->setGeometry(QRect(0, 0, 100, 101));
        human->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/accueil/human.png"));
        horizontalLayoutPicture->addWidget(human);

        werewolf = new QLabel(centralwidget);
        werewolf->setObjectName("werewolf_picture");
        werewolf->setGeometry(QRect(0, 0, 100, 163));
        werewolf->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/accueil/werewolf.png"));
        horizontalLayoutPicture->addWidget(werewolf);

        wolf = new QLabel(centralwidget);
        wolf->setObjectName("wolf_picture");
        wolf->setGeometry(QRect(0, 0, 98, 81));
        wolf->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/accueil/wolf.png"));
        horizontalLayoutPicture->addWidget(wolf);

        demon = new QLabel(centralwidget);
        demon->setObjectName("demon_picture");
        demon->setGeometry(QRect(0, 0, 100, 117));
        demon->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/accueil/demon.png"));
        horizontalLayoutPicture->addWidget(demon);

        button_human = new QPushButton(horizontalLayoutButtonWidget);
        button_human->setObjectName("button_human");
        QFont font3;
        font3.setFamily("Sitka Display");
        font3.setPointSize(16);
        button_human->setFont(font3);

        horizontalLayoutButton->addWidget(button_human);

        button_werewolf = new QPushButton(horizontalLayoutButtonWidget);
        button_werewolf->setObjectName("button_werewolf");
        button_werewolf->setFont(font3);

        horizontalLayoutButton->addWidget(button_werewolf);

        button_wolf = new QPushButton(horizontalLayoutButtonWidget);
        button_wolf->setObjectName("button_wolf");
        button_wolf->setFont(font3);

        horizontalLayoutButton->addWidget(button_wolf);

        button_demon = new QPushButton(horizontalLayoutButtonWidget);
        button_demon->setObjectName("button_demon");
        button_demon->setEnabled(true);
        button_demon->setFont(font3);

        connect(button_demon, &QPushButton::clicked, this, &MainWindow::demon_function);
        connect(button_human, &QPushButton::clicked, this, &MainWindow::human_function);
        connect(button_werewolf, &QPushButton::clicked, this, &MainWindow::werewolf_function);
        connect(button_wolf, &QPushButton::clicked, this, &MainWindow::wolf_function);
        connect(actionAuthors, &QAction::triggered, this, &MainWindow::about_authors);
        connect(actionVersion, &QAction::triggered, this, &MainWindow::version);
        connect(actionExit, &QAction::triggered, this, &MainWindow::exit);
        connect(actionReset, &QAction::triggered, this, &MainWindow::reset);

        horizontalLayoutButton->addWidget(button_demon);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1085, 22));
        menu_principal = new QMenu(menubar);
        menu_principal->setObjectName("menu_principal");
        menu_about = new QMenu(menubar);
        menu_about->setObjectName("menu_about");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu_principal->menuAction());
        menubar->addAction(menu_about->menuAction());
        menu_principal->addAction(actionReset);
        menu_principal->addAction(actionExit);
        menu_about->addAction(actionAuthors);
        menu_about->addAction(actionVersion);

        retranslateUi_accueil(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi for Accueil

    void retranslateUi_accueil(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAuthors->setText(QCoreApplication::translate("MainWindow", "Authors", nullptr));
        actionVersion->setText(QCoreApplication::translate("MainWindow", "Version", nullptr));
        label_2->setText(QString());
        WelcomeLabel->setText(QCoreApplication::translate("MainWindow", "Welcome to Meporg", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Please, select your hero", nullptr));
        button_human->setText(QCoreApplication::translate("MainWindow", "Human", nullptr));
        button_werewolf->setText(QCoreApplication::translate("MainWindow", "Werewolf", nullptr));
        button_wolf->setText(QCoreApplication::translate("MainWindow", "Wolf", nullptr));
        button_demon->setText(QCoreApplication::translate("MainWindow", "Demon", nullptr));
        menu_principal->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menu_about->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi for Accueil

    void setupUi_Fight(QMainWindow *MainWindow)
       {
           if (MainWindow->objectName().isEmpty())
               MainWindow->setObjectName(QString::fromUtf8("MainWindow"));

           musique->setMedia(QUrl("file:///" + QApplication::applicationDirPath() + "/ressources/fight/main_sound.wav"));
           musique->play();

           centralwidget = new QWidget(MainWindow);
           centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
           Attack1 = new QPushButton(centralwidget);
           Attack1->setObjectName(QString::fromUtf8("Attack1"));
           Attack1->setGeometry(QRect(700, 610, 151, 61));
           QFont font;
           font.setPointSize(16);
           Attack1->setFont(font);
           Attack2 = new QPushButton(centralwidget);
           Attack2->setObjectName(QString::fromUtf8("Attack2"));
           Attack2->setGeometry(QRect(860, 610, 151, 61));
           Attack2->setFont(font);
           Attack3 = new QPushButton(centralwidget);
           Attack3->setObjectName(QString::fromUtf8("Attack3"));
           Attack3->setGeometry(QRect(700, 675, 151, 61));
           Attack3->setFont(font);
           Attack4 = new QPushButton(centralwidget);
           Attack4->setObjectName(QString::fromUtf8("Attack4"));
           Attack4->setGeometry(QRect(860, 675, 151, 61));
           Attack4->setFont(font);
           Information = new QTextBrowser(centralwidget);
           Information->setObjectName(QString::fromUtf8("Information"));
           Information->setGeometry(QRect(10, 615, 631, 122));
           Enemy = new QLabel(centralwidget);
           Enemy->setObjectName(QString::fromUtf8("Enemy"));
           Enemy->setGeometry(QRect(680, 20, 350, 350));
           Hero = new QLabel(centralwidget);
           Hero->setObjectName(QString::fromUtf8("Hero"));
           Hero->setGeometry(QRect(20, 230, 350, 350));
           Enemy_life = new QLabel(centralwidget);
           Enemy_life->setObjectName(QString::fromUtf8("Enemy_life"));
           Enemy_life->setGeometry(QRect(690, 370, 350, 16));
           Hero_life = new QLabel(centralwidget);
           Hero_life->setObjectName(QString::fromUtf8("Hero_life"));
           Hero_life->setGeometry(QRect(20, 580, 350, 16));
           MainWindow->setCentralWidget(centralwidget);

           retranslateUi_Fight(MainWindow);

           QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi for Fight

    void retranslateUi_Fight(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Attack1->setText(QCoreApplication::translate("MainWindow", "Attack 1", nullptr));
        Attack2->setText(QCoreApplication::translate("MainWindow", "Attack 2", nullptr));
        Attack3->setText(QCoreApplication::translate("MainWindow", "Attack 3", nullptr));
        Attack4->setText(QCoreApplication::translate("MainWindow", "Attack 4", nullptr));
        Enemy->setText(QCoreApplication::translate("MainWindow", "Image de l'enemie", nullptr));
        Hero->setText(QCoreApplication::translate("MainWindow", "Image du h\303\251ro", nullptr));
        Enemy_life->setText(QCoreApplication::translate("MainWindow", "Bare de vie", nullptr));
        Hero_life->setText(QCoreApplication::translate("MainWindow", "Bare de bie", nullptr));
    } // retranslateUi for Fight

    void setupUi_Loading(QMainWindow *MainWindow){

        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, MainWindow->width(), MainWindow->height()));
        label->setStyleSheet("QLabel{ background-color : black; color : white; }");
        label->setText(QString("Loading..."));
        MainWindow->setCentralWidget(centralwidget);
        QMetaObject::connectSlotsByName(MainWindow);
    }

    void setupUi_Win(QMainWindow *MainWindow){

        empty_gui();

    }

    void setupUi_Defeat(QMainWindow *MainWindow){



    }

private:

    Ui::MainWindow *ui;
    void demon_function();
    void werewolf_function();
    void human_function();
    void wolf_function();
    void version();
    void about_authors();
    void play(std::string type, std::string name, std::string job);
    void exit();
    void reset();
    QString get_name();
    QString get_job();
    void attack1();
    void attack2();
    void attack3();
    void attack4();
    void get_next_ennemy();
    void empty_gui(){

        delete Attack1;
        delete Attack2;
        delete Attack3;
        delete Attack4;
        delete Information;
        delete Enemy;
        delete Enemy_life;
        delete Hero;
        delete Hero_life;


    }

};

#endif // MAINWINDOWVYWGET_H
