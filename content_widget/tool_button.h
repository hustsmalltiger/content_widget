#pragma once
#include <QtWidgets/QToolButton>
#include <QtGui/QPainter>
#include <QtGui/QMouseEvent>

class tool_button : public QToolButton
{
	Q_OBJECT

public:
	tool_button(QString pic_name, QWidget *parent = 0);
	~tool_button();
	void setMousePress(bool mouse_press);

protected:
	void enterEvent(QEvent*);
	void leaveEvent(QEvent*);
	void mousePressEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent* event);
	void painterInfo(int top_color, int middle_color, int bottom_color);

public:
	bool mouse_over; //鼠标是否移过
	bool mouse_press; //鼠标是否按下
};