#include "widget.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb10_clicked()
{
    money += 10;
    ui->lcdNumber->display(money);
    changeMoney(money);
}

void MainWindow::on_pb50_clicked()
{
    money += 50;
    ui->lcdNumber->display(money);
    changeMoney(money);
}

void MainWindow::on_pb100_clicked()
{
    money += 100;
    ui->lcdNumber->display(money);
    changeMoney(money);
}

void MainWindow::on_pb500_clicked()
{
    money += 500;
    ui->lcdNumber->display(money);
    changeMoney(money);
}

void MainWindow::changeMoney (int diff)
{
    if (diff >= 100) {
        ui->pbCoffee->setEnabled(true);

        if (diff >= 150) {
            ui->pbTea->setEnabled(true);

            if (diff > 200) {
                ui->pbMilk->setEnabled(true);
            }
            else {
                ui->pbMilk->setEnabled(false);
            }

        }
        else {
            ui->pbTea->setEnabled(false);
            ui->pbMilk->setEnabled(false);
        }
    }
    else {
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }
}

void MainWindow::on_pbCoffee_clicked()
{
    money -= 100;
    ui->lcdNumber->display(money);
    changeMoney(money);
}

void MainWindow::on_pbTea_clicked()
{
    money -= 150;
    ui->lcdNumber->display(money);
    changeMoney(money);
}

void MainWindow::on_pbMilk_clicked()
{
    money -= 200;
    ui->lcdNumber->display(money);
    changeMoney(money);
}

void MainWindow::on_pbReset_clicked()
{
    QMessageBox m;
//    m.information(nullptr, "Reset",QString("%1 -> 0\nReset Success").arg(money));

    std::string won_500, won_100, won_50, won_10;
    won_500 = std::to_string(money/500);
    money %= 500;
    won_100 = std::to_string(money/100);
    money %= 100;
    won_50 = std::to_string(money/50);
    money %= 50;
    won_10 = std::to_string(money/10);
    money %= 10;

    std::string output = "500won => " + won_500 + "\n" +
            "100won => " + won_100 + "\n" +
            "50won => " + won_50 + "\n" +
            "10won => " + won_10;
    const char *op = output.c_str();
    m.information(nullptr, "notice", op);

    money = 0;
    ui->lcdNumber->display(money);
    changeMoney(money);
}
