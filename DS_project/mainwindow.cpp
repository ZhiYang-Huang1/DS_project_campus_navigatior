#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "info_dialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::initUI()
{
    ui->CB_departure->addItem("大学城校区(1-16)");
    ui->CB_departure->addItem("国际校区(17-33)");
    ui->CB_destination->addItem("大学城校区(1-16)");
    ui->CB_destination->addItem("国际校区(17-33)");


}


void MainWindow::on_btn1_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();


}


void MainWindow::on_CB_departure_currentTextChanged(const QString &arg1)
{
    if (arg1=="大学城校区(1-16)")
    {
        QRegExp ediName("^(?:[1-9]|1[0-6])$");
        ui->departureEdit->setValidator(new QRegExpValidator(ediName,this));
        ui->departureEdit->setPlaceholderText("请输入1-16的数字");
    }
    else if (arg1=="国际校区(17-33)")
    {
        QRegExp ediName("^(?:1[7-9]|2[0-9]|3[0-3])$");
        ui->departureEdit->setValidator(new QRegExpValidator(ediName,this));
        ui->departureEdit->setPlaceholderText("请输入17-33的数字");
    }


}


void MainWindow::on_CB_destination_currentTextChanged(const QString &arg1)
{
    if (arg1=="大学城校区(1-16)")
    {
        QRegExp ediName("^(?:[1-9]|1[0-6])$");
        ui->destinationEdit->setValidator(new QRegExpValidator(ediName,this));
        ui->destinationEdit->setPlaceholderText("请输入1-16的数字");
    }
    else if (arg1=="国际校区(17-33)")
    {
        QRegExp ediName("^(?:1[7-9]|2[0-9]|3[0-3])$");
        ui->destinationEdit->setValidator(new QRegExpValidator(ediName,this));
        ui->destinationEdit->setPlaceholderText("请输入17-33的数字");
    }

}


void MainWindow::on_btn2_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn3_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn4_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}
void MainWindow::on_btn5_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}
void MainWindow::on_btn6_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn7_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn8_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn9_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn10_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn11_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn12_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn13_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn14_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn15_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn16_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn17_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn18_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn19_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn20_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn21_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn22_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn23_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn24_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn25_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn26_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn27_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn28_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn29_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn30_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn31_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn32_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn33_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍"));    // 设置介绍文字

    infoWindow->exec();
}

