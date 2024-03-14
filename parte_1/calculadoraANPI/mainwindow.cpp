#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "anpi2/anpi2/funtras.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    bool xSelected = false;
    bool ySelected = false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputSelected(bool selectedBox, QString num){
    if (selectedBox){
        QString tempText = ui->xInputField->toPlainText();
        tempText.append(num);
        ui->xInputField->setPlainText(tempText);
    } else {
        QString tempText = ui->yInputField->toPlainText();
        tempText.append(num);
        ui->yInputField->setPlainText(tempText);
    }
}

void MainWindow::on_helpButton_clicked()
{
    ui->resultLabel->setText("ayuda");
}


void MainWindow::on_pushButton_clicked()
{
    ui->resultTextBrowser->clear();
    ui->xInputField->clear();
    ui->yInputField->clear();
    // TODO: limpiar las variables en la logica
}

void MainWindow::on_senhButton_clicked()
{
    //Fun_tras result_senh;
    // castear el plainText
    //cpp_dec_float_50 result = result_senh.exp_t(2);
    //cout << setprecision(std::numeric_limits<cpp_dec_float_50>::max_digits10) << result << endl;

}
void MainWindow::on_tanhButton_clicked()
{

}


void MainWindow::on_coshButton_clicked()
{

}


void MainWindow::on_asenButton_clicked()
{

}


void MainWindow::on_acosButton_clicked()
{

}


void MainWindow::on_atanButton_clicked()
{

}


void MainWindow::on_secButton_clicked()
{

}


void MainWindow::on_cscButton_clicked()
{

}


void MainWindow::on_cotButton_clicked()
{

}


void MainWindow::on_senButton_clicked()
{

}


void MainWindow::on_cosButton_clicked()
{

}


void MainWindow::on_tanButton_clicked()
{

}


void MainWindow::on_lnButton_clicked()
{

}


void MainWindow::on_logTenButton_clicked()
{

}


void MainWindow::on_logYButton_clicked()
{

}


void MainWindow::on_divButton_clicked()
{

}


void MainWindow::on_sqrButton_clicked()
{

}


void MainWindow::on_sqrYButton_clicked()
{

}


void MainWindow::on_expButton_clicked()
{

}


void MainWindow::on_powerYButton_clicked()
{

}


void MainWindow::on_factorialButton_clicked()
{

}


void MainWindow::on_sevenButton_clicked()
{
    inputSelected(this->xSelected, "7");
}


void MainWindow::on_eightButton_clicked()
{
    inputSelected(this->xSelected, "8");
}


void MainWindow::on_nineButton_clicked()
{
    inputSelected(this->xSelected, "9");
}


void MainWindow::on_fourButton_clicked()
{
    inputSelected(this->xSelected, "4");
}


void MainWindow::on_fiveButton_clicked()
{
    inputSelected(this->xSelected, "5");
}


void MainWindow::on_sixButton_clicked()
{
    inputSelected(this->xSelected, "6");
}


void MainWindow::on_oneButton_clicked()
{
    inputSelected(this->xSelected, "1");
}


void MainWindow::on_twoButton_clicked()
{
    inputSelected(this->xSelected, "2");
}


void MainWindow::on_threeButton_clicked()
{
    inputSelected(this->xSelected, "3");
}


void MainWindow::on_piButton_clicked()
{
    inputSelected(this->xSelected, "π");
}


void MainWindow::on_zeroButton_clicked()
{
    inputSelected(this->xSelected, "0");
}


void MainWindow::on_pushButton_23_clicked()
{

}


void MainWindow::on_xSelectionButton_clicked()
{
    this->xSelected = true;
}


void MainWindow::on_pushButton_2_clicked()
{
    this->xSelected = false;
}

