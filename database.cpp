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
    qDebug()<<"case_t_start"<<t_start<<"case_t_work"<<t_work<<"zone_index"<<zone_index;
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
    t_start_list
    <<240
      <<192
        <<144
          <<96
            <<72
              <<48
                <<24
                  <<21
                    <<18
                      <<15
                        <<12
                          <<10
                            <<8
                              <<6
                                <<5
                                  <<4
                                    <<3
                                      <<2
                                        <<1;
    return case_value(t_start, t_start_list);

}

int database::case_t_work(int t_work)
{
    QList <int> t_work_list;
    t_work_list<<720<<360<<240<<192<<144<<96<<72<<48<<24<<21<<18<<15<<12<<10<<8<<6<<5<<4<<3<<2<<1;


    return case_value(t_work, t_work_list);
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
