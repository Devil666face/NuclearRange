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
    set_pen(painter, QColor(Qt::red), QColor(255, 0, 0, 20));
    foreach (auto ellipse, ellipse_list) {
        draw_ellipse(painter, blast, ellipse);
    }
}

void MapLayer::set_pen(GeoPainter *painter, QColor color_pen, QColor color_brush)
{
    painter->setPen(QPen(color_pen, 2));
    painter->setBrush(QBrush(color_brush));
}

QVector<QPair<qreal,qreal>> MapLayer::getEllipseCoords(qreal centerX, qreal centerY, qreal a, qreal b, qreal rotationAngle, int numPoints)
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
    QVector<QPair<qreal,qreal>> coord_list = getEllipseCoords(rad_to_deg(blast.lon), rad_to_deg(blast.lat), km_to_deg(ellipse.width), km_to_deg(ellipse.length, blast.lat), qreal(deg_to_rad(blast.alfa_wind)), int(ellipse.length*2));
    GeoDataLinearRing ellipse_polygon;
    foreach (auto pair, coord_list) {
        ellipse_polygon.append(GeoDataCoordinates(pair.first, pair.second, 0, GeoDataCoordinates::Degree));
    }
    painter->drawPolygon(ellipse_polygon);
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
