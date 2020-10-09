#pragma once

#include <QDialog>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>

class drop_shadow_widget : public QDialog
{
	Q_OBJECT

public:
	explicit drop_shadow_widget(QWidget* parent = 0);
	~drop_shadow_widget();

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	virtual void paintEvent(QPaintEvent* event);

private:
	QPoint move_point; //移动的距离
	bool mouse_press; //按下鼠标左键

};