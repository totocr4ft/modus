#ifndef COMMON_HELPER_H
#define COMMON_HELPER_H
#include <QVector>
#include <QMap>

QVector<QString> explode(QString separator,QString t);
QMap<QString, QString> TSlistToQmap(QString t);

#endif // COMMON_HELPER_H
