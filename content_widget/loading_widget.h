#pragma once

#include <QWidget>
#include <QLabel>  
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include "util.h"

class loading_widget : public QWidget
{
	Q_OBJECT

public:
	explicit loading_widget(QWidget* parent = 0);
	~loading_widget();
	void translateLanguage();
	void start(bool is_start);
	void setAccount(QString account);

private slots:
	void updatePixmap();

private:
	QLabel* loading_label;  //加载等待图标
	QLabel* account_label;  //账号名称
	QLabel* waiting_label;  //正在加载
	QTimer* timer; //定时器，变化图标
	int index; //图标下标值
	QString account; //账号名

};
