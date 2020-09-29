#include "push_button.h"

push_button::push_button(QWidget* parent)
	: QPushButton(parent)
{
	//��ʼ��״̬
	status = NORMAL;
	mouse_press = false;
}


push_button::~push_button()
{

}


void push_button::setPicName(QString pic_name)
{
	this->pic_name = pic_name;
	setFixedSize(QPixmap(pic_name).size());//��ͼƬpic_name�Ĵ�С���ô����С
}


void push_button::enterEvent(QEvent*)
{
	status = ENTER;
	//�����ڳ�����Ҫ�����������»���ʱ,���ô˳�Ա����.ʹ�� repaint()�� update() �󣬵��ú��� paintEvent()��
	update();
}


void push_button::leaveEvent(QEvent*)
{
	status = NORMAL;
	update();
}


void push_button::mousePressEvent(QMouseEvent* event)
{
	//���������
	if (event->button() == Qt::LeftButton)
	{
		mouse_press = true;
		status = PRESS;
		update();
	}
}

void push_button::mouseReleaseEvent(QMouseEvent* event)
{
	//���Ѿ����,��������Ϊ�������ͼ���Ϸŵģ�Ҳ����enter״̬
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
			pixmap.load(pic_name); //����ͼƬ
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

	painter.drawPixmap(rect(), pixmap);		//Rect()ָ���ǵ�ǰ�������ʾ����

}

