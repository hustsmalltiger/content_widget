#include "title_widget.h"
#include "push_button.h"
#include"tool_button.h"
#pragma execution_character_set("utf-8")							//ָʾchar��ִ���ַ�����UTF-8����

title_widget::title_widget(QWidget* parent)
	: QWidget(parent)
{
	//ȥ���߿�����ñ���Ϊ͸��
	//setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);			//�ᵼ�µ���ʱ��û�취�رգ������ڳ�Ʒʱ���򿪣�Դ��û�У�
	/*setAttribute(Qt::WA_TranslucentBackground);*/

	version_title = new QLabel();
	medal_button = new push_button();								//ѫ��ǽ
	skin_button = new push_button();								//����
	main_menu_button = new push_button();							//����
	min_button = new push_button();									//��С��   
	feedback_button = new push_button();							//��������
	close_button = new push_button();								//�ر�

	version_title->setObjectName("whiteLabel");						//Դ���У�������ע�͵��ˣ��京���Ǹ����ʵ�����˸�����
	//����ͼƬ
	medal_button->setPicName(QString("./Resources/img/sysButton/medal.png"));
	skin_button->setPicName(QString("./Resources/img/sysButton/skin.png"));
	feedback_button->setPicName(QString("./Resources/img/sysButton/feedback.png"));
	main_menu_button->setPicName(QString("./Resources/img/sysButton/menu.png"));
	min_button->setPicName(QString("./Resources/img/sysButton/min.png"));
	close_button->setPicName(QString("./Resources/img/sysButton/close.png"));
	//����
	connect(skin_button, SIGNAL(clicked()), this, SIGNAL(showSkin()));
	connect(main_menu_button, SIGNAL(clicked()), this, SIGNAL(showMainMenu()));
	connect(min_button, SIGNAL(clicked()), this, SIGNAL(showMin()));
	connect(close_button, SIGNAL(clicked()), this, SIGNAL(closeWidget()));

	//ˮƽ����
	QHBoxLayout* title_layout = new QHBoxLayout();
	title_layout->addWidget(version_title, 0, Qt::AlignVCenter);	//,stretch=0?, Qt::AlignVCenter����ֱ�������
	title_layout->addStretch();										//�����һ�������ռ�
	title_layout->addWidget(medal_button, 0, Qt::AlignTop);			//Qt::AlignTop����ֱ�����ϡ�
	title_layout->addWidget(skin_button, 0, Qt::AlignTop);	  
	title_layout->addWidget(feedback_button, 0, Qt::AlignTop);
	title_layout->addWidget(main_menu_button, 0, Qt::AlignTop);
	title_layout->addWidget(min_button, 0, Qt::AlignTop);
	title_layout->addWidget(close_button, 0, Qt::AlignTop);

	title_layout->setSpacing(0);									//��ʾ�����ؼ�֮������¼��Ϊ:0
	title_layout->setContentsMargins(0, 0, 5, 0);					//������ࡢ�������Ҳ�͵ײ��߾࣬�Ա��ڲ�����Χʹ��
	version_title->setContentsMargins(15, 0, 0, 0);					//
	skin_button->setContentsMargins(0, 0, 10, 0);

	QStringList string_list;
	string_list << "./Resources/img/toolWidget/tiJian.png" << "./Resources/img/toolWidget/muMa.png" << "./Resources/img/toolWidget/repair.png" << "./Resources/img/toolWidget/qingLi.png"
		<< "./Resources/img/toolWidget/jiaSu.png" << "./Resources/img/toolWidget/expert.png" << "./Resources/img/toolWidget/menZhen.png" << "./Resources/img/toolWidget/gongNeng.png";

	QHBoxLayout* button_layout = new QHBoxLayout();
	QSignalMapper* signal_mapper = new QSignalMapper(this);

	for (int i = 0; i < string_list.size(); i++)
	{
		//��ͼ
		tool_button* tol_button = new tool_button(string_list.at(i));
		button_list.append(tol_button);
		connect(tol_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
		signal_mapper->setMapping(tol_button, QString::number(i, 10));				//10Ϊת������

		button_layout->addWidget(tol_button, 0, Qt::AlignBottom);					//Qt::AlignButtom����ֱ�����£���ײ����롣
	}

	connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(turnPage(QString)));
	safe_360_label = new QLabel();
	safe_label = new QLabel();

	//��ֱ����
	QVBoxLayout* safe_layout = new QVBoxLayout();
	safe_layout->addWidget(safe_360_label);
	safe_layout->addWidget(safe_label);
	safe_layout->setSpacing(5);
	safe_layout->setContentsMargins(0, 0, 0, 0);

	//����������Ǹ�360ͼ��
	QLabel* logo_label = new QLabel();
	QPixmap pixmap("./Resources/img/safe.ico");
	logo_label->setPixmap(pixmap);
	logo_label->setFixedSize(pixmap.size());

	safe_360_label->setObjectName("whiteLabel");			//ͬǰ�棬Դ�����У������б�ע�͵���
	safe_label->setObjectName("whiteLabel");				//ͬ��
	QFont safe_360_font = safe_360_label->font();
	safe_360_font.setPointSize(18);
	safe_360_font.setBold(true);
	safe_360_label->setFont(safe_360_font);

	safe_360_label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	safe_label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

	QFont safe_font = safe_label->font();					//��������
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
	version_title->setText(tr("title") + QString("9.2"));				//tr�����룩������ʵ�ֹ��ʻ�
	skin_button->setToolTip(tr("change skin"));
	main_menu_button->setToolTip(tr("main menu"));
	min_button->setToolTip(tr("minimize"));
	feedback_button->setToolTip(tr("feedback"));
	close_button->setToolTip(tr("close"));

	button_list.at(0)->setText(tr("power"));							//setText()  �ı����е��ı�
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