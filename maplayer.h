#ifndef MAPLAYER_H
#define MAPLAYER_H

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
    MapLayer();
   ~MapLayer()override;
    bool draw_zone = false;
    BlastMath blast;
    MarbleWidget* map;

private:
    void draw_zone_list(GeoPainter* painter, QList<Ellipse> ellipse_list);
    void set_pen(GeoPainter* painter, QColor color_pen, QColor color_brush);
    QVector<QPair<qreal,qreal>> getEllipseCoords(qreal centerX, qreal centerY, qreal a, qreal b, qreal rotationAngle, int numPoints);
    QPair<qreal, qreal> get_coords_for_offset(qreal x, qreal y, qreal distance, qreal angle);
    void draw_ellipse(GeoPainter* painter, BlastMath blast, Ellipse ellipse);
    qreal km_to_deg(qreal km_value, qreal lat_in_rad);
    qreal km_to_deg(qreal km_value);
    qreal deg_to_rad(qreal deg);
    qreal rad_to_deg(qreal rad);
};

#endif // MAPLAYER_H
