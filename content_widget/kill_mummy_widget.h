#pragma once

#include <QWidget>
#include <QLabel>
#include <QToolButton>
#include <QHBoxLayout>

class kill_mummy_widget : public QWidget
{
	Q_OBJECT

public:
	explicit kill_mummy_widget(QWidget* parent = 0);
	~kill_mummy_widget();
	void translateLanguage();

private:
	QLabel* tip_icon_label;  //��ʾͼ��
	QLabel* tip_info_label;  //��ʾ��Ϣ
	QLabel* tip_suggest_label;  //������Ϣ
	QToolButton* fast_scan_button; //����ɨ��
	QToolButton* full_scan_button; //ȫ��ɨ��
	QToolButton* custom_scan_button; //�Զ���ɨ��
};
