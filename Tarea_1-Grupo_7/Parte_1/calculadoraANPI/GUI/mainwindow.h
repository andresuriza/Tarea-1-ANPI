#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "funtras.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool xSelected;
    void inputSelected(bool selectedBox, QString num);
    Fun_tras calc;

private slots:
    void on_senhButton_clicked();

    void on_helpButton_clicked();

    void on_pushButton_clicked();

    void on_tanhButton_clicked();

    void on_coshButton_clicked();

    void on_asenButton_clicked();

    void on_acosButton_clicked();

    void on_atanButton_clicked();

    void on_secButton_clicked();

    void on_cscButton_clicked();

    void on_cotButton_clicked();

    void on_senButton_clicked();

    void on_cosButton_clicked();

    void on_tanButton_clicked();

    void on_lnButton_clicked();

    void on_logTenButton_clicked();

    void on_logYButton_clicked();

    void on_divButton_clicked();

    void on_sqrButton_clicked();

    void on_sqrYButton_clicked();

    void on_expButton_clicked();

    void on_powerYButton_clicked();

    void on_factorialButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_piButton_clicked();

    void on_zeroButton_clicked();

    void on_xSelectionButton_clicked();

    void on_pushButton_2_clicked();

    void on_decButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
