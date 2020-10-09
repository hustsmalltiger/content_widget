#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMouseEvent>

class account_item : public QWidget
{
	Q_OBJECT

public:
	explicit account_item(QWidget* parent = 0);
	~account_item();
	void setAccountNumber(QString account_text);
	QString getAccountNumber();

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

signals:
	void showAccount(QString account);
	void removeAccount(QString account_number_text);

private slots:
	void removeAccount();

private:
	QLabel* account_number;  //’À∫≈
	QPushButton* delede_button;  //…æ≥˝’À∫≈∞¥≈•
	bool mouse_press;

};
