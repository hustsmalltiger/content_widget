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
	QLabel* loading_label;  //���صȴ�ͼ��
	QLabel* account_label;  //�˺�����
	QLabel* waiting_label;  //���ڼ���
	QTimer* timer; //��ʱ�����仯ͼ��
	int index; //ͼ���±�ֵ
	QString account; //�˺���

};
