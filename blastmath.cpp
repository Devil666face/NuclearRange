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

Type BlastMath::set_type(int index)
{
    switch (index) {
    case 0:
        return Air;
        break;
    case 1:
        return Ground;
        break;
    case 2:
        return Overwather;
        break;
    case 3:
        return Underwather;
        break;
    case 4:
        return Underground;
        break;
    default:
        return Ground;
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
    qDebug()<<"legend"<<legend;
    foreach (auto ellipse, ellipse_list) {
        ellipse.print();
    }
}

void BlastMath::set(int _type_index, qreal _q, QDateTime _date_time, qreal _vh_wind, qreal _alfa_wind)
{
    type = set_type(_type_index);
    q = _q;
    date_time = _date_time;
    vh_wind = _vh_wind;
    alfa_wind = _alfa_wind;
    legend = set_legend(type, _q, _date_time);
}

QStringList BlastMath::set_legend(Type _type, qreal _q, QDateTime _date_time)
{
    QStringList legend;
    legend<<QString("%1-%2").arg(_q).arg(get_letter_for_legend(_type));
    legend<<QString("%1.%2 %3.%4").arg(_date_time.time().hour()).arg(_date_time.time().minute()).arg(_date_time.date().day()).arg(_date_time.date().month());
    return legend;
}

QString BlastMath::get_letter_for_legend(Type _type)
{
    switch (_type) {
    case Air:
        return "В";
    case Ground:
        return "Н";
    case Overwather:
        return "ВП";
    case Underwather:
        return "ПВ";
    case Underground:
        return "П";
    }
    return "Н";
}

