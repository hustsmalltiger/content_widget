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

	void enterEvent(QEvent *);						//进入事件
	void leaveEvent(QEvent *);						//离开事件
	void mousePressEvent(QMouseEvent* event);		//鼠标按下事件
	void mouseReleaseEvent(QMouseEvent* event);		//鼠标释放事件
	void paintEvent(QPaintEvent*);					//绘制事件
private:

	//枚举按钮的几种状态
	enum ButtonStatus { NORMAL, ENTER, PRESS, NOSTATUS };
	ButtonStatus status;
	QString pic_name;

	int btn_width;			//按钮宽度
	int btn_height;			//按钮高度
	int mouse_press;		//按钮左键是否按下

};