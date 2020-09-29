#include "push_button.h"

push_button::push_button(QWidget* parent)
	: QPushButton(parent)
{
	//初始化状态
	status = NORMAL;
	mouse_press = false;
}


push_button::~push_button()
{

}


void push_button::setPicName(QString pic_name)
{
	this->pic_name = pic_name;
	setFixedSize(QPixmap(pic_name).size());//以图片pic_name的大小设置窗体大小
}


void push_button::enterEvent(QEvent*)
{
	status = ENTER;
	//当窗口程序需要升级或者重新绘制时,调用此成员函数.使用 repaint()和 update() 后，调用函数 paintEvent()。
	update();
}


void push_button::leaveEvent(QEvent*)
{
	status = NORMAL;
	update();
}


void push_button::mousePressEvent(QMouseEvent* event)
{
	//点击鼠标左键
	if (event->button() == Qt::LeftButton)
	{
		mouse_press = true;
		status = PRESS;
		update();
	}
}

void push_button::mouseReleaseEvent(QMouseEvent* event)
{
	//若已经点击,则将它处理为仅在这个图标上放的，也就是enter状态
	if (mouse_press && this->rect().contains(event->pos()))
	{
		mouse_press = false;
		status = ENTER;
		update();
		emit clicked();
	}
}


void push_button::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QPixmap pixmap;
	switch (status)
	{
	case NORMAL:
		{
			pixmap.load(pic_name); //加载图片
			break;
		}
	case ENTER:
		{
			pixmap.load(pic_name + QString("_hover"));
			break;
		}
	case PRESS:
		{
			pixmap.load(pic_name + QString("_pressed"));
			break;
		}
	case NOSTATUS:
		{
			pixmap.load(pic_name);
			break;
		}
	default:
		pixmap.load(pic_name);
	}

	painter.drawPixmap(rect(), pixmap);		//Rect()指的是当前窗体的显示区域

}

