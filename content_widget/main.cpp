#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/QTranslator>
#include "title_widget.h"
#include "content_widget.h"
#include "setting_dialog.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QTextCodec* codec = QTextCodec::codecForName("System");
	QTextCodec::setCodecForLocale(codec);						//��ȡϵͳ����
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

	//title_widget wt;
	//wt.show();
	setting_dialog sd;
	sd.show();

	//content_widget wc;
	//wc.show();

	return a.exec();
}
