#ifndef READER_H
#define READER_H

#include <QJsonDocument>
#include <QFile>
#include <QApplication>

class Reader
{
public:
    Reader();
    static QJsonDocument readDataJson();
};

#endif // READER_H
