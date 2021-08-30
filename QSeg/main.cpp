#include "framework.h"
#include "QSeg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSeg mainWnd;
    mainWnd.showMaximized();
    mainWnd.SetUIStyle();

    return a.exec();
}
