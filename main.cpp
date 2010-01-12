#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QTextCodec"



using namespace std;
char validateChar(char c);

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("cp-1250"));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
