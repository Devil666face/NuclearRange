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
    qreal get_D_rad(int zone_index, int t_start, int t_work);

private:
    int case_t_start(int t_start);
    int case_t_work(int t_work);
    int case_value(int value, QList<int> list_treshold);


signals:

};

#endif // DATABASE_H
