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
    set_pen(painter, QColor(Qt::red));
    foreach (auto ellipse, ellipse_list) {
        // Calculate the points of the elliptical GeoDataLinearRing
        const qreal centerLatitude = blast.lat*57.3; // Replace with your own center latitude
        const qreal centerLongitude = blast.lon*57.3; // Replace with your own center longitude
        const qreal majorAxis = 1/110.5; // Replace with your own major axis in meters
        const qreal minorAxis = 10/110.5; // Replace with your own minor axis in meters
        const int numPoints = 60; // Replace with the desired number of points around the ellipse circumference
        GeoDataLinearRing ell;
        for (int i = 0; i < numPoints; ++i) {
            qreal angle = i * 2 * M_PI / numPoints;
            qDebug()<<angle;
            qreal x = centerLongitude + majorAxis * cos(angle);
            qreal y = centerLatitude + minorAxis * sin(angle);
            qDebug()<<x<<y<<centerLatitude<<centerLongitude;
            ell << GeoDataCoordinates(x, y, 0, GeoDataCoordinates::Degree);
        }
        painter->drawPolygon(ell);
    }

}

void MapLayer::set_pen(GeoPainter *painter, QColor color)
{
    painter->setPen(QPen(color, 2));
    painter->setBrush(QBrush(color));
}


