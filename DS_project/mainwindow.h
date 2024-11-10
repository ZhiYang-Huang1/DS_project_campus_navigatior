#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMessageBox>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QDialog>
#include <QRegExpValidator>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn1_clicked();

    void on_CB_departure_currentTextChanged(const QString &arg1);

    void on_CB_destination_currentTextChanged(const QString &arg1);

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_btn10_clicked();

    void on_btn11_clicked();

    void on_btn12_clicked();

    void on_btn13_clicked();

    void on_btn14_clicked();

    void on_btn15_clicked();

    void on_btn16_clicked();

    void on_btn17_clicked();

    void on_btn18_clicked();

    void on_btn19_clicked();

    void on_btn20_clicked();

    void on_btn21_clicked();

    void on_btn22_clicked();

    void on_btn23_clicked();

    void on_btn24_clicked();

    void on_btn25_clicked();

    void on_btn26_clicked();

    void on_btn27_clicked();

    void on_btn28_clicked();

    void on_btn29_clicked();

    void on_btn30_clicked();

    void on_btn31_clicked();

    void on_btn32_clicked();

    void on_btn33_clicked();

    void on_ExitBtn_clicked();

private:
    Ui::MainWindow *ui;

private:
    void initUI();
};
#endif // MAINWINDOW_H
