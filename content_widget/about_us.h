#pragma once

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include "common.h"
#include "push_button.h"
#include "drop_shadow_widget.h"

class about_us_dialog : public drop_shadow_widget
{
	Q_OBJECT

public:
	explicit about_us_dialog(QWidget* parent = 0);
	~about_us_dialog();
	void translateLanguage();

protected:
	void paintEvent(QPaintEvent* event);

private:
	void init();

private:
	QLabel* title_label; //标题
	QLabel* title_icon_label; //标题图标
	QLabel* title_info_label; //360安全卫士
	QLabel* info_label; //杀木马、防盗号、电脑加速
	QLabel* version_label; //主程序版本
	QLabel* mummy_label; //备用木马库
	QLabel* copyright_label; //版本信息
	QLabel* icon_label; //图标
	push_button* close_button; //关闭按钮
	QPushButton* ok_button; //确定按钮
};
