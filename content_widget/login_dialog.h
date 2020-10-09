#pragma once

#include <QDialog>
#include <QStackedLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QListWidget>
#include <QGridLayout>
#include "push_button.h"
#include "msg_box.h"
#include "loading_widget.h"
#include "common.h"
#include "drop_shadow_widget.h"


class login_dialog : public drop_shadow_widget
{
	Q_OBJECT

public:
	explicit login_dialog(QWidget* parent = 0);
	~login_dialog();
	void translateLanguage();

protected:
	void paintEvent(QPaintEvent* event);

private slots:
	void turnSina();
	void turnRenRen();
	void showAccount(QString account);
	void removeAccount(QString account);
	void verify();

private:
	void initSafeWidget();
	void initRenRenWidget();
	void initSinaWidget();
	void initLoginCenter();
	void changeTitle();
	void turnWidget();

private:
	QStackedLayout* main_stacked_layout; //���ˡ�360������������
	QStackedLayout* stacked_layout; //360������������
	QStackedLayout* login_stacked_layout; //360����¼��֤����
	QWidget* safe_renren_center_widget;

	QWidget* safe_renren_widget; //��ȫ��ʿ����
	QWidget* safe_widget;
	QLabel* icon_label;
	QLabel* safe_label;
	QLabel* protect_label;

	QWidget* renren_widget; //���˽���
	QLabel* renren_icon_label;
	QLabel* renren_info_label;
	QLabel* renren_net_label;
	QLabel* renren_login_label;

	QWidget* sina_widget; //���˽���
	QLabel* sina_icon_label; //����ͼ��
	QLabel* sina_info_label; //����΢��
	QLabel* sina_net_label; //sina.com
	QPushButton* sina_register_button; //����ע�ᰴť
	QLineEdit* sina_account_line_edit; //�����ʺ�
	QLineEdit* sina_password_line_edit; //��������
	QPushButton* examine_authorize_button; //�鿴��Ȩ��Ϣ
	QPushButton* authorize_button; //��Ȩ��ť
	QCheckBox* sina_login_check_box; //�Զ���¼
	QCheckBox* safe_attention_check_box; //��ע360��ȫ��ʿ

	QLabel* title_label;
	QLabel* account_label;
	QLabel* password_label;
	QLabel* other_account_label;
	push_button* close_button;
	QPushButton* sina_button;
	QPushButton* renren_button;
	QLineEdit* password_line_edit;
	QPushButton* register_button;
	QPushButton* forgot_button;
	QPushButton* login_button;
	QCheckBox* remember_check_box;
	QCheckBox* auto_login_check_box;
	QComboBox* account_combo_box;
	QListWidget* list_widget;

	LOGIN login; //��¼��ʾ�Ľ���
	LOGIN sina_login; //���˰�ť��ʾ�Ľ���

	msg_box * msg_box_; //ɾ���û���ʾ����    //�����޸�  msg_box_
	loading_widget* loading_widget_; //�ȴ����棬���ڵ�¼  //�����޸�  loading_widget_

};
