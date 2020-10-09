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

	QLabel* background_label; //背景图片
	int current_index; //当前图片下标
	QLabel* total_label; //图片（结合体）
	CLabel* label_array[4]; //存储图片的数组
	push_button* close_button; //关闭按钮
};
