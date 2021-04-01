#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>

#include "./ui_mainwindow.h"
#include "handlers.h"
#include "draw.h"
#include "points.h"

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
    void on_loadButton_clicked();

    void on_moveButton_clicked();

    void on_scaleButton_clicked();
    
    void on_rotateButton_clicked();

    int on_draw(void);

private:
    Ui::MainWindow *ui;
};

#endif // __MAINWINDOW_H__
