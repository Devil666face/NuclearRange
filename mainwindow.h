#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "maplayer.h"
#include "inputwindow.h"
#include "animatedlabel.h"
#include "settingswindow.h"
#include "blastmath.h"
#include "ellipse.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
//    windows
    InputWindow* inputwin;
    SettingsWindow* settingswin;
    BlastMath blast;
    void show_window(QMainWindow* window);

    MapLayer* layer;
    MarbleWidget* map;
    void load_map(QGridLayout *&lay, QString map_theme, int projection);
//    buttons
    void create_button_input(AnimatedLabel* button);
    void create_button_settings(AnimatedLabel* button);
    AnimatedLabel* create_button(QString icon_path, QString legend, int size);

    bool check_coor(qreal lon, qreal lat);

private slots:
    void mouse_move_on_map(QString string);
    void zoom_map(int zoom);
    void closeEvent(QCloseEvent* event);
    void on_pushButton_input();
    void on_pushButton_settings();
    void set_map_settings(QString map_theme, int projection);
    void recive_blast_data_from_input_window(BlastMath _blast);
    void on_click_coor_button_in_input_window();
    void get_coordibates_from_map(qreal lon,qreal lat,GeoDataCoordinates::Unit);


signals:
    void send_coor_to_input_window(qreal lon, qreal lat);


};
#endif // MAINWINDOW_H
