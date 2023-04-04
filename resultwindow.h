#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>
#include <QTableWidget>
#include "blastmath.h"
#include "ellipse.h"
#include "inputwindow.h"
#include "random.h"

namespace Ui {
class ResultWindow;
}

class ResultWindow : public QMainWindow
{
    Q_OBJECT

public:
    ResultWindow(QWidget *parent, BlastMath _blast);
    ~ResultWindow();
    BlastMath blast;

private:
    Ui::ResultWindow *ui;
    void set_rad_d(QDoubleSpinBox *&doubleSpinBox, qreal value);
    void set_zone_table(QTableWidget *&tableWidget, int zone_index);
    void resize_table(QTableWidget *tableWidget);
    void draw_graph(QList<int> kill_list);
    QVector <int> get_x_vector(QList<int> kill_list);
    QVector<int> get_y_vector(QList<int> kill_list);
    QString get_legend(int index);
    QColor get_random_color(int alfa);

};
#endif // RESULTWINDOW_H
