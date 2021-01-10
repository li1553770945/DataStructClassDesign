#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_InfoWindow.h"
#include "familytree.h"
class InfoWindow : public QDialog
{
    Q_OBJECT

public slots:
    void InfoWindow::Receive(People* node);
    void on_ButtonConfirm_clicked();
public:
   InfoWindow(QWidget* parent = Q_NULLPTR);
   People* people;
   void set_data();

private:
   
    Ui::InfoWindowClass ui;
};

