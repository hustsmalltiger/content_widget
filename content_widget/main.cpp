#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/QTranslator>
#include <QSharedMemory>
#include "main_widget.h"


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QTextCodec* codec = QTextCodec::codecForName("System");
	QTextCodec::setCodecForLocale(codec);						//获取系统编码
	//可以对界面中的菜单栏,label,对话框等进行翻译
	QTranslator translator;
	translator.load(QString("./Resources/qt_zh_CN.qm"));
	a.installTranslator(&translator);

	QTranslator translator_zh;
	translator_zh.load(QString("./Resources/360safe_zh.qm"));
	a.installTranslator(&translator_zh);

	//加载QSS样式表
	QFile qss("./Resources/360safe.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();

	//title_widget wt;
	//wt.show();

	//setting_dialog sd;
	//sd.show();

	//about_us_dialog aud;
	//aud.show();

	//character_widget w_character;
	//w_character.show();

	//skin_widget w_skin;
	//w_skin.show();

	//login_dialog ld;
	//ld.show();

	//content_widget wc;
	//wc.show();

	//register_widget wr;
	//wr.show();



	QSharedMemory shared_memory;
	shared_memory.setKey(QString("main_window"));

	if (shared_memory.attach())
	{
		return 0;
	}

	if (shared_memory.create(1))
	{
		main_widget m_main_widget;
		m_main_widget.setTranslator(&translator_zh);
		m_main_widget.showWidget();

		return a.exec();
	}



	//return a.exec();
}
