#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QComboBox>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QDateTimeEdit>
#include <GeoDataCoordinates.h>
#include <QtGlobal>
#include "blastmath.h"
#include "animatedlabel.h"

namespace Ui {
class InputWindow;
}

class InputWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InputWindow(QWidget *parent = nullptr);
    ~InputWindow();
    BlastMath blast;

private:
    QComboBox* get_window_v_comboBox(int max_v_wind_index);
    QDoubleSpinBox* get_alfa_doubleSpinBox();
    qreal get_value_from_cell_widget(QWidget* widget);

    void resize_table(QTableWidget *tableWidget);
    void set_dateTime(QDateTimeEdit*& edit);

    AnimatedLabel *create_button(QString icon_path, QString legend, int size, QGridLayout *&lay);
    void create_button_enter(AnimatedLabel* button);
    void create_button_coor(AnimatedLabel* button);
    void create_button_coor_work(AnimatedLabel* button);
    void set_max_q(Type type, QComboBox*& comboBox);
    QList<QList<qreal>> get_values_from_tableWidget(QTableWidget*& tableWidget);
    bool check_coor(BlastMath blast);

private slots:
    void on_comboBox_type_currentIndexChanged(int index);
    void on_pushButton_enter();
    void on_pushButton_coor();
    void on_pushButton_coor_work();
    void on_comboBox_q_currentTextChanged(const QString &arg1);
    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);
    void recive_coor_from_mainwidnow(qreal lon, qreal lat);

private:
    Ui::InputWindow *ui;
    void init_weather_tableWidjet(QTableWidget *&tableWidget, int column, int max_v_wind_index);

signals:
    void send_blast_data(BlastMath blast);
    void coor_button_push();
};

#endif // INPUTWINDOW_H
