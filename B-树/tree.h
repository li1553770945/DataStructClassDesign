#pragma once
#include <QtWidgets/QMainWindow>
#include <vector>
#include "Btree.h"
using namespace std;
class Area {
public:
    Area();
    Area(QPoint s, QPoint e);
    QPoint start, end;
};
class Tree :public QWidget {
public:
    
    Tree(QWidget* parent);
    vector<Area> area;
    void Tree::paintEvent(QPaintEvent* event);
};
