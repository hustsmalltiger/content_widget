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
    void initLeft();     //主窗口左边
    void initRight();
    void initRightTop(); //主窗口右上部
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
	QPushButton* power_button; //立即体验按钮

	QSplitter* right_splitter;
	QWidget* right_top_widget;

	QPushButton* login_button; //登录我的360账号
	QLabel* priv_label;        //黄砖图标
	QLabel* info_label;        //开启炫动卫视图标
	QLabel* privilege_label;   //专享特权
	QPushButton* register_button; //10秒免费注册
	QPushButton* safe_button;     //特权领360炫动logo
	QPushButton* tab_button;      //领取炫动导航功能图标
	QPushButton* pet_button;      //宠物安仔精灵
	QPushButton* lottery_button;  //按在抱枕大派送
	QPushButton* cloud_five_button;  //5G云盘
	QPushButton* caipiao_button;     //彩票

	QWidget* right_center_widget;
	QToolButton* fireproof_button;    //360防火墙
	QToolButton* triggerman_button;   //360保镖
	QToolButton* net_shop_button;     //网购先赔
	QLabel* line_label_1;             //虚线
	QLabel* line_label_2;             //虚线


	QWidget* right_center_funtion_widget;
	QLabel* funtion_label;             //功能大全
	QPushButton* more_button;          //更多
	QList<QToolButton*> button_list;  //按钮容器

	QWidget* right_botton_widget;
	QLabel* icon_label;                //云图标
	QLabel* connect_label;             //成功连接云安全
	QLabel* version_label;             //版本号
	QPushButton* version_button;       //版本升级

};

