#include "account_item.h"

account_item::account_item(QWidget* parent)
	: QWidget(parent)
{
	mouse_press = false;
	account_number = new QLabel();
	delede_button = new QPushButton();

	QPixmap pixmap("./Resources/img/loginDialog/delete.png");
	delede_button->setIcon(pixmap);
	delede_button->setIconSize(pixmap.size());
	delede_button->setStyleSheet("background:transparent;");
	connect(delede_button, SIGNAL(clicked()), this, SLOT(removeAccount()));

	QHBoxLayout* main_layout = new QHBoxLayout();
	main_layout->addWidget(account_number);
	main_layout->addStretch();
	main_layout->addWidget(delede_button);
	main_layout->setContentsMargins(5, 5, 5, 5);
	main_layout->setSpacing(5);
	this->setLayout(main_layout);
}

account_item::~account_item()
{

}

void account_item::setAccountNumber(QString account_text)
{
	account_number->setText(account_text);
}

QString account_item::getAccountNumber()
{
	QString account_number_text = account_number->text();

	return account_number_text;
}

void account_item::removeAccount()
{
	QString account_number_text = account_number->text();
	emit removeAccount(account_number_text);
}

void account_item::mousePressEvent(QMouseEvent* event)
{
	//只能是鼠标左键
	if (event->button() == Qt::LeftButton)
	{
		mouse_press = true;
	}
}

void account_item::mouseReleaseEvent(QMouseEvent* event)
{
	if (mouse_press && (this->rect()).contains(event->pos()))
	{
		emit showAccount(account_number->text());
	}
	mouse_press = false;
}