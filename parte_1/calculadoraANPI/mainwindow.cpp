#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "funtras.h"

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
    //Help helpWindow;
    //helpWindow.show();
   // helpWindow.setFixedSize(helpWindow.size());
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
    Fun_tras result_senh;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_senh.sinh_t(num);
    QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
        // en vez de 50 decimales
    ui->resultTextBrowser->setText(resultStr);
}

void MainWindow::on_tanhButton_clicked()
{
    Fun_tras result_tanh;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_tanh.tanh_t(num);
    QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
        // en vez de 50 decimales
    ui->resultTextBrowser->setText(resultStr);
}


void MainWindow::on_coshButton_clicked()
{
    Fun_tras result_cosh;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_cosh.cosh_t(num);
    QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
        // en vez de 50 decimales
    ui->resultTextBrowser->setText(resultStr);

}


void MainWindow::on_asenButton_clicked()
{
    Fun_tras result_asen;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_asen.asin_t(num);

    if (((-1 <= num) && (num <= 1))) {
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales
        ui->resultTextBrowser->setText(resultStr);
    }

    else {
       ui->resultTextBrowser->setText("Numero no esta en el dominio");
    }

}


void MainWindow::on_acosButton_clicked()
{
    Fun_tras result_acos;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();


    if ((-1 <= num) && (num <= 1)) {
        cpp_dec_float_50 result = result_acos.acos_t(num);
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales
        ui->resultTextBrowser->setText(resultStr);
    }

    else {
        ui->resultTextBrowser->setText("Numero no esta en el dominio");
    }
}

void MainWindow::on_atanButton_clicked()
{
    Fun_tras result_atan;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_atan.atan_t(num);
    QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
        // en vez de 50 decimales
    ui->resultTextBrowser->setText(resultStr);
}


void MainWindow::on_secButton_clicked()
{
    Fun_tras result_sec;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();

    if (result_sec.cos_t(num) == 0) {
        ui->resultTextBrowser->setText("Error: Coseno igual a 0");
    }
    else {
        cpp_dec_float_50 result = result_sec.sec_t(num);
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales
        ui->resultTextBrowser->setText(resultStr);
    }
}


void MainWindow::on_cscButton_clicked()
{
    Fun_tras result_csc;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    if (result_csc.sin_t(num) == 0) {
        ui->resultTextBrowser->setText("Error: Seno igual a 0");
    }
    else {
        cpp_dec_float_50 result = result_csc.csc_t(num);
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales
        ui->resultTextBrowser->setText(resultStr);
    }
}


void MainWindow::on_cotButton_clicked()
{
    Fun_tras result_cot;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    if (result_cot.sin_t(num) == 0) {
        ui->resultTextBrowser->setText("Error: Seno igual a 0");
    }
    else {
        cpp_dec_float_50 result = result_cot.cot_t(num);
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales
        ui->resultTextBrowser->setText(resultStr);
    }
}

void MainWindow::on_senButton_clicked()
{
    Fun_tras result_sen;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_sen.sin_t(num);
    QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
        // en vez de 50 decimales
    ui->resultTextBrowser->setText(resultStr);
}

void MainWindow::on_cosButton_clicked()
{
    Fun_tras result_cos;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_cos.cos_t(num);
    QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
        // en vez de 50 decimales
    ui->resultTextBrowser->setText(resultStr);
}

void MainWindow::on_tanButton_clicked()
{
    Fun_tras result_tan;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_tan.tan_t(num);
    QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
        // en vez de 50 decimales
    ui->resultTextBrowser->setText(resultStr);
}

void MainWindow::on_lnButton_clicked()
{
    Fun_tras result_ln;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    if (num <= 0) {
        ui->resultTextBrowser->setText("Error: x menor o igual a 0");
    }
    else {
        cpp_dec_float_50 result = result_ln.ln_t(num);
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales
        ui->resultTextBrowser->setText(resultStr);
    }
}


void MainWindow::on_logTenButton_clicked()
{
    Fun_tras result_logTen;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_logTen.log_t(num, 10);
    QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
        // en vez de 50 decimales
    ui->resultTextBrowser->setText(resultStr);
}


void MainWindow::on_logYButton_clicked()
{
    Fun_tras result_logY;
    // castear el plainText
    cpp_dec_float_50 x = ui->xInputField->toPlainText().toFloat();
    int y = ui->yInputField->toPlainText().toInt();
    cpp_dec_float_50 result = result_logY.log_t(x, y);

    if (result <= 0) {
        ui->resultTextBrowser->setText("Error: numero menor o igual a 0");
    }

    else {
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales
        ui->resultTextBrowser->setText(resultStr);
    }
}

void MainWindow::on_divButton_clicked()
{
    Fun_tras result_div;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    if (num > 0) {
        cpp_dec_float_50 result = result_div.divi_t(num);
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales

        ui->resultTextBrowser->setText(resultStr);
    }

    else {
        ui->resultTextBrowser->setText("Error: x menor o igual a 0");
    }


}

void MainWindow::on_sqrButton_clicked()
{
    Fun_tras result_sqr;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_sqr.sqrt_t(num);

    if (num > 0) {
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales
        ui->resultTextBrowser->setText(resultStr);
    }

    else {
      ui->resultTextBrowser->setText("Error: Índice o radicando menores a 0");
    }
}

void MainWindow::on_sqrYButton_clicked()
{
    Fun_tras result_sqrY;
    // castear el plainText
    cpp_dec_float_50 x = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 y = ui->yInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_sqrY.root_t(x, y);

    if ((x && y) > 0) {
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales
        ui->resultTextBrowser->setText(resultStr);
    }

    else {
        ui->resultTextBrowser->setText("Error: Índice o radicando menores a 0");
    }
}


void MainWindow::on_expButton_clicked()
{
    Fun_tras result_exp;
    // castear el plainText
    cpp_dec_float_50 num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_exp.exp_t(num);
    QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
        // en vez de 50 decimales
    ui->resultTextBrowser->setText(resultStr);
}


void MainWindow::on_powerYButton_clicked()
{
    Fun_tras result_power;
    // castear el plainText
    cpp_dec_float_50 x = ui->xInputField->toPlainText().toFloat();
    int y = ui->yInputField->toPlainText().toInt();
    cpp_dec_float_50 result = result_power.power_t(x, y);

    if (y <= 0) {
        ui->resultTextBrowser->setText("Error: numero menor o igual a 0");
    }

    else {
        QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
            // en vez de 50 decimales
        ui->resultTextBrowser->setText(resultStr);
    }
}

void MainWindow::on_factorialButton_clicked()
{
    Fun_tras result_fac;
    // castear el plainText
    int num = ui->xInputField->toPlainText().toFloat();
    cpp_dec_float_50 result = result_fac.factorial(num);
    QString resultStr = QString::fromStdString(result.str(50)); // El str(50) limita al resultado a 50 caracteres,
        // en vez de 50 decimales
    ui->resultTextBrowser->setText(resultStr);
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



void MainWindow::on_xSelectionButton_clicked()
{
    this->xSelected = true;
}


void MainWindow::on_pushButton_2_clicked()
{
    this->xSelected = false;
}


void MainWindow::on_decButton_clicked()
{
    inputSelected(this->xSelected, ".");
}

