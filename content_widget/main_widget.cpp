#include "main_widget.h"
#include "util.h"

main_widget::main_widget(QWidget* parent)
	: drop_shadow_widget(parent)
{
	initLocalConnection();
	setMinimumSize(900, 600);
	setWindowIcon(QIcon("./Resources/img/safe.png"));

	statked_widget = new QStackedWidget();
	m_title_widget = new title_widget();
	m_content_widget = new content_widget();
	m_kill_mummy_widget = new kill_mummy_widget();
	m_main_menu = new main_menu();
	m_character_widget = new character_widget();
	m_about_us_dialog = new about_us_dialog(this);
	m_setting_dialog = new setting_dialog(this);
	m_login_dialog = new login_dialog(this);
	m_register_widget = new register_widget(this);
	m_skin_widget = new skin_widget(this);
	m_system_tray = new system_tray(this);

	QPalette palette;
	palette.setBrush(QPalette::Window, QBrush(Qt::white));
	statked_widget->setPalette(palette);
	statked_widget->setAutoFillBackground(true);

	statked_widget->addWidget(m_content_widget);
	statked_widget->addWidget(m_kill_mummy_widget);

	QVBoxLayout* center_layout = new QVBoxLayout();
	center_layout->addWidget(statked_widget);
	center_layout->setSpacing(0);
	center_layout->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout* main_layout = new QVBoxLayout();
	main_layout->addWidget(m_title_widget);
	main_layout->addLayout(center_layout);
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

	setLayout(main_layout);

	connect(m_title_widget, SIGNAL(showSkin()), this, SLOT(showSkinWidget()));
	connect(m_title_widget, SIGNAL(showMainMenu()), this, SLOT(showMainMenu()));
	connect(m_title_widget, SIGNAL(showMin()), this, SLOT(showMinimized()));
	connect(m_title_widget, SIGNAL(closeWidget()), this, SLOT(hide()));
	connect(m_title_widget, SIGNAL(turnPage(int)), this, SLOT(turnPage(int)));

	connect(m_main_menu, SIGNAL(showSettingDialog()), this, SLOT(showSettingDialog()));
	connect(m_main_menu, SIGNAL(showNewCharacter()), this, SLOT(showNewCharacter()));
	connect(m_main_menu, SIGNAL(showAboutUs()), this, SLOT(showAboutUs()));

	connect(m_content_widget, SIGNAL(showLoginDialog()), this, SLOT(showLoginDialog()));
	connect(m_content_widget, SIGNAL(showRegisterDialog()), this, SLOT(showRegisterDialog()));

	connect(m_setting_dialog, SIGNAL(changeLanguage(LANGUAGE)), this, SLOT(changeLanguage(LANGUAGE)));

	connect(m_skin_widget, SIGNAL(changeSkin(QString)), this, SLOT(changeSkin(QString)));

	connect(m_system_tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));
	connect(m_system_tray, SIGNAL(showWidget()), this, SLOT(showWidget()));

	m_system_tray->show();

	m_title_widget->turnPage("0");

	skin_name = util::getSkinName();
	if (QString::compare(skin_name, QString("")) == 0)
	{
		this->changeSkin(DEFAULT_SKIN);
	}
}

main_widget::~main_widget()
{

}

void main_widget::turnPage(int current_page)
{
	if (current_page == 0)
	{
		statked_widget->setCurrentWidget(m_content_widget);
	}
	else if (current_page == 1)
	{
		statked_widget->setCurrentWidget(m_kill_mummy_widget);
	}
}

void main_widget::initLocalConnection()
{
	/*
	is_running = false;
	QCoreApplication::setApplicationName("localserver");
	QString serverName = QCoreApplication::applicationName();

	QLocalSocket socket;
	socket.connectToServer(serverName);

	if (socket.waitForConnected(500))
	{
		is_running = true;

		return;
	}

	//连接不上服务器，就创建一个
	server = new QLocalServer(this);
	connect(server, SIGNAL(newConnection()), this, SLOT(newLocalConnection()));
	if (server->listen(serverName))
	{
		//防止程序崩溃时,残留进程服务,移除之  
		if (server->serverError() == QAbstractSocket::AddressInUseError && QFile::exists(server->serverName()))
		{
			QFile::remove(server->serverName());
			server->listen(serverName);
		}
	}
	*/
}

void main_widget::newLocalConnection()
{
	QLocalSocket* socket = server->nextPendingConnection();
	if (!socket)
		return;

	socket->waitForReadyRead(1000);

	delete socket;
}


bool main_widget::isRunning()
{
	return is_running;
}

void main_widget::paintEvent(QPaintEvent* event)
{
	drop_shadow_widget::paintEvent(event);
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width() - 2 * SHADOW_WIDTH, this->height() - 2 * SHADOW_WIDTH), QPixmap(skin_name));
}

void main_widget::showSkinWidget()
{
	m_skin_widget->show();
}

void main_widget::showMainMenu()
{
	//设置主菜单出现的位置
	QPoint p = rect().topRight();
	p.setX(p.x() - 90);
	p.setY(p.y() + 25);
	m_main_menu->exec(this->mapToGlobal(p));
}

void main_widget::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
		//点击托盘图标之后松开
	case QSystemTrayIcon::Trigger:
	{
		showWidget();
		break;
	}
	//双击托盘图标
	case QSystemTrayIcon::DoubleClick:
	{
		showWidget();
		break;
	}
	default:
		break;
	}
}

void main_widget::showWidget()
{
	this->showNormal();
	this->raise();
	this->activateWindow();
}

void main_widget::showAboutUs()
{
	m_about_us_dialog->exec();
}

void main_widget::showNewCharacter()
{
	m_character_widget->show();
}

void main_widget::showSettingDialog()
{
	m_setting_dialog->exec();
}

void main_widget::showLoginDialog()
{
	m_login_dialog->exec();
}

void main_widget::showRegisterDialog()
{
	m_register_widget->exec();
}

void main_widget::changeSkin(QString skin_name)
{
	util::writeInit(QString("./user.ini"), QString("skin"), skin_name);
	this->skin_name = skin_name;
	update();
}

void main_widget::setTranslator(QTranslator* translator)
{
	this->translator = translator;
}

void main_widget::changeLanguage(LANGUAGE language)
{
	if (current_language == language)
	{
		return;
	}
	current_language = language;

	switch (language)
	{
	case 0:			//0 UI_EN
		translator->load(QString("./Resources/360safe_en.qm"));
		break;

	case 1://1 UI_ZN
		translator->load(QString("./Resources/360safe_zh.qm"));
		break;

	default:
		translator->load(QString("./Resources/360safe_zh.qm"));
	}

	m_title_widget->translateLanguage();
	m_content_widget->translateLanguage();
	m_kill_mummy_widget->translateLanguage();
	m_main_menu->translateActions();
	m_character_widget->translateLanguage();
	m_login_dialog->translateLanguage();
	m_register_widget->translateLanguage();
	m_character_widget->translateLanguage();
	m_about_us_dialog->translateLanguage();
	m_setting_dialog->translateLanguage();
	m_skin_widget->translateLanguage();
	m_system_tray->translateLanguage();
}

