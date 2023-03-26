#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QWidget>
#include <QDebug>
#include <QApplication>
#include <QSqlQuery>
#include "ellipse.h"

class database
{

public:
    database(QString database_name);
    QSqlDatabase db;
    QSqlQuery *query;

    QList<Ellipse> get_range_list(int type_index, qreal q, qreal v);




signals:

};

#endif // DATABASE_H
