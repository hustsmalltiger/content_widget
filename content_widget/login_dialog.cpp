#include "login_dialog.h"
#include "util.h"
#include "account_item.h"

login_dialog::login_dialog(QWidget* parent)
	: drop_shadow_widget(parent)
{
	this->resize(370, 275);
	login = SAFE;                                        //由于LOGIN未设定范围引起的警告
	sina_login = SINA;
	msg_box_ = new msg_box();                           //重名修改  msg_box_
	loading_widget_ = new loading_widget(this);			//重名修改  loading_widget_
	safe_renren_center_widget = new QWidget(this);

	this->initLoginCenter();
	this->initRenRenWidget();
	this->initSafeWidget();
	this->initSinaWidget();

	login_stacked_layout = new QStackedLayout();
	main_stacked_layout = new QStackedLayout();
	stacked_layout = new QStackedLayout();
	login_stacked_layout->addWidget(safe_renren_center_widget);
	login_stacked_layout->addWidget(loading_widget_);     //重名修改
	login_stacked_layout->setCurrentWidget(safe_renren_center_widget);

	stacked_layout->addWidget(safe_widget);
	stacked_layout->addWidget(renren_widget);
	stacked_layout->setCurrentWidget(safe_widget);

	safe_widget->setFixedHeight(70);

	safe_renren_widget = new QWidget(this);
	title_label = new QLabel();
	other_account_label = new QLabel();
	close_button = new push_button();
	sina_button = new QPushButton();
	renren_button = new QPushButton();

	title_label->setAlignment(Qt::AlignBottom);

	QPixmap sina_pixmap("./Resources/img/loginDialog/sina.png");
	sina_button->setIcon(sina_pixmap);
	sina_button->setIconSize(QSize(20, 20));
	sina_button->setFixedSize(25, 22);

	QPixmap renren_pixmap("./Resources/img/loginDialog/renren.png");
	renren_button->setIcon(renren_pixmap);
	renren_button->setIconSize(QSize(20, 20));
	renren_button->setFixedSize(25, 22);

	sina_button->setObjectName("skinButton");
	renren_button->setObjectName("skinButton");

	close_button->setPicName(QString("./Resources/img/sysButton/close.png"));
	title_label->setObjectName("whiteLabel");

	QHBoxLayout* title_layout = new QHBoxLayout();
	title_layout->addWidget(title_label);
	title_layout->addStretch();
	title_layout->addWidget(close_button);
	title_layout->setSpacing(0);
	title_layout->setContentsMargins(10, 0, 5, 10);

	QHBoxLayout* bottom_layout = new QHBoxLayout();
	bottom_layout->addWidget(other_account_label);
	bottom_layout->addWidget(sina_button);
	bottom_layout->addWidget(renren_button);
	bottom_layout->addStretch();
	bottom_layout->setSpacing(5);
	bottom_layout->setContentsMargins(20, 0, 0, 5);

	QVBoxLayout* safe_renren_layout = new QVBoxLayout();
	safe_renren_layout->addLayout(stacked_layout);
	safe_renren_layout->addStretch();
	safe_renren_layout->addLayout(login_stacked_layout);
	safe_renren_layout->setSpacing(0);
	safe_renren_layout->setContentsMargins(0, 0, 0, 0);

	safe_renren_widget->setLayout(safe_renren_layout);

	main_stacked_layout->addWidget(safe_renren_widget);
	main_stacked_layout->setCurrentWidget(safe_renren_widget);

	QHBoxLayout* login_layout = new QHBoxLayout();
	login_layout->addStretch();
	login_layout->addWidget(login_button);
	login_layout->setSpacing(0);
	login_layout->setContentsMargins(0, 0, 20, 10);

	QVBoxLayout* main_layout = new QVBoxLayout();
	main_layout->addLayout(title_layout);
	main_layout->addLayout(main_stacked_layout);
	main_layout->addLayout(login_layout);
	main_layout->addLayout(bottom_layout);
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

	connect(close_button, SIGNAL(clicked()), this, SLOT(hide()));
	connect(renren_button, SIGNAL(clicked()), this, SLOT(turnRenRen()));
	connect(sina_button, SIGNAL(clicked()), this, SLOT(turnSina()));
	connect(login_button, SIGNAL(clicked()), this, SLOT(verify()));

	this->setLayout(main_layout);
	this->translateLanguage();
}

login_dialog::~login_dialog()
{

}

void  login_dialog::initLoginCenter()
{
	account_label = new QLabel();
	password_label = new QLabel();
	register_button = new QPushButton();
	forgot_button = new QPushButton();
	login_button = new QPushButton();
	password_line_edit = new QLineEdit();
	remember_check_box = new QCheckBox();
	auto_login_check_box = new QCheckBox();

	register_button->setCursor(Qt::PointingHandCursor);
	forgot_button->setCursor(Qt::PointingHandCursor);

	account_combo_box = new QComboBox();
	list_widget = new QListWidget();
	account_combo_box->setModel(list_widget->model());
	account_combo_box->setView(list_widget);
	account_combo_box->setEditable(true);
	for (int i = 0; i < 3; i++)
	{
		account_item* account_item_ = new account_item();    //重名修改account_item_
		account_item_->setAccountNumber(QString("safe_") + QString::number(i, 10) + QString("@sina.com"));
		connect(account_item_, SIGNAL(showAccount(QString)), this, SLOT(showAccount(QString)));
		connect(account_item_, SIGNAL(removeAccount(QString)), this, SLOT(removeAccount(QString)));
		QListWidgetItem* list_item = new QListWidgetItem(list_widget);
		list_widget->setItemWidget(list_item, account_item_);
	}

	account_label->setScaledContents(true);
	password_label->setScaledContents(true);
	account_label->setAlignment(Qt::AlignRight);
	password_label->setAlignment(Qt::AlignRight);
	password_line_edit->setEchoMode(QLineEdit::Password);
	account_combo_box->setFixedHeight(25);
	password_line_edit->setFixedHeight(25);

	register_button->setFixedSize(70, 25);
	forgot_button->setFixedSize(70, 25);
	login_button->setFixedSize(60, 25);
	register_button->setObjectName("blueButton");
	forgot_button->setObjectName("blueButton");
	login_button->setObjectName("loginGreenButton");

	QHBoxLayout* h_layout = new QHBoxLayout();
	h_layout->addWidget(remember_check_box);
	h_layout->addWidget(auto_login_check_box);
	h_layout->addStretch();
	h_layout->setSpacing(40);
	h_layout->setContentsMargins(0, 0, 0, 0);

	QGridLayout* grid_layout = new QGridLayout();
	grid_layout->addWidget(account_label, 0, 0);
	grid_layout->addWidget(account_combo_box, 0, 1);
	grid_layout->addWidget(register_button, 0, 2);
	grid_layout->addWidget(password_label, 1, 0);
	grid_layout->addWidget(password_line_edit, 1, 1);
	grid_layout->addWidget(forgot_button, 1, 2);
	grid_layout->addLayout(h_layout, 2, 1);
	grid_layout->setHorizontalSpacing(5);
	grid_layout->setVerticalSpacing(10);
	grid_layout->setContentsMargins(20, 0, 20, 0);

	safe_renren_center_widget->setLayout(grid_layout);
}

void login_dialog::initSinaWidget()
{
	sina_widget = new QWidget();
	sina_register_button = new QPushButton();
	sina_icon_label = new QLabel();
	sina_info_label = new QLabel();
	sina_net_label = new QLabel();
	sina_register_button = new QPushButton();
	sina_account_line_edit = new QLineEdit();
	sina_password_line_edit = new QLineEdit();
	examine_authorize_button = new QPushButton();
	authorize_button = new QPushButton();
	sina_login_check_box = new QCheckBox();
	safe_attention_check_box = new QCheckBox();

	sina_password_line_edit->setEchoMode(QLineEdit::Password);

	sina_info_label->setAlignment(Qt::AlignBottom);
	sina_net_label->setAlignment(Qt::AlignTop);
	sina_register_button->setCursor(Qt::PointingHandCursor);
	examine_authorize_button->setCursor(Qt::PointingHandCursor);

	sina_account_line_edit->setFixedHeight(30);
	sina_password_line_edit->setFixedHeight(30);
	QPixmap icon_pixmap("./Resources/img/loginDialog/sina.png");
	sina_icon_label->setPixmap(icon_pixmap);
	sina_icon_label->setFixedSize(icon_pixmap.size());
	sina_icon_label->setScaledContents(true);

	QFont sina_info_font = sina_info_label->font();
	sina_info_font.setPointSize(14);
	sina_info_font.setItalic(true);
	sina_info_label->setFont(sina_info_font);

	QFont sina_net_font = sina_net_label->font();
	sina_net_font.setItalic(true);
	sina_net_label->setFont(sina_net_font);

	sina_register_button->setObjectName("blueButton");
	examine_authorize_button->setObjectName("examineAuthorizeButton");

	authorize_button->setFixedSize(90, 30);
	QFont authorize_font = authorize_button->font();
	authorize_font.setPointSize(14);
	authorize_button->setFont(authorize_font);
	authorize_button->setObjectName("redButton");

	QVBoxLayout* info_layout = new QVBoxLayout();
	info_layout->addWidget(sina_info_label);
	info_layout->addWidget(sina_net_label);
	info_layout->setSpacing(0);
	info_layout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout* sina_layout = new QHBoxLayout();
	sina_layout->addWidget(sina_icon_label);
	sina_layout->addLayout(info_layout);
	sina_layout->addStretch();
	sina_layout->setSpacing(5);
	sina_layout->setContentsMargins(0, 0, 0, 0);

	QGridLayout* grid_layout = new QGridLayout();
	grid_layout->addLayout(sina_layout, 0, 0);
	grid_layout->addWidget(sina_register_button, 0, 2);
	grid_layout->addWidget(sina_account_line_edit, 1, 0, 1, 3);
	grid_layout->addWidget(sina_password_line_edit, 2, 0, 1, 3);
	grid_layout->addWidget(examine_authorize_button, 3, 0);
	grid_layout->addWidget(authorize_button, 3, 2, Qt::AlignRight);
	grid_layout->setHorizontalSpacing(5);
	grid_layout->setVerticalSpacing(10);
	grid_layout->setContentsMargins(50, 0, 50, 0);

	QHBoxLayout* h_layout = new QHBoxLayout();
	h_layout->addStretch();
	h_layout->addWidget(sina_login_check_box);
	h_layout->addWidget(safe_attention_check_box);
	h_layout->setSpacing(20);
	h_layout->setContentsMargins(0, 0, 20, 0);

	QVBoxLayout* main_layout = new QVBoxLayout();
	main_layout->addLayout(grid_layout);
	main_layout->addLayout(h_layout);
	main_layout->setSpacing(20);
	main_layout->setContentsMargins(0, 0, 0, 0);

	sina_widget->setLayout(main_layout);
}

void login_dialog::initRenRenWidget()
{
	renren_widget = new QWidget(this);
	renren_icon_label = new QLabel();
	renren_info_label = new QLabel();
	renren_net_label = new QLabel();
	renren_login_label = new QLabel();

	QFont renren_info_font = renren_info_label->font();
	renren_info_font.setPointSize(14);
	renren_info_label->setFont(renren_info_font);

	QFont renren_login_font = renren_login_label->font();
	renren_login_font.setPointSize(14);
	renren_login_label->setFont(renren_login_font);

	renren_info_label->setStyleSheet("color:rgb(0, 90, 170);");
	renren_net_label->setStyleSheet("color:rgb(0, 90, 170);");
	renren_login_label->setStyleSheet("color:white;");

	QPixmap icon_pixmap("./Resources/img/loginDialog/ren.png");
	renren_icon_label->setPixmap(icon_pixmap);
	renren_icon_label->setFixedSize(icon_pixmap.size());
	renren_icon_label->setScaledContents(true);

	QVBoxLayout* info_layout = new QVBoxLayout();
	info_layout->addStretch();
	info_layout->addWidget(renren_info_label);
	info_layout->addWidget(renren_net_label);
	info_layout->addStretch();
	info_layout->setSpacing(0);
	info_layout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout* main_layout = new QHBoxLayout();
	main_layout->addWidget(renren_icon_label);
	main_layout->addLayout(info_layout);
	main_layout->addStretch();
	main_layout->addWidget(renren_login_label);
	main_layout->setSpacing(5);
	main_layout->setContentsMargins(30, 0, 20, 0);

	renren_widget->setLayout(main_layout);
}

void login_dialog::initSafeWidget()
{
	safe_widget = new QWidget(this);
	icon_label = new QLabel();
	safe_label = new QLabel();
	protect_label = new QLabel();

	safe_label->setAlignment(Qt::AlignRight | Qt::AlignBottom);
	protect_label->setAlignment(Qt::AlignRight | Qt::AlignTop);
	QFont safe_font = safe_label->font();
	safe_font.setPointSize(14);
	safe_label->setFont(safe_font);
	safe_label->setObjectName("whiteLabel");
	protect_label->setObjectName("whiteLabel");

	icon_label->setFixedSize(70, 70);
	icon_label->setPixmap(QPixmap("./Resources/img/360safe.png"));
	icon_label->setScaledContents(true);

	QVBoxLayout* info_layout = new QVBoxLayout();
	info_layout->addWidget(safe_label);
	info_layout->addWidget(protect_label);
	info_layout->addStretch();
	info_layout->setSpacing(5);
	info_layout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout* main_layout = new QHBoxLayout();
	main_layout->addWidget(icon_label);
	main_layout->addStretch();
	main_layout->addLayout(info_layout);
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(30, 0, 20, 0);

	safe_widget->setLayout(main_layout);
}

void login_dialog::translateLanguage()
{
	msg_box_->translateLanguage();  //重名修改msg_box_
	this->changeTitle();
	close_button->setToolTip(tr("close"));

	safe_label->setText(tr("360 safe"));
	protect_label->setText(tr("protect every day"));

	renren_info_label->setText(tr("renren"));
	renren_net_label->setText(tr("renren.com"));
	renren_login_label->setText(tr("login by renren"));

	account_label->setText(tr("account"));
	password_label->setText(tr("password"));
	other_account_label->setText(tr("other account"));
	register_button->setText(tr("register"));
	forgot_button->setText(tr("forgot"));
	login_button->setText(tr("login"));
	remember_check_box->setText(tr("remember"));
	auto_login_check_box->setText(tr("auto login"));

	sina_info_label->setText(tr("sina info"));
	sina_net_label->setText(tr("sina net"));
	sina_register_button->setText(tr("sina register"));
	examine_authorize_button->setText(tr("examine authorize"));
	authorize_button->setText(tr("authorize"));
	sina_login_check_box->setText(tr("sina login"));
	safe_attention_check_box->setText(tr("safe attention"));
	sina_account_line_edit->setPlaceholderText(tr("sina account"));
}

void login_dialog::paintEvent(QPaintEvent* event)
{
	drop_shadow_widget::paintEvent(event);
	bool is_sina = false;
	int width = this->width();
	int height = this->height();
	switch (login)
	{
	case SINA:
		is_sina = true;
		break;
	default:
		break;
	}

	int draw_height = 95;
	if (is_sina)
	{
		draw_height = 35;
	}

	QString skin_name = util::getSkinName();

	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width() - 2 * SHADOW_WIDTH, this->height() - 2 * SHADOW_WIDTH), QPixmap(skin_name));

	int sina_line = 0;
	if (is_sina)
	{
		sina_line = 3;
		QLinearGradient linear(rect().topLeft(), rect().bottomRight());
		linear.setColorAt(0, QColor(240, 30, 50));
		linear.setColorAt(0.2, QColor(240, 40, 50));
		linear.setColorAt(0.4, QColor(255, 50, 60));
		linear.setColorAt(0.6, QColor(255, 150, 10));
		linear.setColorAt(0.8, QColor(255, 180, 60));
		linear.setColorAt(1, QColor(255, 200, 120));

		QPainter painter2(this);
		painter2.setBrush(QBrush(linear));
		painter2.setPen(Qt::NoPen);
		painter2.drawRect(QRect(SHADOW_WIDTH, draw_height, width - 2 * SHADOW_WIDTH, sina_line));
	}

	QPainter painter3(this);
	painter3.setPen(Qt::NoPen);
	painter3.setBrush(Qt::white);
	painter3.drawRect(QRect(SHADOW_WIDTH, draw_height + sina_line, width - 2 * SHADOW_WIDTH, height - draw_height - sina_line - SHADOW_WIDTH));
}

void login_dialog::showAccount(QString account)
{
	account_combo_box->setEditText(account);
	account_combo_box->hidePopup();
}

void login_dialog::removeAccount(QString account)
{
	msg_box_->setInfo(tr("remove account"), tr("are you sure to remove account?"), QPixmap("./Resources/img/loginDialog/attention.png"), false);  //重名msg_box_
	if (msg_box_->exec() == QDialog::Accepted)    //重名
	{
		int list_count = list_widget->count();
		for (int i = 0; i < list_count; i++)
		{
			QListWidgetItem* item = list_widget->item(i);
			account_item* account_item_ = (account_item*)(list_widget->itemWidget(item));   //重名account_item_
			QString account_number = account_item_->getAccountNumber();	 //重名
			if (account == account_number)
			{
				list_widget->takeItem(i);
				delete item;

				break;
			}
		}
	}
	account_combo_box->hidePopup();
}

void login_dialog::verify()
{
	bool is_hidden = false;
	bool is_login_hidden = false;
	login = SAFE;
	QWidget* current_widget = login_stacked_layout->currentWidget();
	if (current_widget != loading_widget_)	//重名loading_widget_
	{
		login_button->setText(tr("cancel"));
		is_hidden = true;
		login_stacked_layout->setCurrentWidget(loading_widget_);			//
		loading_widget_->setAccount(account_combo_box->lineEdit()->text());	//
		loading_widget_->start(true);										//
	}
	else
	{
		login_button->setText(tr("login"));
		loading_widget_->start(false);										//
		login_stacked_layout->setCurrentWidget(safe_renren_center_widget);
		is_login_hidden = auto_login_check_box->isHidden();
	}

	if (is_login_hidden)
	{
		login = RENREN;
		stacked_layout->setCurrentWidget(renren_widget);
	}
	else
	{
		stacked_layout->setCurrentWidget(safe_widget);
	}
	changeTitle();
	other_account_label->setHidden(is_hidden);
	sina_button->setHidden(is_hidden);
	renren_button->setHidden(is_hidden);
}

void login_dialog::turnRenRen()
{
	switch (login)
	{
	case SAFE:
	{
		if (sina_login == SINA)
		{
			login = RENREN;
		}
		else
		{
			login = SINA;
		}
		this->changeTitle();
		this->turnWidget();
		renren_button->setIcon(QIcon("./Resources/img/safe.ico"));
	}
	break;
	case RENREN:
	{
		if (sina_login == SINA)
		{
			login = SAFE;
		}
		else
		{
			login = SINA;
		}
		this->changeTitle();
		this->turnWidget();
		renren_button->setIcon(QIcon("./Resources/img/loginDialog/renren.png"));
	}
	break;
	case SINA:
	{
		if (sina_login == SAFE)
		{
			login = RENREN;
		}
		else
		{
			login = SAFE;
		}
		this->changeTitle();
		this->turnWidget();
		renren_button->setIcon(QIcon("./Resources/img/loginDialog/sina.png"));
	}
	break;

	default:
		break;
	}
}

void login_dialog::turnSina()
{
	switch (login)
	{
	case SAFE:
	{
		if (sina_login == SINA)
		{
			login = SINA;
		}
		else
		{
			login = RENREN;
		}
		this->changeTitle();
		this->turnWidget();
		sina_login = SAFE;
		sina_button->setIcon(QIcon("./Resources/img/safe.ico"));
	}
	break;
	case RENREN:
	{
		if (sina_login == SINA)
		{
			login = SINA;
		}
		else
		{
			login = SAFE;
		}
		this->changeTitle();
		this->turnWidget();
		sina_login = RENREN;
		sina_button->setIcon(QIcon("./Resources/img/loginDialog/renren.png"));
	}
	break;
	case SINA:
	{
		if (sina_login == SAFE)
		{
			login = SAFE;
			update();
		}
		else
		{
			login = RENREN;
		}
		this->changeTitle();
		this->turnWidget();
		sina_login = SINA;
		sina_button->setIcon(QIcon("./Resources/img/loginDialog/sina.png"));
	}
	break;
	default:
		break;
	}
}

void login_dialog::changeTitle()
{
	switch (login)
	{
	case SAFE:
		title_label->setText(tr("360 safe login"));
		break;
	case SINA:
		title_label->setText(tr("login by sina"));
		break;
	case RENREN:
		title_label->setText(tr("login by renren"));
		break;

	default:
		title_label->setText(tr("360 safe login"));
	}
}

void login_dialog::turnWidget()
{
	switch (login)
	{
	case SAFE:
	{
		main_stacked_layout->removeWidget(sina_widget);
		this->resize(370, 275);
		QWidget* current_widget = main_stacked_layout->currentWidget();
		if (current_widget != safe_renren_widget)
		{
			main_stacked_layout->setCurrentWidget(safe_renren_widget);
		}
		QWidget* stack_current_widget = stacked_layout->currentWidget();
		if (stack_current_widget != safe_widget)
		{
			stacked_layout->setCurrentWidget(safe_widget);
			register_button->show();
			forgot_button->show();
			auto_login_check_box->show();
		}
		login_button->show();
	}
	break;
	case SINA:
	{
		this->resize(400, 310);
		main_stacked_layout->addWidget(sina_widget);
		QWidget* current_widget = main_stacked_layout->currentWidget();
		if (current_widget == safe_renren_widget)
		{
			main_stacked_layout->setCurrentWidget(sina_widget);
			login_button->hide();
		}
	}
	break;
	case RENREN:
	{
		main_stacked_layout->removeWidget(sina_widget);
		this->resize(370, 275);
		QWidget* current_widget = main_stacked_layout->currentWidget();
		if (current_widget != safe_renren_widget)
		{
			main_stacked_layout->setCurrentWidget(safe_renren_widget);
		}
		QWidget* stack_current_widget = stacked_layout->currentWidget();
		if (stack_current_widget != renren_widget)
		{
			stacked_layout->setCurrentWidget(renren_widget);
			register_button->hide();
			forgot_button->hide();
			auto_login_check_box->hide();
		}
		login_button->show();
	}
	break;

	default:
		break;
	}
}
