#pragma once

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "common.h"
#include "push_button.h"
#include "drop_shadow_widget.h"

class msg_box : public drop_shadow_widget
{
	Q_OBJECT

public:
	explicit msg_box(QWidget* parent = 0);
	~msg_box();
	void translateLanguage();
	void setInfo(QString title_info, QString info, QPixmap pixmap, bool is_ok_hidden);

signals:
	void okMessageHidden(bool is_checked);
	void msgChecked(bool is_checked, bool is_ok);

private slots:
	void okOperate();
	void cancelOperate();

protected:
	void paintEvent(QPaintEvent* event);

private:
	QLabel* title_label;
	QLabel* title_icon_label;
	QLabel* msg_label; //��ʾͼƬ
	QLabel* ask_label; //��ʾ��Ϣ
	push_button* close_button; //��ʾ���ϵĹرհ�ť
	QPushButton* ok_button; //���ذ�ť
	QPushButton* cancel_button; //ȡ����ť

	QString ok_text;
	QString cancel_text;

};