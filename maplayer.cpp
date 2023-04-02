#include "maplayer.h"
#include "mainwindow.h"

MapLayer::MapLayer(int _zoom, int _zoom_max, int _zoom_min):LayerInterface()
{
    zoom=_zoom;
    zoom_max=_zoom_max;
    zoom_min=_zoom_min;
    zoom_vector = get_zoom_vector(zoom_max, zoom_min);
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
    draw_legend(painter, GeoDataCoordinates(blast.lon, blast.lat), blast.legend, -150);
    for (int i=0;i<ellipse_list.size();i++) {
        set_color_for_zone(painter, i);
        draw_ellipse(painter, blast, ellipse_list[i]);
//        draw_small_radius(painter, GeoDataCoordinates(blast.lon, blast.lat), ellipse_list[i]);
    }
    draw_point(painter, GeoDataCoordinates(blast.lon, blast.lat), ellipse_list.first(), QColor(0,0,0));
    if (!draw_regimen) return;
    painter->drawImage(GeoDataCoordinates(blast.work_lon, blast.work_lat), get_image(get_zoom_interval(zoom, zoom_vector),"zrdn"));

}

void MapLayer::set_painter_color(GeoPainter *painter, QColor main_color)
{
    painter->setPen(QPen(main_color, 0));
    painter->setBrush(QBrush(QColor(main_color.red(),main_color.green(),main_color.blue(), 100)));
}

void MapLayer::set_color_for_zone(GeoPainter *painter, int zone_index)
{
    QList<QColor> color_list;
    color_list<<QColor(0,0,255)<<QColor(0,255,0)<<QColor(255,0,0)<<QColor(0,0,0);
    set_painter_color(painter, color_list[zone_index]);
}

void MapLayer::draw_ellipse(GeoPainter *painter, BlastMath blast, Ellipse ellipse)
{
    if ((blast.lon==0) && (blast.lat==0)) return;
    QVector<QPair<qreal,qreal>> coord_list = blast.get_ellipse_coords(rad_to_deg(blast.lon), rad_to_deg(blast.lat), blast.km_to_deg(ellipse.width), blast.km_to_deg(ellipse.length, blast.lat), qreal(deg_to_rad(blast.alfa_wind)), int(ellipse.length*2));
    GeoDataLinearRing ellipse_polygon;
    foreach (auto pair, coord_list) {
        ellipse_polygon.append(GeoDataCoordinates(pair.first, pair.second, 0, GeoDataCoordinates::Degree));
    }
    painter->drawPolygon(ellipse_polygon);
}

void MapLayer::draw_point(GeoPainter *painter, GeoDataCoordinates center, Ellipse ellipse, QColor main_color)
{
    painter->setPen(QPen(main_color, 2));
    painter->setBrush(QBrush(QColor(0,0,0,0)));
    draw_small_radius(painter, center, ellipse.length/50);
    painter->setBrush(QBrush(QColor(main_color.red(),main_color.green(),main_color.blue(), 255)));
    draw_small_radius(painter, center, ellipse.length/100);
}

void MapLayer::draw_small_radius(GeoPainter *painter, GeoDataCoordinates center, qreal radius)
{
    if ((center.latitude()==0) && (center.longitude()==0)) return;
    GeoDataLinearRing ring_polygon;
    for (qreal a=0.0;a<=360.0;a+=1.0) ring_polygon.append(center.moveByBearing(a/57.3,(radius)/6371));
    painter->drawPolygon(ring_polygon);
}

void MapLayer::draw_legend(GeoPainter *painter, GeoDataCoordinates center, QStringList legend, int x_offset)
{
    painter->drawText(center, legend[0], zoom_convert(x_offset));
    painter->drawText(center, legend[1], zoom_convert(x_offset),-1);
    painter->drawText(center, legend[2], zoom_convert(x_offset), -15);
}

int MapLayer::zoom_convert(int value)
{
    qreal zoom_koef = qreal(zoom)/qreal(zoom_max);
    int offset = int(zoom_koef*qreal(value));
    return offset;
}

QVector<qreal> MapLayer::get_zoom_vector(int max_zoom, int min_zoom)
{
    qreal zoom_step = (max_zoom-min_zoom)/7;
    QVector <qreal> zoom_vector;
    zoom_vector.append(min_zoom);
    for (int i=1;i<8;i++)
        zoom_vector.append(min_zoom+zoom_step*i);
    return zoom_vector;
}

int MapLayer::get_zoom_interval(int zoom_value, QVector<qreal> zoom_vector)
{
    for (int i=0;i<zoom_vector.size();i++)
    {
        if (i==zoom_vector.size()-1) return i;
        if ((zoom_vector[i]<=zoom_value)&&(zoom_value<zoom_vector[i+1])) return i;
    }
}

QImage MapLayer::get_image(int interval, QString image_name)
{
    return QImage(QString(":/new/prefix1/icons/%1_%2.png").arg(image_name).arg(interval));
}
