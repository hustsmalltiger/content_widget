#include "tool_button.h"


tool_button::tool_button(QString pic_name, QWidget* parent)
	: QToolButton(parent)
{
	//初始化
	//设置文本颜色  一会总结用法(如电脑体验)
	QPalette text_palette = palette();
	text_palette.setColor(QPalette::ButtonText, QColor(30, 30, 30));
	setPalette(text_palette);

	//设置文本粗体
	QFont& text_font = const_cast<QFont&>(font());
	text_font.setWeight(QFont::Bold);
	//设置文字显示在图片的下面
	setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	//设置图标
	QPixmap pixmap(pic_name);
	setIcon(pixmap);
	setIconSize(pixmap.size());

	//设置大小
	setFixedSize(pixmap.width() + 25, pixmap.height() + 25);
	setAutoRaise(true);  //图标自动浮起
	setObjectName("transparentToolButton"); //设置对象名

	mouse_over = false;
	mouse_press = false;

}

tool_button::~tool_button()
{

}

void tool_button::enterEvent(QEvent*)
{
	mouse_over = true;
}

void tool_button::leaveEvent(QEvent*)
{
	mouse_over = false;
}

void tool_button::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit clicked();
	}
}

void tool_button::setMousePress(bool mouse_press)
{
	this->mouse_press = mouse_press;
	update();
}

void tool_button::paintEvent(QPaintEvent* event)
{
	if (mouse_over)
	{
		//绘制鼠标移到按钮上的按钮效果
		painterInfo(0, 100, 150);
	}
	else
	{
		if (mouse_press)
		{
			painterInfo(150, 100, 0);
		}
	}
	QToolButton::paintEvent(event);
}

//点击时,出现一个矩形框
void tool_button::painterInfo(int top_color, int middle_color, int botton_color)
{
	QPainter painter(this);
	QPen pen(Qt::NoBrush, 1);
	painter.setPen(pen);
	//指定一个线性渐变画笔
	QLinearGradient linear(rect().topLeft(), rect().bottomLeft());
	linear.setColorAt(0, QColor(230, 230, 230, top_color));
	linear.setColorAt(0.5, QColor(210, 210, 210, middle_color));
	linear.setColorAt(1, QColor(190, 190, 190, botton_color));

	painter.setBrush(linear);
	painter.drawRect(rect());
}
