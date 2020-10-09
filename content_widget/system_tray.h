#pragma once

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QWidgetAction>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QPainter>

class system_tray : public QSystemTrayIcon
{
	Q_OBJECT

public:

	explicit system_tray(QWidget* parent = 0);
	~system_tray();
	void translateLanguage();

protected:

	bool eventFilter(QObject* obj, QEvent* event);

signals:
	void showWidget();

private:
	void createTopAction();
	void createBottomAction();
	void createAction();
	void addActions();

private:
	QMenu* tray_menu; //���̲˵�

	QWidget* top_widget;  //�����˵���
	QWidgetAction* top_widget_action;  //����ģʽ����һ�ס�����/��ͣ����һ��
	QLabel* protect_label;  //360�ѱ�������...��
	QPushButton* open_button;  //ľ�����ǽ�Ѿ�����
	QPushButton* enter_button;  //����

	QWidget* bottom_widget;  //�ײ��˵���
	QWidgetAction* bottom_widget_action;  //����ģʽ����һ�ס�����/��ͣ����һ��
	QPushButton* game_mode_button;  //������Ϸģʽ
	QPushButton* online_mode_button;  //��������ģʽ

	QAction* action_open; //��360��ȫ��ʿ
	QAction* action_help_center; //��������
	QAction* action_kill_mummy; //��ɱľ��
	QAction* action_clear; //��������
	QAction* action_optimize; //һ���Ż�
	QAction* action_fireproof; //������
	QAction* action_show_speed; //��ʾ������
	QAction* action_soft_manage; //����ܼ�
	QAction* action_safe_notice; //��ȫ֪ͨ
	QAction* action_rise; //����
	QAction* action_login; //360�û���¼
	QAction* action_separate; //����ɳ��
	QAction* action_logout; //�˳�

};
