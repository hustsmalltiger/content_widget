#pragma once

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QDialog>
#include <QCheckBox>
#include <QComboBox>
#include <QTabWidget>
#include <QHBoxLayout>
#include "common.h"
#include "push_button.h"
#include "drop_shadow_widget.h"

class setting_dialog : public drop_shadow_widget
{
	Q_OBJECT
		
public:
	explicit setting_dialog(QWidget* parent = 0);
	~setting_dialog();
	void translateLanguage();

protected:
	void paintEvent(QPaintEvent* event);

private:
	void initTitle();
	void initCenter();
	void initBottom();
	void initTab1();
	void initTab2();
	void initTab3();
	void initTab4();
	void initTab5();
	void initTab6();

signals:
	void changeLanguage(LANGUAGE ui_language);

private slots:
	void updateConfig();

private:

	QHBoxLayout* title_layout; //���Ⲽ��
	QLabel* title_icon_label; //����ͼ��
	QLabel* title_label; //����
	push_button* close_button; //�رհ�ť

	QHBoxLayout* bottom_layout; //�ײ�����
	QPushButton* ok_button; //ȷ����ť
	QPushButton* cancel_button; //ȡ����ť

	QTabWidget* tab_widget;

	QWidget* tab1; //������ʽ
	QGroupBox* tab1_group_box;
	QRadioButton* auto_rise_button; //�Զ�����
	QRadioButton* not_auto_rise_button; //���Զ�����
	QCheckBox* rise_mummy_check_box; //������������ľ���
	QCheckBox* game_check_box; //��Ϸʱ������
	QCheckBox* g3_check_box; //3G����ʱ������
	QCheckBox* p2p_check_box; //ʹ��p2p/p2s����Ϊ�����������
	QCheckBox* mummy_check_box; //����ľ���������ɺ����½���ʾ

	QWidget* tab2; //�߼�����
	QGroupBox* tab2_group_box1;
	QGroupBox* tab2_group_box2;
	QGroupBox* tab2_group_box3;
	QCheckBox* auto_start_check_box; //����������
	QCheckBox* remove_own_check_box; //���ռ��
	QCheckBox* strong_remove_check_box; //ǿ��ɾ��
	QCheckBox* mummy_kill_check_box; //ľ���Ʋ�ɱ
	QCheckBox* display_count_check_box; //��ʾ���������

	QWidget* tab3; //��������
	QGroupBox* tab3_group_box1;
	QGroupBox* tab3_group_box2;
	QRadioButton* auto_check_button; //ÿ�������Զ����
	QRadioButton* first_check_button; //�״ο������
	QRadioButton* hand_check_button; //�ֶ��������
	QRadioButton* select_quit_button; //ѡ���˳���ʽ
	QRadioButton* backstage_mode_button; //��̨ģʽ
	QRadioButton* immediacy_close_button; //ֱ�ӹر�

	QWidget* tab4; //�û�����
	QGroupBox* tab4_group_box;
	QCheckBox* diaplay_experience_check_box; //���������ʾ��ȡ����ֵ�Ķ�̬����
	QCheckBox* diaplay_login_check_box; //�Զ���¼����ʾ��¼��ʾ����
	QCheckBox* tray_quit_check_box; //�����˳���¼����ʾ��ʾ����
	QCheckBox* new_character_check_box; //������Ȩʱ��ʾ֪ͨ����
	QCheckBox* rise_remind_check_box; //��������֪ͨ����
	QLabel* language_label; //���Ա�ǩ
	QComboBox* language_combo_box; //����������

	QWidget* tab5; //���Ƽƻ�
	QGroupBox* tab5_group_box;
	QCheckBox* improve_plan_check_box;  //�μӡ�360�û������Ƽƻ���
	QPushButton* understand_detail_button; //�˽�����

	QWidget* tab6; //�ư�ȫ�ƻ�
	QGroupBox* tab6_group_box1;
	QGroupBox* tab6_group_box2;
	QLabel* file_safe_label; //�ļ���ȫ��ŵ
	QLabel* internet_safe_label; //��ַ��ȫ��ŵ
	QCheckBox* file_safe_check_box; //����360���ļ��ư�ȫ�ƻ���
	QCheckBox* internet_safe_check_box; //����360����ַ�ư�ȫ�ƻ���
	QPushButton* look_privacy_button; //�鿴360�û���˽������ŵ

};
