#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Valores iniciais:
    ui->dialTotal->setValue(DEF_TOTAL);
    ui->Total->setValue(DEF_TOTAL);
    ui->dialDosagem->setValue(DEF_DOSAGEM);
    ui->DosagemObjetivo->setValue(DEF_DOSAGEM);
    ui->dialPG->setValue(DEF_PG);
    ui->PercentualPG->setValue(DEF_PG);
    ui->dialVG->setValue(DEF_VG);
    ui->PercentualVG->setValue(DEF_VG);
    ui->sliderNic->setValue(DEF_NIC);
    ui->DosagemNIC->setValue(DEF_NIC);
    Refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Total_valueChanged(int)
{
    Refresh();
}

void MainWindow::Refresh()
{
    // Dados de entrada:
    double T = ui->Total->value();
    double PP = ui->PercentualPG->value() / 100.0;
    double DN = ui->DosagemNIC->value();
    double DO = ui->DosagemObjetivo->value();

    // Evitando divisão por zero:
    if(DN == 0.0)
    {
        ui->ResNIC->display(0);
        ui->ResPG->display(0);
        ui->ResVG->display(0);
        return;
    }

    // Cálculos:
    double P = -((DO-DN*PP)*T)/DN;
    double V = (1-PP)*T;
    double N = (DO*T)/DN;

    // Repassamos para a interface:
    ui->ResNIC->display(N);
    ui->ResPG->display(P);
    ui->ResVG->display(V);
}

void MainWindow::on_DosagemObjetivo_valueChanged(int)
{
    Refresh();
}

void MainWindow::on_PercentualPG_valueChanged(int)
{
    double PG = ui->PercentualPG->value();
    ui->PercentualVG->setValue(100-PG);
    Refresh();
}

void MainWindow::on_PercentualVG_valueChanged(int)
{
    double VG = ui->PercentualVG->value();
    ui->PercentualPG->setValue(100-VG);
    Refresh();
}

void MainWindow::on_DosagemNIC_valueChanged(int)
{
    Refresh();
}
