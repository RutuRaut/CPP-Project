#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class Calculator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double evaluateExpression(const QString &expression);


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

private:
    Ui::MainWindow *ui;
    bool operationPerformed = false;


};

#endif // MAINWINDOW_H
