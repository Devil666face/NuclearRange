#include "blastmath.h"

BlastMath::BlastMath()
{

}

int BlastMath::get_zone_id_for_q(qreal q)
{
    if (q<qreal(1)) {
        return 0;
    }
    else if ((q>=qreal(1)) && (q<qreal(10))) {
        return 1;
    }
    else if ((q>=qreal(10)) && (q<qreal(100))) {
        return 2;
    }
    else if ((q>=qreal(100)) && (q<qreal(1000))) {
        return 3;
    }
    else if (q>=qreal(1000)) {
        return 4;
    }
    return 4;
}

int BlastMath::get_max_v_wind_index(qreal q)
{
    if (q<qreal(1)) {
        return 2;
    }
    else if ((q>=qreal(1)) && (q<=qreal(2))) {
        return 3;
    }
    return 4;
}

void BlastMath::set_type(int index)
{
    switch (index) {
    case 0:
        type = Air;
        break;
    case 1:
        type = Ground;
        break;
    case 2:
        type = Overwather;
        break;
    case 3:
        type = Underwather;
        break;
    case 4:
        type = Underground;
        break;
    default:
        type = Ground;
        break;
    }
}

int BlastMath::get_type_index()
{
    switch (type) {
    case Air:
        return 0;
    case Ground:
        return 1;
    case Overwather:
        return 2;
    case Underwather:
        return 3;
    case Underground:
        return 4;
    }
    return 1;
}

void BlastMath::print()
{
    if (type==Air) qDebug()<<"Air";
    if (type==Ground) qDebug()<<"Ground";
    if (type==Overwather) qDebug()<<"Overwather";
    if (type==Underwather) qDebug()<<"Underwather";
    if (type==Underground) qDebug()<<"Underground";
    qDebug()<<"q"<<q;
    qDebug()<<"vh_wind"<<vh_wind;
    qDebug()<<"alfa_wind"<<alfa_wind;
    qDebug()<<"date_time"<<date_time;
    qDebug()<<"lon"<<lon;
    qDebug()<<"lat"<<lat;
    foreach (auto ellipse, ellipse_list) {
        ellipse.print();
    }
}
