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
	QAction* action_setting; //设置
	QAction* action_new_character; //新版特性
	QAction* action_check_update; //检查更新
	QAction* action_change_company; //切换为企业版
	QAction* action_help_online; //在线帮助
	QAction* action_platform_help; //论坛求助
	QAction* action_login_home; //360网站
	QAction* action_protect; //隐私保护
	QAction* action_about_us; //关于我们

};
