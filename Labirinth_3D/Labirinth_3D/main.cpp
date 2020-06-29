#include <QApplication>

#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOverrideCursor(QCursor(Qt::BlankCursor));

    Widget w;
    w.show();
    w.showFullScreen();

    return a.exec();
}
