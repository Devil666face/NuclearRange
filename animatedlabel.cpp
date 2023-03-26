#include "animatedlabel.h"

AnimatedLabel::AnimatedLabel(QWidget *parent, QString path_to_gif, QString whats_this, int minw, int minh) : QLabel(parent)
{
    this->setMinimumSize(minw,minh);
    this->setMaximumSize(minw,minh);
    movie = new QMovie(path_to_gif);
    this->setMovie(movie);
    this->setStyleSheet(no_push_style);
    this->setScaledContents(true);
    this->setCursor(Qt::PointingHandCursor);
    this->setMouseTracking(true);
    Filter* filter_start_stop = new Filter(this);
    this->installEventFilter(filter_start_stop);
    this->setStatusTip(whats_this);
    connect(filter_start_stop,SIGNAL(start_movie_signal()),this,SLOT(start_movie()));
    connect(filter_start_stop,SIGNAL(stop_movie_signal()),this,SLOT(stop_movie()));
    movie->start();
    movie->stop();
}

void AnimatedLabel::start_movie()
{
    movie->start();
    this->setStyleSheet(push_style);
}

void AnimatedLabel::stop_movie()
{
    movie->stop();
    movie->start();
    movie->stop();
    this->setStyleSheet(no_push_style);
    this->setFrameShape(WinPanel);
}

void AnimatedLabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

bool Filter::eventFilter(QObject *obj, QEvent *e)
{
      if (!obj->isWidgetType()) return true;
      QWidget* w = (QWidget*) obj;
      if (e->type() == QEvent::Enter) {
            emit start_movie_signal();
      }
      else if (e->type() == QEvent::Leave) {
            emit stop_movie_signal();
      }
      return false;
}
