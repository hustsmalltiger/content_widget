#pragma once
/*
#include <QtWidgets/QMainWindow>

#include "ui_content_widget.h"

class content_widget : public QMainWindow
{
    Q_OBJECT

public:
    content_widget(QWidget *parent = Q_NULLPTR);
    //~content_widget();


private:
    Ui::content_widgetClass ui;
    
};
*/
#include <QWidget>
#include <QSplitter>
#include <QToolButton>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QPainter>
#include <QPen>
#include <QHBoxLayout>
#include <QEvent>
#include <QVBoxLayout>
class content_widget : public QWidget
{
    Q_OBJECT

public:
    explicit content_widget(QWidget* parent = 0);
    ~content_widget();
    void translateLanguage();

private:
    void initLeft();     //���������
    void initRight();
    void initRightTop(); //���������ϲ�
    void initRightCenter();
    void initRightCenterFuntion();
    void initRightButton();

protected:
    bool eventFilter(QObject* obj, QEvent* event);


private:
	QSplitter* main_splitter;

	QWidget* left_widget;
	QLabel* label;
	QLabel* suggest_label;
	QLabel* system_safe_label;
	QPushButton* power_button; //�������鰴ť

	QSplitter* right_splitter;
	QWidget* right_top_widget;

	QPushButton* login_button; //��¼�ҵ�360�˺�
	QLabel* priv_label;        //��שͼ��
	QLabel* info_label;        //�����Ŷ�����ͼ��
	QLabel* privilege_label;   //ר����Ȩ
	QPushButton* register_button; //10�����ע��
	QPushButton* safe_button;     //��Ȩ��360�Ŷ�logo
	QPushButton* tab_button;      //��ȡ�Ŷ���������ͼ��
	QPushButton* pet_button;      //���ﰲ�о���
	QPushButton* lottery_button;  //���ڱ��������
	QPushButton* cloud_five_button;  //5G����
	QPushButton* caipiao_button;     //��Ʊ

	QWidget* right_center_widget;
	QToolButton* fireproof_button;    //360����ǽ
	QToolButton* triggerman_button;   //360����
	QToolButton* net_shop_button;     //��������
	QLabel* line_label_1;             //����
	QLabel* line_label_2;             //����


	QWidget* right_center_funtion_widget;
	QLabel* funtion_label;             //���ܴ�ȫ
	QPushButton* more_button;          //����
	QList<QToolButton*> button_list;  //��ť����

	QWidget* right_botton_widget;
	QLabel* icon_label;                //��ͼ��
	QLabel* connect_label;             //�ɹ������ư�ȫ
	QLabel* version_label;             //�汾��
	QPushButton* version_button;       //�汾����

};

