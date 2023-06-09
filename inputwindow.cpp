#include "inputwindow.h"
#include "ui_inputwindow.h"

InputWindow::InputWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InputWindow)
{
    ui->setupUi(this);
    ui->frame_4->hide();
    blast = BlastMath();
    qreal q = ui->comboBox_q->currentText().toDouble();
    init_weather_tableWidjet(ui->tableWidget_weater, blast.get_zone_id_for_q(q), blast.get_max_v_wind_index(q));
    create_button_enter(create_button(":/new/prefix1/icons/add.gif","Нажмите для добавления текущих параметров",64,ui->lay_enter));
    create_button_coor(create_button(":/new/prefix1/icons/coor.gif","Нажмите для выбора на карте координат взрыва",64,ui->lay_coor));
    create_button_coor_work(create_button(":/new/prefix1/icons/coor.gif","Нажмите для выбора на карте координат места работ л/с",64,ui->lay_coor_work));
    set_dateTime(ui->dateTimeEdit);
}

InputWindow::~InputWindow()
{
    delete ui;
}

QComboBox* InputWindow::get_window_v_comboBox(int max_v_wind_index)
{
    QComboBox *comboBox = new QComboBox();
    QStringList wind_v_list;
    wind_v_list << "10" << "25" << "50" << "75" << "100";
    for (int i=0;i<=max_v_wind_index;i++) {
        comboBox->addItem(wind_v_list[i]);
    }
    return comboBox;
}

QDoubleSpinBox* InputWindow::get_alfa_doubleSpinBox()
{
    QDoubleSpinBox* doubleSpinBox = new QDoubleSpinBox();
    doubleSpinBox->setMaximum(359);
    doubleSpinBox->setMinimum(0);
    doubleSpinBox->setSingleStep(10);
    return doubleSpinBox;
}

qreal InputWindow::get_value_from_cell_widget(QWidget *widget)
{
    if (QComboBox* comboBox = qobject_cast<QComboBox*>(widget)) {
        return comboBox->currentText().toDouble();
    }
    else if (QDoubleSpinBox* doubleSpinBox = qobject_cast<QDoubleSpinBox*>(widget)) {
        return doubleSpinBox->value();
    }
    else return qreal(0);
}

void InputWindow::resize_table(QTableWidget *tableWidget)
{
    tableWidget->horizontalHeader()->resizeContentsPrecision();
    tableWidget->verticalHeader()->resizeContentsPrecision();
    tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void InputWindow::set_dateTime(QDateTimeEdit *&edit)
{
    edit->setDateTime(QDateTime::currentDateTime());
    blast.date_time=edit->dateTime();
}

AnimatedLabel *InputWindow::create_button(QString icon_path, QString legend, int size, QGridLayout*& lay)
{
    AnimatedLabel* button = new AnimatedLabel(this, icon_path, legend, size, size);
    lay->addWidget(button);
    return button;
}

void InputWindow::create_button_enter(AnimatedLabel *button)
{
    connect(button, SIGNAL(clicked()), SLOT(on_pushButton_enter()));
}

void InputWindow::create_button_coor(AnimatedLabel *button)
{
    connect(button, SIGNAL(clicked()), SLOT(on_pushButton_coor()));
}

void InputWindow::create_button_coor_work(AnimatedLabel *button)
{
    connect(button, SIGNAL(clicked()), SLOT(on_pushButton_coor_work()));
}

void InputWindow::set_max_q(Type type, QComboBox *&comboBox)
{
    QStringList normal_q_range;
    normal_q_range<<"0.1"<<"0.2"<<"0.5"<<"1"<<"2"<<"5"<<"10"<<"20"<<"50"<<"100"<<"200"<<"500"<<"1000"<<"2000"<<"5000"<<"10000";
    comboBox->clear();
    comboBox->addItems(normal_q_range);
    if (type==Underwather || type==Underground) {
        comboBox->clear();
        comboBox->addItems(normal_q_range.mid(0,10));
    }
}

QList<QList<qreal> > InputWindow::get_values_from_tableWidget(QTableWidget *&tableWidget)
{
    QList <QList<qreal>> row_list;
    for (int i=0;i<tableWidget->rowCount();i++) {
        QList <qreal> column_list;
        for (int j = 0;j<tableWidget->columnCount();++j) {
           qreal value = get_value_from_cell_widget(tableWidget->cellWidget(i, j));
           column_list.append(value);
        }
        row_list.append(column_list);
    }
    return row_list;
}

bool InputWindow::check_coor(qreal lon, qreal lat, QString header, QString message)
{
    if ((lon!=-1) && (lat!=-1)) return true;
    QMessageBox *msgBox = new QMessageBox(QMessageBox::Warning,
                                          header,
                                          message,
                                          QMessageBox::Yes| QMessageBox::No);
    if(msgBox->exec() == QMessageBox::Yes)
    {
        return true;
    }
    delete msgBox;
    return false;
}

void InputWindow::set_coor_in_ui(qreal lon, qreal lat, QDoubleSpinBox *&lon_spin, QDoubleSpinBox *&lat_spin)
{
    lon_spin->setValue(lon*57.3);
    lat_spin->setValue(lat*57.3);
}

void InputWindow::on_comboBox_type_currentIndexChanged(int index)
{
    qDebug()<<index;
    blast.type = blast.set_type(index);
    set_max_q(blast.type, ui->comboBox_q);
}

void InputWindow::on_pushButton_enter()
{
    if (!check_coor(blast.lon, blast.lat, "Ввод координат взрыва", "Координаты взрыва не заданы. Вы действительно хотите продолжить?")) return;
    if (!check_coor(blast.work_lon, blast.work_lat, "Ввод координат ЗРП", "Координаты ЗРП не заданы. Вы действительно хотите продолжить?")) return;
    QList<QList<qreal>> value_list = get_values_from_tableWidget(ui->tableWidget_weater);
    blast.set_blast_params(ui->comboBox_type->currentIndex(),
                           ui->comboBox_q->currentText().toDouble(),
                           ui->dateTimeEdit->dateTime(),
                           value_list[0][value_list[0].size()-1],
                           360-value_list[1][value_list[1].size()-1]);
    blast.set_work_params(ui->spinBox_t_enter->value(),
                          ui->spinBox_T_work->value(),
                          ui->spinBox_D_before->value(),
                          ui->spinBox_N_count->value(),
                          ui->spinBox_D_cloud->value(),
                          ui->spinBox_D_ground->value(),
                          ui->spinBox_t_delta_nuclear->value(),
                          ui->spinBox_A_air->value());
    emit send_blast_data(blast);
    this->close();
}

void InputWindow::on_pushButton_coor()
{
    send_button = "coor";
    emit coor_button_push();
    this->hide();
}

void InputWindow::on_pushButton_coor_work()
{
    send_button = "work_coor";
    emit coor_button_push();
    this->hide();
}

void InputWindow::on_comboBox_q_currentTextChanged(const QString &arg1)
{
    qreal q = arg1.toDouble();
    init_weather_tableWidjet(ui->tableWidget_weater, blast.get_zone_id_for_q(q), blast.get_max_v_wind_index(q));
}

void InputWindow::init_weather_tableWidjet(QTableWidget *&tableWidget, int column, int max_v_wind_index)
{
    QStringList weather_horiz_header;
    weather_horiz_header<<"0-1,5"<<"0-3"<<"0-6"<<"0-12"<<"0-18";
    QStringList weather_vert_header;
    weather_vert_header<<"Vh, км/ч (Скорость ветра)"<<"α, ° (Направление ветра)";
    tableWidget->setRowCount(2);
    tableWidget->setColumnCount(column+1);
    tableWidget->setHorizontalHeaderLabels(weather_horiz_header);
    tableWidget->setVerticalHeaderLabels(weather_vert_header);
    for (int j=0;j<tableWidget->columnCount();j++) {
        tableWidget->setCellWidget(0, j, get_window_v_comboBox(max_v_wind_index));
        tableWidget->setCellWidget(1, j, get_alfa_doubleSpinBox());
    }
    resize_table(tableWidget);
}

void InputWindow::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    blast.date_time=dateTime;
}

void InputWindow::recive_coor_from_mainwidnow(qreal lon, qreal lat)
{
    if (send_button=="coor") {
        blast.lon=lon;
        blast.lat=lat;
        set_coor_in_ui(lon, lat, ui->doubleSpinBox_lon, ui->doubleSpinBox_lat);
        QList<QList<qreal>> value_list = get_values_from_tableWidget(ui->tableWidget_weater);
        blast.set_blast_params(ui->comboBox_type->currentIndex(),
                               ui->comboBox_q->currentText().toDouble(),
                               ui->dateTimeEdit->dateTime(),
                               value_list[0][value_list[0].size()-1],
                               360-value_list[1][value_list[1].size()-1]);
        emit send_blast_data(blast);
    }
    if (send_button=="work_coor") {
        blast.work_lon=lon;
        blast.work_lat=lat;
        set_coor_in_ui(lon, lat, ui->doubleSpinBox_lon_work, ui->doubleSpinBox_lat_work);
    }
}


void InputWindow::on_spinBox_t_enter_valueChanged(int arg1)
{
//    if (show_t_enter_warning) return;
//    if (arg1>4) {
//        QMessageBox::information(this,"Информация","Рекомендуемое значение времени входа для корректных вычислений от 1 до 4 часов");
//        show_t_enter_warning=true;
//    }
}

void InputWindow::on_spinBox_T_work_valueChanged(int arg1)
{
    if (show_t_work_warning) return;
    if (arg1>96) {
        QMessageBox::information(this,"Информация","Рекомендуемое значение продолжительности работ для корректных вычислений от 1 до 96 (4 сут.) часов");
        show_t_enter_warning=true;
    }
}
