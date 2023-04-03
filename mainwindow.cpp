#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame_pane->hide();
    create_button_input(create_button(":/new/prefix1/icons/edit.gif","Нажмите для ввода исходных данных",64));
    create_button_settings(create_button(":/new/prefix1/icons/settings.gif","Нажмите для изменения параметров отображения карты",64));
    load_map(ui->map_lay,"earth/plain/plain.dgml",0);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    delete map;
    delete this;
}

void MainWindow::on_pushButton_input()
{
    inputwin = new InputWindow(this);
    show_window(inputwin);
    connect(inputwin, SIGNAL(send_blast_data(BlastMath)), this, SLOT(recive_blast_data_from_input_window(BlastMath)));
    connect(inputwin, SIGNAL(coor_button_push()), this, SLOT(on_click_coor_button_in_input_window()));
    connect(this, SIGNAL(send_coor_to_input_window(qreal, qreal)), inputwin, SLOT(recive_coor_from_mainwidnow(qreal, qreal)));
}

void MainWindow::on_pushButton_settings()
{
    settingswin = new SettingsWindow(this, map->mapThemeId(), map->projection());
    connect(settingswin,SIGNAL(send_map_settings(QString, int)),this,SLOT(set_map_settings(QString, int)));
    show_window(settingswin);
}

void MainWindow::set_map_settings(QString map_theme, int projection)
{
    delete map;
    load_map(ui->map_lay, map_theme, projection);
    //    send_data_in_layer(current_planes, current_airbases,line_atack);
}

void MainWindow::recive_blast_data_from_input_window(BlastMath _blast)
{
    blast = _blast;
    if (blast.ellipse_list.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", QString("Для выбранного значения q=%1 не существует табличного значения. Выберите значение больше.").arg(blast.q));
        return;
    }
    blast.work_math();
    qDebug()<<"danger_zone_index"<<blast.danger_zone_index;
    if ((blast.danger_zone_index==-1) && check_coor(blast.work_lon, blast.work_lon)) {
        QMessageBox::warning(this, "Внимание", "Точка стояния ЗРП находится вне зоны поражения ядерного взрыва.");
    }
    layer->blast=blast;
    if (check_coor(blast.lon, blast.lat)) layer->draw_zone=true;
    if (check_coor(blast.work_lon, blast.work_lon)) layer->draw_regimen=true;
}

void MainWindow::on_click_coor_button_in_input_window()
{
    connect(map,SIGNAL(mouseClickGeoPosition(qreal,qreal,GeoDataCoordinates::Unit)),this,SLOT(get_coordibates_from_map(qreal,qreal,GeoDataCoordinates::Unit)));
}

void MainWindow::get_coordibates_from_map(qreal lon, qreal lat, GeoDataCoordinates::Unit)
{
    GeoDataCoordinates coor(lon,lat,GeoDataCoordinates::Radian);
    QMessageBox *msgBox = new QMessageBox(QMessageBox::Information,
                                          "Сохранение",
                                          QString("Выбраны координаты\nдолгота: %1°\nширота: %2°.\nДля повторного выбора нажмите нет.").arg(coor.longitude()*57.3).arg(coor.latitude()*57.3),
                                          QMessageBox::Yes| QMessageBox::No);
    if(msgBox->exec() == QMessageBox::Yes)
    {
        disconnect(map,SIGNAL(mouseClickGeoPosition(qreal,qreal,GeoDataCoordinates::Unit)),this,SLOT(get_coordibates_from_map(qreal,qreal,GeoDataCoordinates::Unit)));
        emit send_coor_to_input_window(coor.longitude(), coor.latitude());
        inputwin->show();
    }
    delete msgBox;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_window(QMainWindow *window)
{
    window->setWindowModality(Qt::WindowModal);
    window->show();
}

void MainWindow::load_map(QGridLayout *&lay, QString map_theme, int projection)
{
    map=new MarbleWidget();
    map->setMapThemeId(map_theme);
    map->setShowCrosshairs(false);
    foreach(AbstractFloatItem *floatItem, map->floatItems())
        floatItem->hide();
    foreach(RenderPlugin* plugin, map->renderPlugins())
        if(plugin->nameId() == "stars") plugin->setEnabled(false);
    map->setShowCities(true);
    map->zoomView(1500);
    layer = new MapLayer(map->zoom(), map->maximumZoom(), map->minimumZoom());
    map->addLayer(layer);
    lay->addWidget(map);
    map->centerOn(GeoDataCoordinates(37.61/57.3,55.75/57.3,GeoDataCoordinates::Radian));
    map->setProjection(projection);

    map->update();
    connect(map,SIGNAL(mouseMoveGeoPosition(QString)),SLOT(mouse_move_on_map(QString)));
    connect(map,SIGNAL(zoomChanged(int)),this,SLOT(zoom_map(int)));
}

void MainWindow::create_button_input(AnimatedLabel* button)
{
    connect(button, SIGNAL(clicked()), SLOT(on_pushButton_input()));
}

void MainWindow::create_button_settings(AnimatedLabel *button)
{
    connect(button, SIGNAL(clicked()), SLOT(on_pushButton_settings()));
}

AnimatedLabel* MainWindow::create_button(QString icon_path, QString legend, int size)
{
    AnimatedLabel* button = new AnimatedLabel(this, icon_path, legend, size, size);
    ui->mainToolBar->addWidget(button);
    return button;
}

bool MainWindow::check_coor(qreal lon, qreal lat)
{
    if ((lon!=-1) && (lat!=-1)) return true;
    return false;
}

void MainWindow::mouse_move_on_map(QString string)
{
    if (string!="not available")
    {
        ui->statusbar->showMessage(QString("%1").arg(string));
    }
    else ui->statusbar->clearMessage();
}

void MainWindow::zoom_map(int zoom)
{
    layer->zoom = zoom;
    map->update();
}
