#ifndef BLASTMATH_H
#define BLASTMATH_H
#define EARTH_RADIUS_KM 6371.0
#include <QMainWindow>
#include <QDebug>
#include <QDateTime>
#include <QPair>
#include <cmath>
#include "database.h"
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

    database* db;

    Type type = Ground;
    qreal lon=-1;
    qreal lat=-1;
    qreal q = 0.1;
    qreal vh_wind = 10;
    qreal alfa_wind = 0;
    QDateTime date_time;
    QList<Ellipse> ellipse_list;
    QStringList legend;

    int t_enter = 0;
    int T_work = 0;
    int D_before = 0;
    int N_count = 0;
    qreal work_lon = -1;
    qreal work_lat = -1;
    int D_cloud = 0;
    int D_ground = 0;
    int t_delta_nuclear = 0;
    int A_air = 0;
    int K_down = 3;
    qreal K_zone = 0;
    qreal K_rz = 0;
    int danger_zone_index = -1;

    int get_zone_id_for_q(qreal q);
    int get_max_v_wind_index(qreal q);
    Type set_type(int index);
    int get_type_index();
    void print();
    void set_blast_params(int _type_index, qreal _q, QDateTime _date_time, qreal _vh_wind, qreal _alfa_wind);
    void set_work_params(int _t_enter, int _T_work, int _D_before, int _N_count, int _D_cloud, int _D_ground, int _t_d_nuclear, int _A_air);
    QVector<QPair<qreal,qreal>> get_ellipse_coords(qreal centerX, qreal centerY, qreal a, qreal b, qreal rotationAngle, int numPoints);
    void work_math();

    qreal km_to_deg(qreal km_value, qreal lat_in_rad);
    qreal km_to_deg(qreal km_value);
    qreal rad_to_deg(qreal rad);
    qreal deg_to_rad(qreal deg);

private:
    QStringList set_legend(Type _type, qreal _q, QDateTime _date_time);
    QString get_letter_for_legend(Type _type);
    QString get_sepatarot_for_legend(QStringList legend);
    QPair<qreal, qreal> get_coords_for_offset(qreal x, qreal y, qreal distance, qreal angle);
    qreal get_K_zone(qreal _K_rz, QList<Ellipse> _ellipse_list);
//    qreal get_range_between_two_point(qreal lon1, qreal lat1, qreal lon2, qreal lat2);
    bool is_point_in_ellipse(QVector<QPair<qreal,qreal>> coord_list, qreal x, qreal y);
    qreal get_D(int zone_index, qreal K_zone, int D_before, int x, int y);
};

#endif // BLASTMATH_H
