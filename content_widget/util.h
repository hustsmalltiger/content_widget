#pragma once

#include <QSettings>
#include <QFontMetrics>
#include "common.h"

class util
{
public:
	static bool writeInit(QString path, QString user_key, QString user_value);
	static bool readInit(QString path, QString user_key, QString& user_value);
	static bool updateText(QString text, int max_width, QString& elided_text);
	static QString getSkinName();
};