#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include "push_button.h"
#include "util.h"
#include "drop_shadow_widget.h"

class register_widget : public drop_shadow_widget
{
	Q_OBJECT

public:
	explicit register_widget(QWidget* parent = 0);
	~register_widget();
	void translateLanguage();

protected:
	void paintEvent(QPaintEvent* event);

private:
	QLabel* title_label;
	push_button* close_button;
	QLabel* icon_label;
	QLabel* register_label;
	QLabel* privilege_label;
	QLabel* email_label;
	QLabel* password_label;
	QLabel* confirm_password_label;
	QLineEdit* email_line_edit;
	QLineEdit* password_line_edit;
	QLineEdit* confirm_line_edit;
	QLabel* tip_email_label;
	QLabel* tip_password_label;
	QLabel* tip_confirm_label;
	QCheckBox* remember_check_box;
	QCheckBox* auto_login_check_box;
	QLabel* account_label;
	QPushButton* login_button;
	QPushButton* register_button;
};
