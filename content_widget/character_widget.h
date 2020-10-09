#pragma once

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include "push_button.h"
#include "clabel.h"
#include "common.h"

class character_widget : public QWidget
{
	Q_OBJECT

public:
	explicit character_widget(QWidget* parent = 0);
	~character_widget();
	void translateLanguage();

	enum EButtonMouseState
	{
		EButtonMouseDefault = 0,
		EButtonMouseEnter,
		EButtonMousePress,
		EButtonMouseNone
	};

protected:
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void keyPressEvent(QKeyEvent*);

private slots:
	void changeCurrentPage(CLabel*);

private:
	void changeCurrentButton();
	void setLabelMove(bool);
	void moveCurrentPage(bool);

	QStringList name_list;
	QPoint m_mouseSrcPos;
	QPoint m_mouseDstPos;
	int current_pos_x;
	bool mouse_press;
	bool mouse_move;
	bool label_move;

	QLabel* background_label; //����ͼƬ
	int current_index; //��ǰͼƬ�±�
	QLabel* total_label; //ͼƬ������壩
	CLabel* label_array[4]; //�洢ͼƬ������
	push_button* close_button; //�رհ�ť
};
