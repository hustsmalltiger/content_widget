#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_content_widget.h"

class content_widget : public QMainWindow
{
    Q_OBJECT

public:
    content_widget(QWidget *parent = Q_NULLPTR);

private:
    Ui::content_widgetClass ui;
};
