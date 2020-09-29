/*#include "content_widget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    content_widget w;
    w.show();
    return a.exec();
}*/

#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/QTranslator>
#include"title_widget.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QTextCodec* codec = QTextCodec::codecForName("System");
	QTextCodec::setCodecForLocale(codec);
	//可以对界面中的菜单栏,label,对话框等进行翻译
	QTranslator translator;
	translator.load(QString(":/qm/qt_zh_CN"));
	a.installTranslator(&translator);

	QTranslator translator_zh;
	translator_zh.load(QString(":/qm/360safe_zh"));
	a.installTranslator(&translator_zh);

	//加载QSS样式表
	QFile qss(":/qss/360safe");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();


	title_widget w;
	w.show();

	return a.exec();
}
