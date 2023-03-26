#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QMainWindow>
#include <QDebug>

class Ellipse {
public:
    qreal length;
    qreal width;

    void print() {
        qDebug()<<length;
        qDebug()<<width;
    };
};

#endif // ELLIPSE_H
