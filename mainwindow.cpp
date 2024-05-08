#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QStringList>
#include <QRegExp>
//double firstOperand = 0.0;
QString currentOperator;
bool operationPerformed = false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   ui->DisplaylEdit->setText("0");
   connect(ui->PushButton0, &QPushButton::clicked, this, &MainWindow::OnNumberButtonClicked);
   connect(ui->PushButton1, &QPushButton::clicked, this, &MainWindow::OnNumberButtonClicked);
   connect(ui->PushButton2, &QPushButton::clicked, this, &MainWindow::OnNumberButtonClicked);
   connect(ui->PushButton3, &QPushButton::clicked, this, &MainWindow::OnNumberButtonClicked);
   connect(ui->PushButton4, &QPushButton::clicked, this, &MainWindow::OnNumberButtonClicked);
   connect(ui->PushButton5, &QPushButton::clicked, this, &MainWindow::OnNumberButtonClicked);
   connect(ui->PushButton6, &QPushButton::clicked, this, &MainWindow::OnNumberButtonClicked);
   connect(ui->PushButton7, &QPushButton::clicked, this, &MainWindow::OnNumberButtonClicked);
   connect(ui->PushButton8, &QPushButton::clicked, this, &MainWindow::OnNumberButtonClicked);
   connect(ui->PushButton9, &QPushButton::clicked, this, &MainWindow::OnNumberButtonClicked);

   connect(ui->PushButtonPlus, &QPushButton::clicked, this, &MainWindow::OnPushButtonPlusClicked);
   connect(ui->PushButtonMul, &QPushButton::clicked, this, &MainWindow::OnPushButtonMulClicked);
   connect(ui->PushButtonMinus, &QPushButton::clicked, this, &MainWindow::OnPushButtonMinuslCicked);
   connect(ui->PushButtonDivision, &QPushButton::clicked, this, &MainWindow::OnPushButtonDivClicked);
   connect(ui->PushButtonEqual, &QPushButton::clicked, this, &MainWindow::OnPushButtonEqualClicked);
   connect(ui->PushButtonModulus, &QPushButton::clicked, this, &MainWindow::OnPushButtonModulusClicked);
   connect(ui->PushButtonBack, &QPushButton::clicked, this, &MainWindow::OnBackspaceClicked);
   connect(ui->PushButtonDot, &QPushButton::clicked, this, &MainWindow::OnPushButtonDotClicked);

}
MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::OnNumberButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonText = button->text();
        QString displayText = ui->DisplaylEdit->text();

         if (displayText == "0" || operationPerformed)
         {
               ui->DisplaylEdit->setText(buttonText);
              operationPerformed = false; // Reset operationPerformed flag
          }
         else
         {
             ui->DisplaylEdit->setText(ui->DisplaylEdit->text() + buttonText);
         }
     }
}
void MainWindow::OnPushButtonDotClicked()
{

    QString currentText = ui->DisplaylEdit->text();
    if (currentText.isEmpty() || currentText.right(1) != ".")
    {
        ui->DisplaylEdit->setText(currentText + ".");
    }
}
void MainWindow::OnPushButtonPlusClicked()
{

    QString currentText = ui->DisplaylEdit->text();
    if (currentText.isEmpty() || currentText.right(1) != "+")
    {
        ui->DisplaylEdit->setText(currentText + "+");
    }
}

void MainWindow::OnPushButtonMulClicked()
{
   QString currentText = ui->DisplaylEdit->text();
    if (currentText.isEmpty() || currentText.right(1) != "×")
    {
        ui->DisplaylEdit->setText(currentText + "×");
    }
}
void MainWindow::OnPushButtonMinuslCicked()
{
    QString currentText = ui->DisplaylEdit->text();
    if (currentText.isEmpty() || currentText.right(1) != "-")
    {
        ui->DisplaylEdit->setText(currentText + "-");
    }
}
void MainWindow::OnPushButtonDivClicked()
{

  QString currentText = ui->DisplaylEdit->text();
  if (currentText.isEmpty() || currentText.right(1) != "÷")
  {
      ui->DisplaylEdit->setText(currentText + "÷");
  }
}

void MainWindow::OnPushButtonModulusClicked()
{


  QString currentText = ui->DisplaylEdit->text();
  if (currentText.isEmpty() || currentText.right(1) != "%")
  {
      ui->DisplaylEdit->setText(currentText + "%");
  }

}
void MainWindow::OnBackspaceClicked()
{
    QString text = ui->DisplaylEdit->text();
        if (!text.isEmpty()) {
            text.chop(1); // Remove the last character
            ui->DisplaylEdit->setText(text);
        }
}

void MainWindow::OnPushButtonEqualClicked()
{
    QString expression = ui->DisplaylEdit->text();
    double result = evaluateExpression(expression);
    ui->DisplaylEdit->setText(QString::number(result));
}

double MainWindow::evaluateExpression(const QString &expression)
{
  
    QStringList parts = expression.split(QRegExp("([+\\-×÷%])"), QString::SkipEmptyParts);
    QString op = expression.mid(parts.at(0).size(), 1);
    double num1 = parts.at(0).toDouble();
    double num2 = parts.at(1).toDouble();

     double result = 0.0;
    if (op == "+")
        result = num1 + num2;
    else if (op == "-")
        result = num1 - num2;
    else if (op == "×")
        result = num1 * num2;
    else if (op == "÷")
        result = num1 / num2;
    else if (op == "%")
        result = fmod(num1, num2);

    return result;
}


