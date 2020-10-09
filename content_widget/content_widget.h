#pragma once
/******************************���봰���ʵ��**************************/
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

	void initLeft();
	void initRightTop();
	void initRightCenter();
	void initRightCenterFunction();
	void initRightBottom();
	void initRight();

protected:

	bool eventFilter(QObject* obj, QEvent* event);

signals:

	void showLoginDialog();
	void showRegisterDialog();

private:

	QSplitter* main_splitter;

	QWidget* left_widget;
	QLabel* label;
	QLabel* suggest_label;
	QLabel* system_safe_label;
	QPushButton* power_button; //������찴ť

	QSplitter* right_splitter;
	QWidget* right_widget;
	QWidget* right_top_widget;

	QPushButton* login_button; //��¼�ҵ�360�ʺ�
	QLabel* priv_label; //��שͼ��
	QLabel* info_label; //�����Ŷ�����ͼ��
	QLabel* privilege_label; //ת����Ȩ
	QPushButton* register_button; //10�����ע��
	QPushButton* safe_button; //��Ȩ��360�Ŷ�logo
	QPushButton* tab_button;  //��ȡ�Ŷ���������ͼ��
	QPushButton* pet_button;  //���ﰲ�о���
	QPushButton* lottery_button;  //���ڱ��������
	QPushButton* cloud_five_button;  //5G����
	QPushButton* caipiao_button;  //��Ʊ

	QWidget* right_center_widget;
	QToolButton* fireproof_button; //360����ǽ
	QToolButton* triggerman_button; //360����
	QToolButton* net_shop_button; //��������
	QLabel* line_label_1; //����
	QLabel* line_label_2; //����

	QWidget* right_center_function_widget;
	QLabel* function_label; //���ܴ�ȫ
	QPushButton* more_button; //����
	QList<QToolButton*> button_list;  //��ť����

	QWidget* right_bottom_widget;
	QLabel* icon_label; //��ͼ��
	QLabel* connect_label; //�ɹ������ư�ȫ
	QLabel* version_label; //�汾��
	QPushButton* version_button; //�汾����

};

