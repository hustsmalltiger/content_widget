#include "drop_shadow_widget.h"

drop_shadow_widget::drop_shadow_widget(QWidget* parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	setAttribute(Qt::WA_TranslucentBackground);

	//初始化为未按下鼠标左键
	mouse_press = false;
}

drop_shadow_widget::~drop_shadow_widget()
{

}

void drop_shadow_widget::paintEvent(QPaintEvent*)
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(10, 10, this->width() - 20, this->height() - 20);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for (int i = 0; i < 10; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(10 - i, 10 - i, this->width() - (10 - i) * 2, this->height() - (10 - i) * 2);
        color.setAlpha(150 - qSqrt(i) * 50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void drop_shadow_widget::mousePressEvent(QMouseEvent* event)
{
    //只能是鼠标左键移动和改变大小
    if (event->button() == Qt::LeftButton)
    {
        mouse_press = true;
    }

    //窗口移动距离
    move_point = event->globalPos() - pos();
}

void drop_shadow_widget::mouseReleaseEvent(QMouseEvent*)
{
    mouse_press = false;
}

void drop_shadow_widget::mouseMoveEvent(QMouseEvent* event)
{
    //移动窗口
    if (mouse_press)
    {
        QPoint move_pos = event->globalPos();
        move(move_pos - move_point);
    }
}
