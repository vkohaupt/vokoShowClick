#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QvkShowClickDialog.h"
#include "QvkAnimateControl.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void slot_ponterOnOff();


private:
    Ui::MainWindow *ui;
    QvkAnimateControl *animateControl;
    QvkShowClickDialog *ShowClickDialog;
};
#endif // MAINWINDOW_H
