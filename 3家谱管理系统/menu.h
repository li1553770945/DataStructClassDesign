#pragma once
#include <qmenu.h>
#include "familytree.h"
#include "MainWindow.h"
class Menu :public QMenu {
    Q_OBJECT
signals:
    void Send(People*);
public:
    static MainWindow* main_prt;
    Menu(QWidget* p);
    Node* node;
public slots:
    void add_mate();
    void add_son();
    void del();
    void edit();
    void add_front();
    void add_back();
};