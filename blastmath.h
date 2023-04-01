#ifndef BLASTMATH_H
#define BLASTMATH_H

#include <QMainWindow>
#include <QDebug>
#include <QDateTime>
#include "ellipse.h"

enum Type {
    Air,
    Ground,
    Overwather,
    Underwather,
    Underground
};



class BlastMath
{
public:
    BlastMath();

    Type type = Ground;
    qreal lon=-1;
    qreal lat=-1;
    qreal q = 0.1;
    qreal vh_wind = 10;
    qreal alfa_wind = 0;
    QDateTime date_time;
    QList<Ellipse> ellipse_list;
    QStringList legend;

    int get_zone_id_for_q(qreal q);
    int get_max_v_wind_index(qreal q);
    Type set_type(int index);
    int get_type_index();
    void print();
    void set(int _type_index, qreal _q, QDateTime _date_time, qreal _vh_wind, qreal _alfa_wind);

private:
    QStringList set_legend(Type _type, qreal _q, QDateTime _date_time);
    QString get_letter_for_legend(Type _type);
    QString get_sepatarot_for_legend(QStringList legend);

};

#endif // BLASTMATH_H
