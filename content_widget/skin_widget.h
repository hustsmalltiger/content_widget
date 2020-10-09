#pragma once

#include <QWidget>
#include <QSignalMapper>
#include "common.h"
#include "push_button.h"
#include "change_skin_widget.h"
#include "drop_shadow_widget.h"

class skin_widget : public drop_shadow_widget 
{
	Q_OBJECT

public:
	explicit skin_widget(QWidget* parent = 0);
	~skin_widget();
	void translateLanguage();

protected:
	void paintEvent(QPaintEvent* event);

signals:
	void changeSkin(QString skin_name);

private slots:
	void showSkin(QString page_count);
	void varyfySkin();

private:
	void initTitle();
	void initCenter();
	void initBottom();

private:
	QString skin_name; //����ͼƬ
	bool is_change; //�Ƿ�ı䱳��
	QStringList skin_list;
	QStringList tip_list;

	QHBoxLayout* title_layout;
	QGridLayout* center_layout;
	QHBoxLayout* bottom_layout;

	QLabel* title_label; //����
	QLabel* title_icon_label; //����ͼ��
	push_button* close_button; //�رհ�ť
	int page_count; //��ҳ��
	int page_count_point; //���һҳ����ʾ����
	int current_page; //��ǰΪ�ڼ�ҳ

	QPushButton* first_page_button;
	QPushButton* previous_page_button;
	QPushButton* next_page_button;
	QPushButton* last_page_button;

	QList<change_skin_widget*> change_skin_list;
};

