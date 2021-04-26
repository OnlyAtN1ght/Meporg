#ifndef ABOUTWINDOWJIUEYT_H
#define ABOUTWINDOWJIUEYT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QMainWindow>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui {
    class AboutWindow;
} // namespace Ui

QT_END_NAMESPACE

class AboutWindow : public QDialog
{
public:
    QLabel *Lilian;
    QLabel *Simon;
    QLabel *label;
    QLabel *github_lilian;
    QLabel *github_simon;
    QPushButton *pushButton;

    AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(320, 240);
        Lilian = new QLabel(Dialog);
        Lilian->setObjectName("Lilian");
        Lilian->setGeometry(QRect(0, -10, 91, 151));
        Lilian->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/Lilian.jpg"));
        Simon = new QLabel(Dialog);
        Simon->setObjectName("Simon");
        Simon->setGeometry(QRect(0, 160, 91, 81));
        Simon->setPixmap(QPixmap(QApplication::applicationDirPath() + "/ressources/Simon.jpg"));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 10, 141, 81));
        label->setAutoFillBackground(false);
        label->setWordWrap(true);
        github_lilian = new QLabel(Dialog);
        github_lilian->setObjectName("github_lilian");
        github_lilian->setGeometry(QRect(100, 120, 71, 31));
        github_simon = new QLabel(Dialog);
        github_simon->setObjectName("github_simon");
        github_simon->setGeometry(QRect(100, 200, 71, 31));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 210, 75, 24));
        connect(pushButton, &QPushButton::pressed, this, &AboutWindow::close);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        Lilian->setText(QString());
        Simon->setText(QString());
        label->setText(QCoreApplication::translate("Dialog", "Authors are Lilian Cizeron and Simon Provot, two engeneers students in Software Cybersecurity at ENSIBS.", nullptr));
        github_lilian->setText("<a href = \"https://www.github.com/Lilianc2000\">Github</a>");
        github_lilian->setTextFormat(Qt::RichText);
        github_lilian->setTextInteractionFlags(Qt::TextBrowserInteraction);
        github_lilian->setOpenExternalLinks(true);
        github_simon->setText("<a href = \"https://github.com/OnlyAtN1ght\">Github</a>");
        github_simon->setTextFormat(Qt::RichText);
        github_simon->setTextInteractionFlags(Qt::TextBrowserInteraction);
        github_simon->setOpenExternalLinks(true);

        pushButton->setText(QCoreApplication::translate("Dialog", "Ok", nullptr));
    } // retranslateUi


private:
    Ui::AboutWindow *ui;

    void close(){

        this->done(1);

    }

};

#endif // ABOUTWINDOWJIUEYT_H
