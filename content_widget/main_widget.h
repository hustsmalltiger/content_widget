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
	title_widget* m_title_widget; //������,������Ϊ"m_"+"������"
	content_widget* m_content_widget; //����������
	kill_mummy_widget* m_kill_mummy_widget;  //��ɱľ�����
	system_tray* m_system_tray; //������
	setting_dialog* m_setting_dialog; //���ý���
	character_widget* m_character_widget; //�°����Խ���
	about_us_dialog* m_about_us_dialog; //�������ǽ���
	login_dialog* m_login_dialog; //��¼����
	register_widget* m_register_widget; //ע�����
	QString skin_name;//�����ڱ���ͼƬ������
	main_menu* m_main_menu; //���˵�
	skin_widget* m_skin_widget; //��ʾƤ������

	QTranslator* translator; //������
	LANGUAGE current_language; //��ǰ����

	QLocalServer* server;
	bool is_running;

};

