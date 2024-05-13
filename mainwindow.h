#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
   //double evaluateExpressionFromInput( double num1,double num2,QString op);
   double evaluateExpression(const QString &expression);
    double num1;
    double num2;
    double evaluateExpression(double num1, double num2, const QString &op);

private slots:
         void OnNumberButtonClicked();
    void OnPushButtonPlusClicked();
          void OnPushButtonMulClicked();
          void OnPushButtonMinuslCicked();
          void OnPushButtonDivClicked();
          void OnPushButtonEqualClicked();
          void OnPushButtonModulusClicked();
          void OnBackspaceClicked();
          void OnPushButtonDotClicked();
      //  void OnPushButtonOperationClicked(QString op);
          //void OnNextOperationClicked();
      //  void OnOperatorButtonClicked();
   //void OnPushButtonEqualClickedSecondTime();

private:
    Ui::MainWindow *ui;
    bool operationPerformed = false;
  double previousResult = 0.0;
//    double storedResult = 0.0;
     QString lastOperator;
     QString previousOperator;
     double previousNum2;
     QString operand1;
       QString operand2;

       double currentNumber; // <-- Here
          double result;       // <-- Here
          QString pendingOperation; // <-- Here
          bool waitingForOperand;


};
#endif // MAINWINDOW_H
