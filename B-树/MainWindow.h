#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "Btree.h"
#include "tree.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    Ui::MainWindowClass ui;
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();
    void draw(BTreeNode*);
    void resizeEvent(QResizeEvent* event);
    Tree* tree;
public slots:
    void on_Find_clicked();
    void on_Insert_clicked();
    void on_Delete_clicked();

};
