#include "drawoptics.h"

DrawOptics::DrawOptics(QWidget *parent)
{
    _screen = nullptr;
    _edgeList = nullptr;
    _rayList = nullptr;
}

DrawOptics::DrawOptics(Screen *screen, EdgeList *edgeList, RayList *rayList, QWidget *parent): QWidget(parent)
{
    painter = new QPainter;
    setMinimumSize(300,300);
    _screen = screen;
    _edgeList = edgeList;
    _rayList = rayList;

}

void DrawOptics::set(Screen *screen, EdgeList *edgeList, RayList *rayList)
{
    painter = new QPainter;
    setMinimumSize(300,300);
    _screen = screen;
    _edgeList = edgeList;
    _rayList = rayList;
}

DrawOptics::~DrawOptics()
{
    if(painter){
        delete painter;
        painter = nullptr;
    }
}

void DrawOptics::paintEvent(QPaintEvent *)
{
    if(!_screen) return;
    painter->begin(this);
    //масштабирование окна
    double w = width();
    double h = height();
    if (w > h / _screen->range().y() * _screen->range().x())
        w = h / _screen->range().y() * _screen->range().x();
    else h = w * _screen->range().y() / _screen->range().x();
    _screen->setResolution(w, h);

    //белый фон
    QBrush brush(Qt::white);
    painter->fillRect(0,0,_screen->resolutionX(),_screen->resolutionY(),brush);

    //рисую границы
    if(_edgeList){
        for (auto i : *_edgeList) {
            i->draw(painter, _screen);
        }
    }

    //рисую лучи
    if(_rayList){
        QPolygon polygon;
        painter->setPen(Qt::red);
        for(auto path: *_rayList){
            polygon.clear();
            for(auto i:*path){
                polygon << _screen->doubleToInt({i.x(), i.y()});
            }
            painter->drawPolyline(polygon);
        }
    }


    painter->end();

}

