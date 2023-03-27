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

    int get_zone_id_for_q(qreal q);
    int get_max_v_wind_index(qreal q);
    void set_type(int index);
    int get_type_index();
    void print();


private:

};

#endif // BLASTMATH_H
