#include "skin_widget.h"
#include "util.h"

skin_widget::skin_widget(QWidget* parent)
	: drop_shadow_widget(parent)
{
	this->resize(620, 445);

	skin_name = QString("");
	is_change = false;
	current_page = 1;

	this->initTitle();
	this->initCenter();
	this->initBottom();

	QVBoxLayout* main_layout = new QVBoxLayout();
	main_layout->addLayout(title_layout);
	main_layout->addLayout(center_layout);
	main_layout->addLayout(bottom_layout);
	main_layout->addStretch();
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

	setLayout(main_layout);

	this->translateLanguage();

	this->showSkin(QString::number(current_page, 10));
}

skin_widget::~skin_widget()
{

}

void skin_widget::initTitle()
{
	title_label = new QLabel();
	title_icon_label = new QLabel();
	close_button = new push_button();

	QPixmap title_pixmap("./Resources/img/safe.ico");
	title_icon_label->setPixmap(title_pixmap);
	title_icon_label->setFixedSize(16, 16);
	title_icon_label->setScaledContents(true);

	close_button->setPicName("./Resources/img/sysButton/close.png");
	title_label->setFixedHeight(30);

	title_layout = new QHBoxLayout();
	title_layout->addWidget(title_icon_label, 0, Qt::AlignVCenter);
	title_layout->addWidget(title_label, 0, Qt::AlignVCenter);
	title_layout->addStretch();
	title_layout->addWidget(close_button, 0, Qt::AlignTop);
	title_layout->setSpacing(5);
	title_layout->setContentsMargins(10, 0, 5, 0);

	title_label->setObjectName("whiteLabel");
	connect(close_button, SIGNAL(clicked()), this, SLOT(hide()));
}

void skin_widget::initCenter()
{
	skin_list << "./Resources/img/skin/0.png" << "./Resources/img/skin/1.png" << "./Resources/img/skin/2.png" << "./Resources/img/skin/3.png" << "./Resources/img/skin/4.png" <<
		"./Resources/img/skin/5.png" << "./Resources/img/skin/6.png" << "./Resources/img/skin/7.png" << "./Resources/img/skin/8.png" << "./Resources/img/skin/9.png" <<
		"./Resources/img/skin/10.png" << "./Resources/img/skin/11.png" << "./Resources/img/skin/12.png" << "./Resources/img/skin/13.png" << "./Resources/img/skin/14.png" <<
		"./Resources/img/skin/15.png" << "./Resources/img/skin/16.png" << "./Resources/img/skin/17.png" << "./Resources/img/skin/18.png" << "./Resources/img/skin/19.png" <<
		"./Resources/img/skin/20.png" << "./Resources/img/skin/21.png" << "./Resources/img/skin/22.png" << "./Resources/img/skin/23.png";

	center_layout = new QGridLayout();
	center_layout->setSpacing(5);
	center_layout->setContentsMargins(5, 35, 5, 0);

	for (int i = 0; i < 8; i++)
	{
		change_skin_widget* change_skin_widget_ = new change_skin_widget(); //������,change_skin_widget -> change_skin_widget_
		change_skin_list.append(change_skin_widget_);
		connect(change_skin_widget_, SIGNAL(changeSkin()), this, SLOT(varyfySkin()));
		center_layout->addWidget(change_skin_widget_, i / 4, i % 4);
	}

	int skin_list_count = skin_list.size();
	page_count = skin_list_count / 8;
	page_count_point = skin_list_count % 8;
	if (page_count_point > 0)
	{
		page_count = page_count + 1;
	}
}

void skin_widget::initBottom()
{
	QSignalMapper* signal_mapper = new QSignalMapper(this);
	QList<QPushButton*>* button_list = new QList<QPushButton*>();
	for (int i = 0; i < page_count; i++)
	{
		QPushButton* page_button = new QPushButton();
		page_button->setFixedWidth(20);
		page_button->setText(QString::number(i + 1, 10));
		page_button->setObjectName("blueButton");
		page_button->setCursor(Qt::PointingHandCursor);
		connect(page_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
		signal_mapper->setMapping(page_button, page_button->text());
		button_list->push_back(page_button);
	}

	first_page_button = new QPushButton();
	previous_page_button = new QPushButton();
	next_page_button = new QPushButton();
	last_page_button = new QPushButton();
	first_page_button->setFixedWidth(50);
	previous_page_button->setFixedWidth(50);
	next_page_button->setFixedWidth(50);
	last_page_button->setFixedWidth(50);
	first_page_button->setCursor(Qt::PointingHandCursor);
	previous_page_button->setCursor(Qt::PointingHandCursor);
	next_page_button->setCursor(Qt::PointingHandCursor);
	last_page_button->setCursor(Qt::PointingHandCursor);
	first_page_button->setObjectName("blueButton");
	previous_page_button->setObjectName("blueButton");
	next_page_button->setObjectName("blueButton");
	last_page_button->setObjectName("blueButton");

	connect(first_page_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
	connect(previous_page_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
	connect(next_page_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
	connect(last_page_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
	signal_mapper->setMapping(first_page_button, "first");
	signal_mapper->setMapping(previous_page_button, "previous");
	signal_mapper->setMapping(next_page_button, "next");
	signal_mapper->setMapping(last_page_button, "last");
	connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(showSkin(QString)));

	bottom_layout = new QHBoxLayout();
	bottom_layout->addStretch();
	bottom_layout->addWidget(first_page_button, 0, Qt::AlignVCenter);
	bottom_layout->addWidget(previous_page_button, 0, Qt::AlignVCenter);
	for (int i = 0; i < button_list->count(); i++)
	{
		QPushButton* page_button = button_list->at(i);
		bottom_layout->addWidget(page_button, 0, Qt::AlignVCenter);
	}
	bottom_layout->addWidget(next_page_button, 0, Qt::AlignVCenter);
	bottom_layout->addWidget(last_page_button, 0, Qt::AlignVCenter);
	bottom_layout->addStretch();
	bottom_layout->setSpacing(2);
	bottom_layout->setContentsMargins(0, 10, 0, 0);
}


void skin_widget::showSkin(QString current_skin)
{
	if (current_skin == "first")
	{
		current_page = 1;
	}
	else if (current_skin == "previous")
	{
		if (current_page > 1)
		{
			current_page = current_page - 1;
		}
	}
	else if (current_skin == "next")
	{
		if (current_page < page_count)
		{
			current_page = current_page + 1;
		}
	}
	else if (current_skin == "last")
	{
		current_page = page_count;
	}
	else
	{
		bool ok;
		current_page = current_skin.toInt(&ok, 10);
	}

	if (current_page == 1)
	{
		next_page_button->show();
		last_page_button->show();
		first_page_button->hide();
		previous_page_button->hide();
	}
	else if (current_page == page_count)
	{
		first_page_button->show();
		previous_page_button->show();
		next_page_button->hide();
		last_page_button->hide();
	}
	else
	{
		first_page_button->hide();
		previous_page_button->show();
		next_page_button->show();
		last_page_button->hide();
	}

	//��һҳΪ0-7 ��ʾ��previous_total_page��
	int previous_total_page = (current_page - 1) * 8;
	int tip_index = previous_total_page;

	for (int i = 0; i < change_skin_list.count(); i++)
	{
		change_skin_list.at(i)->changeSkin("./Resources/img/skin/" + QString::number(previous_total_page++, 10), tip_list.at(tip_index++), "11");
	}
}

void skin_widget::translateLanguage()
{
	title_label->setText(tr("title"));
	close_button->setToolTip(tr("close"));

	first_page_button->setText(tr("first page"));
	previous_page_button->setText(tr("previous page"));
	next_page_button->setText(tr("next page"));
	last_page_button->setText(tr("last page"));

	tip_list << tr("profound life") << tr("blue sea") << tr("red heart") << tr("lovely baby") << tr("transparent water") <<
		tr("flower") << tr("great sunshine") << tr("shadow amazement") << tr("life in blossom") << tr("360 pet") <<
		tr("beautiful stone") << tr("yellow energy") << tr("magic world") << tr("intense emotion") << tr("dream sky") <<
		tr("angry bird") << tr("graceful jazz") << tr("card") << tr("summer cool") << tr("blue world") <<
		tr("woodwind") << tr("pink mood") << tr("across time") << tr("six year");
}

void skin_widget::varyfySkin()
{
	QObject* object = QObject::sender();
	change_skin_widget* change_skin_widget_ = qobject_cast<change_skin_widget*>(object);   ////������,change_skin_widget -> change_skin_widget_
	skin_name = change_skin_widget_->getPixmapName();

	this->skin_name = skin_name;
	is_change = true;
	update();
	emit changeSkin(skin_name);
}

void skin_widget::paintEvent(QPaintEvent* event)
{
	drop_shadow_widget::paintEvent(event);
	QString skin_name = util::getSkinName();
	int height = 35;
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width() - 2 * SHADOW_WIDTH, this->height() - 2 * SHADOW_WIDTH), QPixmap(skin_name));
	painter.drawRect(QRect(SHADOW_WIDTH, height, this->width() - 2 * SHADOW_WIDTH, this->height() - height - SHADOW_WIDTH));
}
