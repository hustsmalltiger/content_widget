#pragma once

#include <QtWidgets/QPushButton>
#include <QtGui/QPainter>
#include <QtGui/QMouseEvent>

class push_button : public QPushButton
{
	Q_OBJECT

public:
	push_button(QWidget *parent = 0);
	~push_button();
	void setPicName(QString pic_name);
protected:

	void enterEvent(QEvent *);						//�����¼�
	void leaveEvent(QEvent *);						//�뿪�¼�
	void mousePressEvent(QMouseEvent* event);		//��갴���¼�
	void mouseReleaseEvent(QMouseEvent* event);		//����ͷ��¼�
	void paintEvent(QPaintEvent*);					//�����¼�
private:

	//ö�ٰ�ť�ļ���״̬
	enum ButtonStatus { NORMAL, ENTER, PRESS, NOSTATUS };
	ButtonStatus status;
	QString pic_name;

	int btn_width;			//��ť���
	int btn_height;			//��ť�߶�
	int mouse_press;		//��ť����Ƿ���

};