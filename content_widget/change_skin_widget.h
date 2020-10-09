#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QPainter>
#include <QPen>

class change_skin_widget : public QWidget
{
	Q_OBJECT

public:
	explicit change_skin_widget(QWidget* parent = 0);
	~change_skin_widget();
	void translateLanguage();
	QString getPixmapName();

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void enterEvent(QEvent* event);
	void leaveEvent(QEvent* event);
	void paintEvent(QPaintEvent* event);


signals:
	void changeSkin();

public slots:
	void changeSkin(QString pixmap_name, QString skin_name, QString download_count);

private slots:
	void useSkin();

private:
	QLabel* skin_label; //��ʾƤ��
	QLabel* skin_name_label; //��ʾƤ������
	QLabel* download_count_label; //��ʾ���ش���
	QPushButton* use_skin_button; //ʹ�ô�Ƥ����ť

	QString pixmap_name;
	bool mouse_press;
	bool mouse_enter;
};
