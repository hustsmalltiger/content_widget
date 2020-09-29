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
	QPoint press_point;        //��갴��ȥ�ĵ�
	bool is_move;

	QLabel* version_title;     //����
	push_button* medal_button; //ѫ��ǽ
	push_button* skin_button;  //����
	push_button* main_menu_button;//����
	push_button* min_button;   //��С��   
	push_button* feedback_button;//��������
	push_button* close_button; //�ر�

	QLabel* safe_360_label;    //360��ȫ��ʿ
	QLabel* safe_label;        //360��ȫ��ʿ

	QList<tool_button*> button_list;
};