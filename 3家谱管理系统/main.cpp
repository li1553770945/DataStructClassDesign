﻿
#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include "familytree.h"
Node* ancestor = NULL;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ancestor = load();
    MainWindow w;
    w.show();
    return a.exec();
}