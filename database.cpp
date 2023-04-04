#include "database.h"

database::database(QString database_name)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = qApp->applicationDirPath();
    qDebug()<<path;
    path.push_back(QString("/%1").arg(database_name));
    db.setDatabaseName(path);
    if (db.open())  qDebug("DB open");
    else qDebug("DB not open");
}

QList<Ellipse> database::get_range_list(int type_index, qreal q, qreal v)
{
    QList <Ellipse> ellipse_list;
    query = new QSqlQuery(db);
    QString sql_query = QString("SELECT * "
                        "FROM range WHERE "
                        "type=%1 AND "
                        "q_power=%2 AND "
                        "v_wind=%3;").arg(type_index).arg(q).arg(v);

    query->exec(sql_query);
    while (query->next()) {
        for (int i=3; i<10; i+=2) {
            Ellipse ellipse;
            ellipse.length = query->value(i).toDouble();
            ellipse.width = query->value(i+1).toDouble();
            ellipse_list.push_back(ellipse);
        }
    }
    return ellipse_list;
}

qreal database::get_D_rad(int zone_index, int t_start, int t_work)
{
    query = new QSqlQuery(db);
    t_start = case_t_start(t_start);
    t_work = case_t_work(t_work);
    QString sql_query = QString("SELECT rad "
                                "FROM rad_hit WHERE "
                                "zone_index=%1 AND "
                                "t_start=%2 AND "
                                "t_work=%3;").arg(zone_index).arg(t_start).arg(t_work);
    query->exec(sql_query);
    while (query->first()) {
        return query->value(0).toDouble();
    }
}

int database::case_t_start(int t_start)
{
    QList <int> t_start_list;
    t_start_list<<240<<192<<144<<96<<72<<48<<24<<21<<18<<15<<12<<10<<8<<6<<5<<4<<3<<2<<1;
    return case_value(t_start, t_start_list);
}

int database::case_t_start_for_d(int t_start, int case_d)
{
    QList <int> t_start_list_for_d;
    t_start_list_for_d<<4<<2<<1;
    if ((case_d==100) || (case_d==125) || (case_d==150) || (case_d==175) || (case_d==200)) {
        if (t_start<=96) return 96;
        else return -1;
    }
    else {
        return case_value(t_start, t_start_list_for_d);
    }
}

int database::case_t_work(int t_work)
{
    QList <int> t_work_list;
    t_work_list<<720<<360<<240<<192<<144<<96<<72<<48<<24<<21<<18<<15<<12<<10<<8<<6<<5<<4<<3<<2<<1;
    return case_value(t_work, t_work_list);
}

int database::case_t_work_for_d(int t_work, int case_d)
{
    QList <int> t_work_list_for_d;
    t_work_list_for_d<<96<<24<<12<<6<<3<<2<<1;
    if (t_work>96) return -1;
    if ((case_d==100) || (case_d==125) || (case_d==150)) {
        return 96;
    }
    else {
        return case_value(t_work, t_work_list_for_d);
    }
}

int database::case_d_rad(int D_rad)
{
    QList <int> d_rad_list;
    d_rad_list<<600<<500<<400<<300<<250<<200<<175<<150<<125<<100;
    return case_value(D_rad, d_rad_list);
}

int database::case_value(int value, QList<int> list_treshold)
{
    int _value = 1;
    foreach(int treshold, list_treshold) {
        if (value<=treshold) _value = treshold;
    }
    if (value>list_treshold.first()) _value=list_treshold.first();
    return _value;
}

QList<int> database::get_kill_list_for_D(qreal D_rad, qreal t_start, qreal t_work)
{
    QList<int> _kill_list_for_D;
    D_rad = case_d_rad(D_rad);
    t_start = case_t_start_for_d(t_start, D_rad);
    t_work = case_t_work_for_d(t_work, D_rad);
    if ((t_start==-1) || (t_work==-1)) return _kill_list_for_D;
    qDebug()<<"case D rad"<<D_rad<<"t start"<<t_start<<"t work"<<t_work;
    QString sql_query = QString("SELECT kill_3, kill_6, kill_12, kill_24, kill_336, kill_720, kill_letal "
                                "FROM kill WHERE "
                                "rad=%1 AND "
                                "t_start=%2 AND "
                                "t_work=%3;").arg(D_rad).arg(t_start).arg(t_work);
    query->exec(sql_query);
    while (query->next()) {
        for (int i=0; i<7; i++) {
            _kill_list_for_D.append(query->value(i).toInt());
        };
    }
    return _kill_list_for_D;
}
