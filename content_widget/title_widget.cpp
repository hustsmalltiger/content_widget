#include "title_widget.h"
#include "push_button.h"
#include"tool_button.h"
#pragma execution_character_set("utf-8")							//指示char的执行字符集是UTF-8编码

title_widget::title_widget(QWidget* parent)
	: QWidget(parent)
{
	//去掉边框和设置背景为透明
	//setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);			//会导致调试时，没办法关闭，可能在成品时，打开（源码没有）
	/*setAttribute(Qt::WA_TranslucentBackground);*/

	version_title = new QLabel();
	medal_button = new push_button();								//勋章墙
	skin_button = new push_button();								//换肤
	main_menu_button = new push_button();							//设置
	min_button = new push_button();									//最小化   
	feedback_button = new push_button();							//反馈建议
	close_button = new push_button();								//关闭

	version_title->setObjectName("whiteLabel");						//源码有，博客中注释掉了；其含义是给这个实例命了个名字
	//设置图片
	medal_button->setPicName(QString("./Resources/img/sysButton/medal.png"));
	skin_button->setPicName(QString("./Resources/img/sysButton/skin.png"));
	feedback_button->setPicName(QString("./Resources/img/sysButton/feedback.png"));
	main_menu_button->setPicName(QString("./Resources/img/sysButton/menu.png"));
	min_button->setPicName(QString("./Resources/img/sysButton/min.png"));
	close_button->setPicName(QString("./Resources/img/sysButton/close.png"));
	//关联
	connect(skin_button, SIGNAL(clicked()), this, SIGNAL(showSkin()));
	connect(main_menu_button, SIGNAL(clicked()), this, SIGNAL(showMainMenu()));
	connect(min_button, SIGNAL(clicked()), this, SIGNAL(showMin()));
	connect(close_button, SIGNAL(clicked()), this, SIGNAL(closeWidget()));

	//水平布局
	QHBoxLayout* title_layout = new QHBoxLayout();
	title_layout->addWidget(version_title, 0, Qt::AlignVCenter);	//,stretch=0?, Qt::AlignVCenter：垂直方向居中
	title_layout->addStretch();										//添加了一个伸缩空间
	title_layout->addWidget(medal_button, 0, Qt::AlignTop);			//Qt::AlignTop：垂直方向靠上。
	title_layout->addWidget(skin_button, 0, Qt::AlignTop);	  
	title_layout->addWidget(feedback_button, 0, Qt::AlignTop);
	title_layout->addWidget(main_menu_button, 0, Qt::AlignTop);
	title_layout->addWidget(min_button, 0, Qt::AlignTop);
	title_layout->addWidget(close_button, 0, Qt::AlignTop);

	title_layout->setSpacing(0);									//表示各个控件之间的上下间距为:0
	title_layout->setContentsMargins(0, 0, 5, 0);					//设置左侧、顶部、右侧和底部边距，以便在布局周围使用
	version_title->setContentsMargins(15, 0, 0, 0);					//
	skin_button->setContentsMargins(0, 0, 10, 0);

	QStringList string_list;
	string_list << "./Resources/img/toolWidget/tiJian.png" << "./Resources/img/toolWidget/muMa.png" << "./Resources/img/toolWidget/repair.png" << "./Resources/img/toolWidget/qingLi.png"
		<< "./Resources/img/toolWidget/jiaSu.png" << "./Resources/img/toolWidget/expert.png" << "./Resources/img/toolWidget/menZhen.png" << "./Resources/img/toolWidget/gongNeng.png";

	QHBoxLayout* button_layout = new QHBoxLayout();
	QSignalMapper* signal_mapper = new QSignalMapper(this);

	for (int i = 0; i < string_list.size(); i++)
	{
		//贴图
		tool_button* tol_button = new tool_button(string_list.at(i));
		button_list.append(tol_button);
		connect(tol_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
		signal_mapper->setMapping(tol_button, QString::number(i, 10));				//10为转换进制

		button_layout->addWidget(tol_button, 0, Qt::AlignBottom);					//Qt::AlignButtom：垂直方向靠下，与底部对齐。
	}

	connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(turnPage(QString)));
	safe_360_label = new QLabel();
	safe_label = new QLabel();

	//垂直布局
	QVBoxLayout* safe_layout = new QVBoxLayout();
	safe_layout->addWidget(safe_360_label);
	safe_layout->addWidget(safe_label);
	safe_layout->setSpacing(5);
	safe_layout->setContentsMargins(0, 0, 0, 0);

	//标题栏里的那个360图标
	QLabel* logo_label = new QLabel();
	QPixmap pixmap("./Resources/img/safe.ico");
	logo_label->setPixmap(pixmap);
	logo_label->setFixedSize(pixmap.size());

	safe_360_label->setObjectName("whiteLabel");			//同前面，源码里有，博客中被注释掉了
	safe_label->setObjectName("whiteLabel");				//同上
	QFont safe_360_font = safe_360_label->font();
	safe_360_font.setPointSize(18);
	safe_360_font.setBold(true);
	safe_360_label->setFont(safe_360_font);

	safe_360_label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	safe_label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

	QFont safe_font = safe_label->font();					//设置字体
	safe_font.setPointSize(14);
	safe_font.setBold(true);
	safe_label->setFont(safe_font);

	button_layout->addStretch();
	button_layout->addLayout(safe_layout);
	button_layout->addWidget(logo_label);
	button_layout->setSpacing(8);
	button_layout->setContentsMargins(15, 0, 15, 0);

	QVBoxLayout* main_layout = new QVBoxLayout();
	main_layout->addLayout(title_layout);
	main_layout->addLayout(button_layout);
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(0, 0, 0, 0);

	this->translateLanguage();

	setLayout(main_layout);
	setFixedHeight(110);
	setFixedWidth(870);
	is_move = false;

}

title_widget::~title_widget()
{

}

void title_widget::translateLanguage()
{
	version_title->setText(tr("title") + QString("9.2"));				//tr（翻译）是用来实现国际化
	skin_button->setToolTip(tr("change skin"));
	main_menu_button->setToolTip(tr("main menu"));
	min_button->setToolTip(tr("minimize"));
	feedback_button->setToolTip(tr("feedback"));
	close_button->setToolTip(tr("close"));

	button_list.at(0)->setText(tr("power"));							//setText()  改变其中的文本
	button_list.at(1)->setText(tr("mummy"));
	button_list.at(2)->setText(tr("repair"));
	button_list.at(3)->setText(tr("clear"));
	button_list.at(4)->setText(tr("optimize"));
	button_list.at(5)->setText(tr("expert"));
	button_list.at(6)->setText(tr("hole"));
	button_list.at(7)->setText(tr("software"));

	safe_360_label->setText(tr("360"));
	safe_label->setText(tr("safe"));
}

void title_widget::turnPage(QString current_page)
{
	bool ok;
	int current_index = current_page.toInt(&ok, 10);

	for (int i = 0; i < button_list.count(); i++)
	{
		tool_button* tol_button = button_list.at(i);
		if (current_index == i)
		{
			tol_button->setMousePress(true);
		}
		else
		{
			tol_button->setMousePress(false);
		}
	}

	emit turnPage(current_index);
}