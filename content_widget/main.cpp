#include "content_widget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    content_widget w;
    w.show();
    return a.exec();
}
