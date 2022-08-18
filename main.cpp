#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QResource::registerResource("icons.qrc");
    QApplication a(argc, argv);
    MainWindow w;
    a.setOrganizationName("anmolmadaik");
    a.setOrganizationDomain("https://github.com/anmolmadaik");
    a.setApplicationName("TextEditor");
    a.setApplicationDisplayName("TextEditor");
    a.setApplicationVersion("1.0");
    a.setWindowIcon(QIcon(":/icons/appicon.ico"));
    w.show();
    return a.exec();
}
