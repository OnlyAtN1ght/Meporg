#include "aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    setFixedSize(320, 240);
    setWindowTitle("About authors");
}

AboutWindow::~AboutWindow()
{
    delete ui;
}
