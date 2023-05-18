#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton0, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButton3, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButton4, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButton5, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButton6, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButton7, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButton8, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButton9, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButtonAddit, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButtonDot, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButtonAllClear, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButtonEqually, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButtonMinus, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButtonMultipl, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButtonDivision, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButtonPercent, SIGNAL(clicked()), this, SLOT(add_to_display()));
    connect(ui->pushButtonClear, SIGNAL(clicked()), this, SLOT(add_to_display()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::delay(int n)
{
    QEventLoop loop;
    timer->singleShot(n, &loop, SLOT(quit()));
    loop.exec();
}

void MainWindow::add_to_display()
{
    QPushButton *button = (QPushButton *)sender();

    if(button->text() == "=")
    {
        persent='0';
        QTextStream stream(&displayStr);
        stream >> i >> temp >> j >> persent;
        if(persent == '%')
            j=i/100*j;
        if(temp == '+')
        {
            i += j;
            displayStr = QString::number(i);
            ui->display->setText(displayStr);
        }else
        if(temp == '-')
        {
            i -= j;
            displayStr = QString::number(i);
            ui->display->setText(displayStr);
        }else
        if(temp == '/')
        {
            if(i == 0 && j > 0)
                ui->display->setText("0");
            else
            if(i > 0 && j == 0)
            {
                ui->display->setText("ERROR");
                delay(2000);
                ui->display->setText("0");
            }
            else
            {
                i /= j;
                displayStr = QString::number(i);
                ui->display->setText(displayStr);
            }
            i = 0, j = 0;
        }else
        if(temp == 'x')
        {
            i *= j;
            displayStr = QString::number(i);
            ui->display->setText(displayStr);
        }else
        if(temp == '=')
            ui->display->setText("0");
    }
    else
    if(button->text() == "AC")
    {
        displayStr = "0";
        i = 0, j = 0;
        ui->display->setText(displayStr);
    }else
    if(button->text() == "C")
    {
        if(ui->display->text().length() > 1)
            displayStr.chop(1);
        else
            displayStr = "0";
        ui->display->setText(displayStr);
    }
    else
    if((button->text() == "0" && ui->display->text() == '0')||
       (button->text() == "=" && ui->display->text() == '0'))
    {
        ui->display->setText("0");
    }
    else
        if((button->text() >= "1" && button->text() <= "9") && ui->display->text() == '0')
    {
        displayStr=button->text();
        ui->display->setText(displayStr);
    }
    else
    {
        displayStr += button->text();
        ui->display->setText(displayStr);
    }

}


