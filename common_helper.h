#ifndef COMMON_HELPER_H
#define COMMON_HELPER_H
#include <QVector>
#include <QMap>
#include <windows.h>
#include <QDebug>

QVector<QString> explode(QString separator,QString t);
QMap<QString, QString> TSlistToQmap(QString t);
QString getVersionString(QString fName);

#endif // COMMON_HELPER_H
