#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel.h>

#include "ui_content_widget.h"

class content_widget : public QMainWindow
{
    Q_OBJECT

public:
    content_widget(QWidget *parent = Q_NULLPTR);
    ~content_widget();
    void translateLanguage();

signals:

    void showSkin();
    void showMin();
    void showMainMenu();
    void closeWidget();
    void turnPage(int current_page);

public slots:
    void turnPage(QString current_page);

private:
    Ui::content_widgetClass ui;

    QPoint press_point;  //鼠标按下去的点
    bool is_move;

    QLabel* version_title; //标题
    
};
