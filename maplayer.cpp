#include "maplayer.h"
#include "mainwindow.h"

MapLayer::MapLayer():LayerInterface()
{

}

bool MapLayer::render(GeoPainter* painter, ViewportParams* viewport,
    const QString& /*renderPos*/, GeoSceneLayer* /*layer*/)
{
    draw_zone_list(painter, blast.ellipse_list);
    return true;
}


QStringList MapLayer::renderPosition() const
{
    return QStringList() << "USER_TOOLS";
}


MapLayer::~MapLayer()
{
}

void MapLayer::draw_zone_list(GeoPainter* painter, QList<Ellipse> ellipse_list)
{
    if (!draw_zone) return;
    painter->setPen(QPen(Qt::black, 2));
    draw_legend(painter, GeoDataCoordinates(blast.lon, blast.lat), blast.legend);
    for (int i=0;i<ellipse_list.size();i++) {
        set_color_for_zone(painter, i);
        draw_ellipse(painter, blast, ellipse_list[i]);
        draw_small_radius(painter, GeoDataCoordinates(blast.lon, blast.lat), ellipse_list[i]);
    }
}

void MapLayer::set_painter_color(GeoPainter *painter, QColor main_color)
{
    painter->setPen(QPen(main_color, 0));
    painter->setBrush(QBrush(QColor(main_color.red(),main_color.green(),main_color.blue(), 100)));
}

void MapLayer::set_color_for_zone(GeoPainter *painter, int zone_index)
{
    QList<QColor> color_list;
    color_list<<QColor(255,0,0,0)<<QColor(0,0,255,0)<<QColor(0,255,0,0)<<QColor(150,75,0,0);
    set_painter_color(painter, color_list[zone_index]);
}

QVector<QPair<qreal,qreal>> MapLayer::get_ellipse_coords(qreal centerX, qreal centerY, qreal a, qreal b, qreal rotationAngle, int numPoints)
{
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

QPair<qreal, qreal> MapLayer::get_coords_for_offset(qreal x, qreal y, qreal distance, qreal angle)
{
    qreal x_offset = x+distance*cos(deg_to_rad(90+angle));
    qreal y_offset = y+distance*sin(deg_to_rad(90+angle));
    return QPair<qreal,qreal>(x_offset, y_offset);
}

void MapLayer::draw_ellipse(GeoPainter *painter, BlastMath blast, Ellipse ellipse)
{
    if ((blast.lon==0) && (blast.lat==0)) return;
    QVector<QPair<qreal,qreal>> coord_list = get_ellipse_coords(rad_to_deg(blast.lon), rad_to_deg(blast.lat), km_to_deg(ellipse.width), km_to_deg(ellipse.length, blast.lat), qreal(deg_to_rad(blast.alfa_wind)), int(ellipse.length*2));
    GeoDataLinearRing ellipse_polygon;
    foreach (auto pair, coord_list) {
        ellipse_polygon.append(GeoDataCoordinates(pair.first, pair.second, 0, GeoDataCoordinates::Degree));
    }
    painter->drawPolygon(ellipse_polygon);
}

void MapLayer::draw_small_radius(GeoPainter *painter, GeoDataCoordinates center, Ellipse ellipse)
{
    if ((center.latitude()==0) && (center.longitude()==0)) return;
    GeoDataLinearRing ring_polygon;
    for (qreal a=0.0;a<=360.0;a+=1.0) ring_polygon.append(center.moveByBearing(a/57.3,(ellipse.length/10)/6371));
    painter->drawPolygon(ring_polygon);
}

void MapLayer::draw_legend(GeoPainter *painter, GeoDataCoordinates center, QStringList legend)
{
    painter->drawText(center, legend.first(), zoom_convert(-100));
}

qreal MapLayer::km_to_deg(qreal km_value, qreal lat_in_rad)
{
    qreal const METHER_TO_DEGREE_FACTOR = 1.0 / 111.3199;
    qreal deg_to_km_factor = cos(rad_to_deg(lat_in_rad)*M_PI/180.0) * METHER_TO_DEGREE_FACTOR;
    return qreal(km_value*deg_to_km_factor);
}

qreal MapLayer::km_to_deg(qreal km_value)
{
    return qreal(km_value/111.3199);
}

qreal MapLayer::deg_to_rad(qreal deg)
{
    return qreal(deg/57.3);
}

qreal MapLayer::rad_to_deg(qreal rad)
{
    return qreal(rad*57.3);
}

int MapLayer::zoom_convert(int value)
{
    qDebug()<<qreal(zoom/zoom_max)*value<<zoom<<zoom_max<<value;
    return int(qreal(zoom/zoom_max)*qreal(value));
}

qreal MapLayer::zoom_convert(qreal value)
{
    qDebug()<<zoom<<qreal(zoom/value);
    return qreal(zoom/value);
}
