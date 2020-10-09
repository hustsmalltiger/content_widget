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
	QLabel* title_label; //����
	QLabel* title_icon_label; //����ͼ��
	QLabel* title_info_label; //360��ȫ��ʿ
	QLabel* info_label; //ɱľ�������š����Լ���
	QLabel* version_label; //������汾
	QLabel* mummy_label; //����ľ���
	QLabel* copyright_label; //�汾��Ϣ
	QLabel* icon_label; //ͼ��
	push_button* close_button; //�رհ�ť
	QPushButton* ok_button; //ȷ����ť
};
