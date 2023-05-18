#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QEventLoop>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTimer *timer = new QTimer(this);

    char temp, persent;
    QString displayStr="0";
    double i=0,j=0;
    Ui::MainWindow *ui;
    void delay(int);
private slots:
    void add_to_display();

    /*void operations();*/
};

