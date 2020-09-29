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
#include "title_widget.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QTextCodec* codec = QTextCodec::codecForName("System");
	QTextCodec::setCodecForLocale(codec);
	//���ԶԽ����еĲ˵���,label,�Ի���Ƚ��з���
	QTranslator translator;
	translator.load(QString("./Resources/qt_zh_CN.qm"));
	a.installTranslator(&translator);

	QTranslator translator_zh;
	translator_zh.load(QString("./Resources/360safe_zh.qm"));
	a.installTranslator(&translator_zh);

	//����QSS��ʽ��
	QFile qss("./Resources/360safe.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();


	title_widget w;
	w.show();

	return a.exec();
}
