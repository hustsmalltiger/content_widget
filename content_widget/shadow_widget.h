#pragma once

#include <QDialog>
#include <QPainter>
#include "common.h"

class shadow_widget : public QDialog
{
	Q_OBJECT

public:

	explicit shadow_widget(QWidget* parent = 0);
	~shadow_widget();

protected:

	virtual void paintEvent(QPaintEvent* event);

private:

	void drawWindowShadow(QPainter& painter);

};
