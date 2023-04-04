#include "blastmath.h"

BlastMath::BlastMath()
{
    db = new database(QString("database.sqlite3"));
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

void BlastMath::set_blast_params(int _type_index, qreal _q, QDateTime _date_time, qreal _vh_wind, qreal _alfa_wind)
{
    type = set_type(_type_index);
    q = _q;
    date_time = _date_time;
    vh_wind = _vh_wind;
    alfa_wind = _alfa_wind;
    legend = set_legend(type, _q, _date_time);
    ellipse_list = db->get_range_list(get_type_index(), q, vh_wind);
}

void BlastMath::set_work_params(int _t_enter, int _T_work, int _D_before, int _N_count, int _D_cloud, int _D_ground, int _t_d_nuclear, int _A_air)
{
    t_enter = _t_enter;
    T_work = _T_work;
    D_before = _D_before;
    N_count = _N_count;
    D_cloud = _D_cloud;
    D_ground = _D_ground;
    t_delta_nuclear = _t_d_nuclear;
    A_air = _A_air;
}

QVector<QPair<qreal, qreal> > BlastMath::get_ellipse_coords(qreal centerX, qreal centerY, qreal a, qreal b, qreal rotationAngle, int numPoints)
{
    if (numPoints<100) numPoints=100;
    QPair<qreal, qreal>offset_coords = get_coords_for_offset(centerX, centerY, b, rad_to_deg(rotationAngle));
    QVector<QPair<qreal,qreal>> coords;
    centerX = offset_coords.first;
    centerY = offset_coords.second;
    for (int i = 0; i < numPoints; i++) {
        qreal angle = i * (2 * M_PI / numPoints);
        qreal distance = a * b / sqrt(pow(b*cos(angle),2) + pow(a*sin(angle),2));
        qreal x = distance * cos(angle);
        qreal y = distance * sin(angle);
        qreal newX = x*cos(rotationAngle) - y*sin(rotationAngle);
        qreal newY = x*sin(rotationAngle) + y*cos(rotationAngle);
        coords.push_back(QPair<qreal,qreal>(centerX + newX, centerY + newY));
    }
    return coords;
}

void BlastMath::work_math()
{
    K_rz = K_down*N_count;
    K_zone = get_K_zone(K_rz, ellipse_list);
    if (danger_zone_index==-1) return;
    D_rad = get_D(danger_zone_index, K_zone, D_before, t_enter, T_work);
    kill_list = get_kill(D_rad, t_enter, T_work);
}

bool BlastMath::check_coor(qreal lon, qreal lat)
{
    if ((lon!=-1) && (lat!=-1)) return true;
    return false;
}

bool BlastMath::check_coor_blast()
{
    return check_coor(lon, lat);
}

bool BlastMath::check_coor_work()
{
    return check_coor(work_lon, work_lat);
}

bool BlastMath::check_empty_kill_list()
{
    if (kill_list.isEmpty()) return true;
    return false;
}

bool BlastMath::check_empty_ellipse_list()
{
    if (ellipse_list.isEmpty()) return true;
    return false;
}

bool BlastMath::check_no_in_zone()
{
    if (danger_zone_index==-1) return true;
    return false;
}

QPair<qreal, qreal> BlastMath::get_coords_for_offset(qreal x, qreal y, qreal distance, qreal angle)
{
    qreal x_offset = x+distance*cos(deg_to_rad(90+angle));
    qreal y_offset = y+distance*sin(deg_to_rad(90+angle));
    return QPair<qreal,qreal>(x_offset, y_offset);
}

qreal BlastMath::get_K_zone(qreal _K_rz, QList<Ellipse> _ellipse_list)
{
    danger_zone_index=-1;
    foreach (Ellipse ellipse, _ellipse_list) {
        QVector<QPair<qreal,qreal>> coord_list = get_ellipse_coords(rad_to_deg(lon), rad_to_deg(lat), km_to_deg(ellipse.width), km_to_deg(ellipse.length, lat), qreal(deg_to_rad(alfa_wind)), int(ellipse.length*2));
        bool is_ellipse = is_point_in_ellipse(coord_list, rad_to_deg(work_lon), rad_to_deg(work_lat));
        if (is_ellipse) danger_zone_index++;
    }
    switch (danger_zone_index) {
    case -1:
        return _K_rz/3.2;
        break;
    case 0:
        return 3.2/_K_rz;
        break;
    case 1:
        return 1.7/_K_rz;
        break;
    case 2:
        return 1.8/_K_rz;
        break;
    case 3:
        return 1.8/_K_rz;
        break;
    default:
        break;
    }

}

bool BlastMath::is_point_in_ellipse(QVector<QPair<qreal, qreal> > coord_list, qreal x, qreal y)
{
    bool is_inside = false;
    for (int i = 0, j = coord_list.size() - 1; i < coord_list.size(); j = i++) {
        qreal xi = coord_list[i].first;
        qreal yi = coord_list[i].second;
        qreal xj = coord_list[j].first;
        qreal yj = coord_list[j].second;
        if (((yi > y) != (yj > y)) &&
            (x < (xj - xi) * (y - yi) / (yj - yi) + xi)) {
            is_inside = !is_inside;
        }
    }
    return is_inside;
}

qreal BlastMath::get_D(int zone_index, qreal K_zone, int D_before, int x, int y)
{
    qreal D = db->get_D_rad(zone_index, x, y);
    if (D<1) D=1;
    return D*K_zone+D_before;
}

 QList<int> BlastMath::get_kill(qreal D_rad, int t_start, int t_work)
{
    QList<int> kill_list_for_D = db->get_kill_list_for_D(D_rad, t_start, t_work);
    if (kill_list_for_D.isEmpty()) {
        qDebug()<<"no kill";
    }
    qDebug()<<kill_list_for_D;
    return kill_list_for_D;
}


QStringList BlastMath::set_legend(Type _type, qreal _q, QDateTime _date_time)
{
    QStringList legend;
    legend<<QString("%1 - %2").arg(_q).arg(get_letter_for_legend(_type));
    QString lower_string = _date_time.toString("hh:mm dd.MM");
    legend<<lower_string<<lower_string;
    legend[1] = get_sepatarot_for_legend(legend);
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

QString BlastMath::get_sepatarot_for_legend(QStringList legend)
{
    int length = 1;
    foreach (QString line, legend) {
        if (line.length()>length) length=line.length();
    }
    QString separator;
    for (int i=0;i<length-1;i++) {
        separator.append("_");
    }
    return separator;
}

qreal BlastMath::rad_to_deg(qreal rad)
{
    return qreal(rad*57.3);
}

qreal BlastMath::deg_to_rad(qreal deg)
{
    return qreal(deg/57.3);
}

qreal BlastMath::km_to_deg(qreal km_value, qreal lat_in_rad)
{
    qreal const METHER_TO_DEGREE_FACTOR = 1.0 / 111.3199;
    qreal deg_to_km_factor = cos(rad_to_deg(lat_in_rad)*M_PI/180.0) * METHER_TO_DEGREE_FACTOR;
    return qreal(km_value*deg_to_km_factor);
}

qreal BlastMath::km_to_deg(qreal km_value)
{
    return qreal(km_value/111.3199);
}


//qreal BlastMath::get_range_between_two_point(qreal lon1, qreal lat1, qreal lon2, qreal lat2)
//{
//    double dlat = deg_to_rad(lat2 - lat1);
//    double dlon = deg_to_rad(lon2 - lon1);
//    double a = pow(sin(dlat / 2.0), 2.0) +
//               cos(deg_to_rad(lat1)) * cos(deg_to_rad(lat2)) *
//               pow(sin(dlon / 2.0), 2.0);
//    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
//    double d = EARTH_RADIUS_KM * c;
//    return d;
//}
