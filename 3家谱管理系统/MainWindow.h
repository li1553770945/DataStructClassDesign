#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "familytree.h"
#include "tree.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    Ui::MainWindowClass ui;
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();
    void draw(Node*);
    void resizeEvent(QResizeEvent* event);
    Tree* tree;
    Node* front,*back;
    void add_front(Node*);
    void add_back(Node*);
public slots:

    void on_ActionSave_triggered();//����excel
    void on_ButtonName_clicked();
    void on_ButtonDate_clicked();
    void on_ButtonRelative_clicked();
};
