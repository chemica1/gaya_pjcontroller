#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Pjlink for Huliac (v1.3)");

    w.show();

    w.FirstStep();
    w.SecondStep();
    w.FinalStepTimer();

    return a.exec();
}
