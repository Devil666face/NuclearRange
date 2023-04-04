#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "ellipse.h"

ResultWindow::ResultWindow(QWidget *parent, BlastMath _blast) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    blast = _blast;

    set_rad_d(ui->doubleSpinBox_rad_D, blast.D_rad);
    set_zone_table(ui->tableWidget_zone, blast.danger_zone_index);
    draw_graph(blast.kill_list);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::set_rad_d(QDoubleSpinBox *&doubleSpinBox, qreal value)
{
    doubleSpinBox->setValue(value);
}

void ResultWindow::set_zone_table(QTableWidget *&tableWidget, int zone_index)
{
    tableWidget->setColumnCount(3);
    tableWidget->setRowCount(blast.ellipse_list.size());
    QStringList zone_header;
    zone_header<<"A"<<"Б"<<"В"<<"Г";
    QStringList vert_header;
    for (int i=0;i<blast.ellipse_list.size();i++) {
        vert_header.append(zone_header[i]);
    }
    tableWidget->setVerticalHeaderLabels(vert_header);
    QStringList horiz_header;
    horiz_header<<"Длина, км"<<"Ширина, км"<<"ЗРП попадает\nв зону";
    tableWidget->setHorizontalHeaderLabels(horiz_header);
    for (int i=0;i<blast.ellipse_list.size();i++) {
        for (int j=0;j<tableWidget->columnCount()-1;j+=2) {
            tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(blast.ellipse_list[i].length)));
            tableWidget->setItem(i,j+1,new QTableWidgetItem(QString::number(blast.ellipse_list[i].width)));
        }
    }
    for (int i=0;i<zone_index+1;i++) {
        tableWidget->setItem(i,2, new QTableWidgetItem("+"));
    }
    resize_table(tableWidget);
}

void ResultWindow::resize_table(QTableWidget *tableWidget)
{
    tableWidget->horizontalHeader()->resizeContentsPrecision();
    tableWidget->verticalHeader()->resizeContentsPrecision();
    tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void ResultWindow::draw_graph(QList <int> kill_list)
{
    QVector <int> hit_counts;
    ui->graph->setInteraction(QCP::iRangeZoom,true);
    ui->graph->setInteraction(QCP::iRangeDrag,true);
    ui->graph->xAxis->setVisible(false);
//    ui->graph->yAxis->setVisible(false);
//    ui->graph->xAxis->setLabel("Номер аэродрома");
    ui->graph->yAxis->setLabel("Суммарный выход из строя личного состава, %");
    ui->graph->xAxis->setRange(-1,kill_list.size()+1);
    ui->graph->yAxis->setRange(0,100);
    QVector <int> y = get_y_vector(kill_list);
    QVector <int> x = get_x_vector(kill_list);
    for (int i=0;i<x.size();i++)
    {
        ui->graph->addGraph();
        ui->graph->graph()->addData(qreal(x.at(i)),qreal(y.at(i)));
        ui->graph->graph()->setPen(QPen(get_random_color(200),100));
        ui->graph->graph()->setLineStyle((QCPGraph::LineStyle)(5));
        ui->graph->graph()->setName(get_legend(i).arg(kill_list[i]));
        ui->graph->replot();
    }
    ui->graph->legend->setVisible(true);
    ui->graph->replot();
}

QVector<int> ResultWindow::get_x_vector(QList<int> kill_list)
{
    QVector <int> _x_list;
    for (int i=0;i<kill_list.size();i++) _x_list.append(i);
    return _x_list;
}

QVector<int> ResultWindow::get_y_vector(QList<int> kill_list)
{
    QVector <int> _y_list;
    for (int i=0;i<kill_list.size();i++) _y_list.append(kill_list[i]);
    return _y_list;
}

QString ResultWindow::get_legend(int index)
{
    QStringList legend_list;
    legend_list
            <<"Через 3 часа"
           <<"Через 6 часов"
          <<"Через 12 часов"
         <<"Через 1 сутки"
        <<"Через 14 суток"
       <<"Через 30 суток"
      <<"Смертность облученных";
    return legend_list[index].append(QString(" - %1%"));
}

QColor ResultWindow::get_random_color(int alfa)
{
    int r = Random::get(0,255);
    int g = Random::get(0,255);
    int b = Random::get(0,255);
    return QColor(r,g,b,alfa);
}


