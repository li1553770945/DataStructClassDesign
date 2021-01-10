
#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include "Btree.h"
BTree*  ancestor;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ancestor = new BTree(3);
    MainWindow w;
    w.show();
    return a.exec();
}