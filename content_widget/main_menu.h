#pragma once

#include <QMenu>
#include <QDesktopServices>
#include <QUrl>
#include "common.h"

class main_menu : public QMenu
{
	Q_OBJECT

public:
	explicit main_menu(QWidget* parent = 0);
	void translateActions();

signals:
	void showSettingDialog();
	void showNewCharacter();
	void showAboutUs();

private slots:
	void showPage();

private:
	void createActions();

private:
	QAction* action_setting; //����
	QAction* action_new_character; //�°�����
	QAction* action_check_update; //������
	QAction* action_change_company; //�л�Ϊ��ҵ��
	QAction* action_help_online; //���߰���
	QAction* action_platform_help; //��̳����
	QAction* action_login_home; //360��վ
	QAction* action_protect; //��˽����
	QAction* action_about_us; //��������

};
