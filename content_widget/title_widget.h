#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QSignalMapper>
#include "tool_button.h"
#include "push_button.h"


class title_widget : public QWidget
{
	Q_OBJECT

public:
	title_widget(QWidget* parent = 0);
	~title_widget();
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
	QPoint press_point;        //鼠标按下去的点
	bool is_move;

	QLabel* version_title;     //标题
	push_button* medal_button; //勋章墙
	push_button* skin_button;  //换肤
	push_button* main_menu_button;//设置
	push_button* min_button;   //最小化   
	push_button* feedback_button;//反馈建议
	push_button* close_button; //关闭

	QLabel* safe_360_label;    //360安全卫士
	QLabel* safe_label;        //360安全卫士

	QList<tool_button*> button_list;
};