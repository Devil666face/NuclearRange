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
    while (query->next())
    {
        for (int i=3; i<10; i+=2) {
            Ellipse ellipse;
            ellipse.length = query->value(i).toDouble();
            ellipse.width = query->value(i+1).toDouble();
            ellipse_list.push_back(ellipse);
        }
    }
    return ellipse_list;
}
