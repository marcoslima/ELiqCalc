#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

#define DEF_TOTAL 30
#define DEF_DOSAGEM 18
#define DEF_PG 60
#define DEF_VG 100-DEF_PG
#define DEF_NIC 100

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Total_valueChanged(int arg1);

    void on_DosagemObjetivo_valueChanged(int arg1);

    void on_PercentualPG_valueChanged(int arg1);

    void on_PercentualVG_valueChanged(int arg1);

    void on_DosagemNIC_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

private:
    void Refresh(void);
};

#endif // MAINWINDOW_H
