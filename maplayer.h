#ifndef MAPLAYER_H
#define MAPLAYER_H

#include <QPair>
#include <cmath>
#include <QGeoShape>
#include <GeoDataLatLonBox.h>
#include <GeoDataPlacemark.h>
#include <GeoDataLinearRing.h>
#include <AbstractFloatItem.h>
#include <QSvgRenderer>
#include <QDebug>
#include <QGridLayout>
#include <MarbleGlobal.h>
#include <MarbleWidget.h>
#include <MarbleMap.h>
#include <MarbleModel.h>
#include <GeoPainter.h>
#include <LayerInterface.h>
#include <QPainter>
#include "ellipse.h"
#include "blastmath.h"

using namespace Marble;

class MapLayer : public LayerInterface
{
    virtual bool render(GeoPainter* painter, ViewportParams* viewport,
                        const QString& renderPos = "NONE", GeoSceneLayer* layer = nullptr)override;
    virtual QStringList renderPosition() const override;


public:
    MapLayer(int _zoom, int _zoom_max, int _zoom_min);
   ~MapLayer()override;
    int zoom;
    int zoom_max;
    int zoom_min;
    QVector<qreal> zoom_vector;
    bool draw_zone = false;
    bool draw_regimen = false;
    BlastMath blast;

private:
    qreal deg_to_rad(qreal deg) {
        return blast.deg_to_rad(deg);
    };
    qreal rad_to_deg(qreal rad) {
        return blast.rad_to_deg(rad);
    };
    int zoom_convert(int value);
    QVector<qreal> get_zoom_vector(int max_zoom, int min_zoom);
    int get_zoom_interval(int zoom_value, QVector<qreal> zoom_vector);
    QImage get_image(int interval, QString image_name);
    void draw_zone_list(GeoPainter* painter, QList<Ellipse> ellipse_list);
    void draw_ellipse(GeoPainter* painter, BlastMath blast, Ellipse ellipse);
    void draw_point(GeoPainter* painter, GeoDataCoordinates center, Ellipse ellipse, QColor main_color);
    void draw_small_radius(GeoPainter* painter, GeoDataCoordinates center, qreal radius);
    void draw_legend(GeoPainter* painter, GeoDataCoordinates center, QStringList legend, int x_offset);
    void set_painter_color(GeoPainter* painter, QColor main_color);
    void set_color_for_zone(GeoPainter* painter, int zone_index);
};


//#include <MarbleWidget.h>
//#include <MarbleModel.h>
//#include <GeoDataTreeModel.h>
//#include <GeoDataPlacemark.h>
//#include <GeoDataCoordinates.h>
//#include <GeoDataStyle.h>
//#include <GeoDataIconStyle.h>
//#include <MarbleWidgetPopupMenu.h>
//#include <ViewportParams.h>
//#include <GeoDataRegion.h>
//#include <GeoDataLineString.h>
//#include <MarbleWidgetInputHandler.h>
//#include <GeoDataLatLonBox.h>
//#include <GeoDataLatLonAltBox.h>


//#include <GeoPainter.h>
//#include <QContextMenuEvent>
//#include <GeoDataDocument.h>
//#include <QPaintEvent>
//#include <QtMath>
//#include <QColorDialog>
//#include <GeoDataPolygon.h>
//#include <QColor>

#endif // MAPLAYER_H
