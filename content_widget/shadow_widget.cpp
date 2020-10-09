#include "shadow_widget.h"

shadow_widget::shadow_widget(QWidget* parent)
    : QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);
}

shadow_widget::~shadow_widget()
{

}

void shadow_widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    this->drawWindowShadow(painter);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width() - 2 * SHADOW_WIDTH, this->height() - 2 * SHADOW_WIDTH));
}

void shadow_widget::drawWindowShadow(QPainter& painter)
{
    //绘制左上角、左下角、右上角、右下角、上、下、左、右边框
    QList<QPixmap> pixmaps;
    pixmaps.append(QPixmap("./Resources/img/shadow/shadow_left.png"));
    pixmaps.append(QPixmap("./Resources/img/shadow/shadow_right.png"));
    pixmaps.append(QPixmap("./Resources/img/shadow/shadow_top.png"));
    pixmaps.append(QPixmap("./Resources/img/shadow/shadow_bottom.png"));
    pixmaps.append(QPixmap("./Resources/img/shadow/shadow_left_top.png"));
    pixmaps.append(QPixmap("./Resources/img/shadow/shadow_right_top.png"));
    pixmaps.append(QPixmap("./Resources/img/shadow/shadow_left_bottom.png"));
    pixmaps.append(QPixmap("./Resources/img/shadow/shadow_right_bottom.png"));

    painter.drawPixmap(0, 0, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[4]);
    painter.drawPixmap(this->width() - SHADOW_WIDTH, 0, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[5]);
    painter.drawPixmap(0, this->height() - SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[6]);
    painter.drawPixmap(this->width() - SHADOW_WIDTH, this->height() - SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[7]);
    painter.drawPixmap(0, SHADOW_WIDTH, SHADOW_WIDTH, this->height() - 2 * SHADOW_WIDTH, pixmaps[0].scaled(SHADOW_WIDTH, this->height() - 2 * SHADOW_WIDTH));
    painter.drawPixmap(this->width() - SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, this->height() - 2 * SHADOW_WIDTH, pixmaps[1].scaled(SHADOW_WIDTH, this->height() - 2 * SHADOW_WIDTH));
    painter.drawPixmap(SHADOW_WIDTH, 0, this->width() - 2 * SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[2].scaled(this->width() - 2 * SHADOW_WIDTH, SHADOW_WIDTH));
    painter.drawPixmap(SHADOW_WIDTH, this->height() - SHADOW_WIDTH, this->width() - 2 * SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[3].scaled(this->width() - 2 * SHADOW_WIDTH, SHADOW_WIDTH));
}
