#pragma once

#include <QWidget>
#include <QDesktopWidget>
#include <QTranslator>
#include <QtNetwork/QLocalSocket>
#include <QtNetwork/QLocalServer>
#include "shadow_widget.h"
#include "title_widget.h"
#include "content_widget.h"
#include "system_tray.h"
#include "about_us.h"
#include "main_menu.h"
#include "character_widget.h"
#include "setting_dialog.h"
#include "skin_widget.h"
#include "login_dialog.h"
#include "register_widget.h"
#include "drop_shadow_widget.h"
#include "kill_mummy_widget.h"
#include <QStackedWidget>


class main_widget : public drop_shadow_widget
{
	Q_OBJECT

public:

	main_widget(QWidget* parent = 0);
	~main_widget();
	void setTranslator(QTranslator* translator);
	bool isRunning();

protected:

	virtual void paintEvent(QPaintEvent* event);

public slots:

	void showWidget();

private slots:

	void newLocalConnection();

	void showSkinWidget();
	void showMainMenu();
	void showSettingDialog();
	void showAboutUs();
	void showNewCharacter();
	void showLoginDialog();
	void showRegisterDialog();
	void changeSkin(QString skin_name);
	void iconIsActived(QSystemTrayIcon::ActivationReason reason);
	void changeLanguage(LANGUAGE language);

	void turnPage(int current_page);

private:

	void initLocalConnection();

private:
	QStackedWidget* statked_widget;
	title_widget* m_title_widget; //标题栏,重名改为"m_"+"变量名"
	content_widget* m_content_widget; //主界面内容
	kill_mummy_widget* m_kill_mummy_widget;  //查杀木马界面
	system_tray* m_system_tray; //托盘项
	setting_dialog* m_setting_dialog; //设置界面
	character_widget* m_character_widget; //新版特性界面
	about_us_dialog* m_about_us_dialog; //关于我们界面
	login_dialog* m_login_dialog; //登录界面
	register_widget* m_register_widget; //注册界面
	QString skin_name;//主窗口背景图片的名称
	main_menu* m_main_menu; //主菜单
	skin_widget* m_skin_widget; //显示皮肤界面

	QTranslator* translator; //翻译器
	LANGUAGE current_language; //当前语言

	QLocalServer* server;
	bool is_running;

};

