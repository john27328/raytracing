#ifndef DRAWOPTICS_H
#define DRAWOPTICS_H

#include <QWidget>
#include <QPainter>
#include <QPointer>
#include <QSize>
#include <QRect>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QDebug>
#include <cmath>
#include <QPolygon>
#include <QPolygonF>
#include <QString>
#include <QLabel>
#include <QPainterPath>
#include <QPointF>
#include <QRectF>
#include "screen.h"
#include <vector>
#include "old_edge.h"
#include <QtCore>
//#include <QVBoxLayout>

class DrawOptics : public QWidget
{
    Q_OBJECT
public:
    DrawOptics(QWidget *parent = nullptr);
    DrawOptics(Screen *screen, EdgeList *edgeList, RayList *rayList, QWidget *parent = nullptr);
    void set(Screen *screen, EdgeList *edgeList, RayList *rayList);
    ~DrawOptics();
    virtual void paintEvent(QPaintEvent*);

signals:

public slots:

private:
    QPainter *painter = nullptr;
    Screen *_screen = nullptr;
    EdgeList *_edgeList = nullptr;
    RayList *_rayList = nullptr;
};

#endif // DRAWOPTICS_H
