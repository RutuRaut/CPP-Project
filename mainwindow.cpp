#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
       ui->setupUi(this);


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

       connect(ui->PlusPushButton, &QPushButton::clicked, this, &MainWindow::OnPushButtonPlusClicked);
        connect(ui->MulPushButton, &QPushButton::clicked, this, &MainWindow::OnPushButtonMulClicked);
        connect(ui->MinusPushButton, &QPushButton::clicked, this, &MainWindow::OnPushButtonMinuslCicked);
        connect(ui->DivPushButton, &QPushButton::clicked, this, &MainWindow::OnPushButtonDivClicked);
        connect(ui->EqualPushButton, &QPushButton::clicked, this, &MainWindow::OnPushButtonEqualClicked);
        connect(ui->ModlusPushButton, &QPushButton::clicked, this, &MainWindow::OnPushButtonModulusClicked);
        connect(ui->BackPushButton, &QPushButton::clicked, this, &MainWindow::OnBackspaceClicked);
        connect(ui->DotPushButton, &QPushButton::clicked, this, &MainWindow::OnPushButtonDotClicked);



}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::OnNumberButtonClicked()
//{
//    QPushButton *button = qobject_cast<QPushButton*>(sender());
//    if (button) {
//        QString buttonText = button->text();
//        QString displayText = ui->lineEdit_2->text();

//         if (displayText == "0" || operationPerformed)
//         {
//               ui->lineEdit_2->setText(buttonText);
//              operationPerformed = false; // Reset operationPerformed flag
//          }
//         else
//         {
//             ui->lineEdit_2->setText(ui->lineEdit_2->text() + buttonText);
//         }
//     }
//}
void MainWindow::OnNumberButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonText = button->text();
        QString displayText = ui->lineEdit_2->text();

        if (displayText == "0" || operationPerformed)
        {
            ui->lineEdit_2->setText(""); // Clear the display if needed
            ui->lineEdit_2->setText(buttonText);
            operationPerformed = false; // Reset operationPerformed flag
        }
        else
        {
            ui->lineEdit_2->setText(ui->lineEdit_2->text() + buttonText);
        }
    }
}


void MainWindow::OnPushButtonDotClicked()
{
    QString currentText = ui->lineEdit_2->text();
    if (currentText.isEmpty() || currentText.right(1) != ".")
    {
        ui->lineEdit_2->setText(currentText + ".");
    }
}
//void MainWindow::OnPushButtonPlusClicked()
//{
//    QString currentText = ui->lineEdit_2->text();
//    if (currentText.isEmpty() || currentText.right(1) != "+")
//    {
//        ui->lineEdit_2->setText(currentText + "+");
//    }
//}
void MainWindow::OnPushButtonPlusClicked()
{
    if (operationPerformed) {
        ui->lineEdit_2->setText(QString::number(previousResult)); // Use previous result
        operationPerformed = false; // Reset operationPerformed flag
    }

    QString currentText = ui->lineEdit_2->text();
    if (currentText.isEmpty() || currentText.right(1) != "+")
    {
        ui->lineEdit_2->setText(currentText + "+");
    }
}
void MainWindow::OnPushButtonMulClicked()
{
   QString currentText = ui->lineEdit_2->text();
    if (currentText.isEmpty() || currentText.right(1) != "×")
    {
        ui->lineEdit_2->setText(currentText + "×");
    }
}
void MainWindow::OnPushButtonMinuslCicked()
{
    QString currentText = ui->lineEdit_2->text();
    if (currentText.isEmpty() || currentText.right(1) != "-")
    {
        ui->lineEdit_2->setText(currentText + "-");
    }
}
void MainWindow::OnPushButtonDivClicked()
{
  QString currentText = ui->lineEdit_2->text();
  if (currentText.isEmpty() || currentText.right(1) != "÷")
  {
      ui->lineEdit_2->setText(currentText + "÷");
  }
}
void MainWindow::OnPushButtonModulusClicked()
{
  QString currentText = ui->lineEdit_2->text();
  if (currentText.isEmpty() || currentText.right(1) != "%")
  {
      ui->lineEdit_2->setText(currentText + "%");
  }
}
void MainWindow::OnBackspaceClicked()
{
    QString text = ui->lineEdit_2->text();
        if (!text.isEmpty()) {
            text.chop(1); // Remove the last character
            ui->lineEdit_2->setText(text);
        }
}
void MainWindow::OnPushButtonEqualClicked()
{
    // Implementation of OnPushButtonEqualClicked function
    QString expression = ui->lineEdit_2->text();
    double result = evaluateExpression(expression);

    if (!std::isnan(result)) {
        // Update line edit with the result
        ui->lineEdit_2->setText(QString::number(result));

        // Store the result as the current number for the next calculation
        currentNumber = result;

        // Reset flags for next input
        pendingOperation = "";
        waitingForOperand = false;
    } else {
        // Display an error message for invalid expressions
        ui->lineEdit_2->setText("Error: Invalid expression");

        // Reset flags to avoid unexpected behavior
        currentNumber = 0.0;
        pendingOperation = "";
        waitingForOperand = true;
    }
}
double MainWindow::evaluateExpression(const QString &expression)
{
    // Split the expression into parts
    QStringList parts = expression.split(QRegExp("([+\\-*/%^])"), QString::SkipEmptyParts);

    // If the expression contains an operator
    if (parts.size() == 2) {
        // Extract the operator and operands
        QString op = expression.mid(parts.at(0).size(), 1);
        double num1 = parts.at(0).toDouble();
        double num2 = parts.at(1).toDouble();

        // Check for division by zero
        if (op == "/" && num2 == 0.0) {
            // Return a special value indicating division by zero
            return std::numeric_limits<double>::infinity();
        }

        // Perform the operation
        double result = 0.0;

        if (op == "+")
            result = num1 + num2;
        else if (op == "-")
            result = num1 - num2;
        else if (op == "*")
            result = num1 * num2;
        else if (op == "/")
            result = num1 / num2;
        else if (op == "%")
            result = fmod(num1, num2);

        return result;
    } else {
        // Invalid expression
        return std::numeric_limits<double>::quiet_NaN();
    }
}

//double MainWindow::evaluateExpression(const QString &expression)
//{
//    // Split the expression into parts

//    QStringList parts = expression.split(QRegExp("([+\\-×÷%])"), QString::SkipEmptyParts);

//    // If the expression does not contain two parts or operator not recognized, return NaN
//    if (parts.size() != 2) {
//        return std::numeric_limits<double>::quiet_NaN();
//    }

//    // Extract the operator and operands
//    QString op = expression.mid(parts.at(0).size(), 1);
//    double num1 = parts.at(0).toDouble();
//    double num2 = parts.at(1).toDouble();

//    // Check for division by zero
//    if ((op == "÷" || op == "%") && num2 == 0.0) {
//        return std::numeric_limits<double>::quiet_NaN(); // Return NaN for undefined operation
//    }

//    // Perform the operation
//    double result = 0.0;

//    if (op == "+")
//        result = num1 + num2;
//    else if (op == "-")
//        result = num1 - num2;
//    else if (op == "×")
//        result = num1 * num2;
//    else if (op == "÷")
//        result = num1 / num2;
//    else if (op == "%")
//        result = fmod(num1, num2);
//    return result;
//}

