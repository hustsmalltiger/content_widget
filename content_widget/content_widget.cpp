#include "content_widget.h"
/*
content_widget::content_widget(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}
*/


content_widget::content_widget(QWidget* parent)
    : QWidget(parent)
{
    //��ʼ��
    setAttribute(Qt::WA_TranslucentBackground);
}