#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/QTranslator>
#include "title_widget.h"
#include "content_widget.h"
#include "setting_dialog.h"
#include "about_us.h"
#include "character_widget.h"
#include "skin_widget.h"
#include "login_dialog.h"

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

	login_dialog ld;
	ld.show();

	//content_widget wc;
	//wc.show();

	return a.exec();
}
